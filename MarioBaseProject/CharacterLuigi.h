#pragma once
#ifndef _CharacterLuigi_H
#define _CharacterLuigi_H
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"
#endif

class CharacterLuigi : public Character
{
public:

	CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterLuigi();

	virtual void Update(float deltaTime, SDL_Event e);
};
