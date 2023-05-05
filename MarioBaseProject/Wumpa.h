#pragma once
#ifndef _WUMPA_H
#define _WUMPA_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
class Wumpa
{
private:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_level_map;

	float m_single_sprite_w;
	float m_single_sprite_h;
	int m_num_hits_left;

public:

	Wumpa(SDL_Renderer* renderer, LevelMap* map);
	~Wumpa();

	void render();
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_single_sprite_w, m_texture->GetHeight()); }
	bool IsAvailable() { return m_num_hits_left > 0; }
};
#endif

