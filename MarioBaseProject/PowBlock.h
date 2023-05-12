#pragma once
#ifndef _POWBLOCK_H
#define _POWBLOCK_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include "GameScreenLevel1.h"
#include "Character.h"
#pragma once

class LevelMap;

class PowBlock : public Character
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

	PowBlock(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~PowBlock();

	void render();
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_single_sprite_w, m_texture->GetHeight()); }
	void TakeHit();
	bool IsAvailable() { return m_num_hits_left > 0; }

};

#endif //_POWBLOCK_H