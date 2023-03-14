#pragma once
#ifndef _CharacterMario_H
#define _CharacterMario_H
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"
#endif

class CharacterMario : Character
{
protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

private:

	FACING m_facing_direction;

public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position);
	~CharacterMario();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();

	void AddGravity(float deltaTime);
	void Jump();
};

