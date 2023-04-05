#pragma once
#ifndef _CHARACTERKOOPA_H
#define _CHARACTERKOOPA_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Character.h"

class CharacterKoopa : public Character
{
private:
	
	float m_single_sprite_w;
	float m_single_sprite_h;
	float m_movement_speed;
	bool m_injured;
	float m_injured_time;

	void FlipRightWayUp();
	virtual void Update(float deltaTime, SDL_Event e);
	virtual void Render();

public:

	CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
	~CharacterKoopa();

	void TakeDamage();
	void Jump();
};

#endif //_CHARACTERKOOPA_H