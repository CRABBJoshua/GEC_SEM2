#pragma once
#ifndef _WUMPA_H
#define _WUMPA_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include "Character.h"

class Wumpa : public Character
{
private:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_level_map;

	float animDelay;
	float standardAnimDelay = 0.2f;

	float m_single_sprite_w;
	float m_single_sprite_h;
	int m_frames_count;

public:

	Wumpa(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~Wumpa();

	void Render();
	void Update(float deltaTime, SDL_Event e) override;
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_single_sprite_w, m_texture->GetHeight()); }
	bool IsAvailable() { return m_frames_count > 0; }
};
#endif

