#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"

class Texture2D;
class GameScreenLevel1;

//The character header file is being used to hold all the info and values of the character class. 

class Character
{
protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	FACING m_facing_direction;
	SDL_Rect source;
	SDL_Rect destination;
	SDL_Rect draw;
	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	float m_collision_radius;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

private:
	LevelMap* m_current_level_map;

	GameScreenLevel1* m_currentScreen = nullptr;

public:

	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();

	void AddGravity(float deltaTime);
	void Jump();
	bool IsJumping() { return m_jumping; }
	void CancelJumping() { m_jumping = false;  }
	float GetCollisionRadius();
	Rect2D GetCollisionBox();

	void SetCurrentScreen(GameScreenLevel1* current);

};

#endif //_CHARACTER_H