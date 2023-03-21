#pragma once
#ifndef _CharacterMario_H
#define _CharacterMario_H
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"
#endif

class CharacterMario : public Character
{
public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterMario();

	virtual void Update(float deltaTime, SDL_Event e);

};

