#pragma once
#ifndef _CHARACTERLUIGI_H
#define _CHARACTERLUIGI_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"

class CharacterLuigi : public Character
{
public:

	CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~CharacterLuigi();

	void Update(float deltaTime, SDL_Event e) override;
};

#endif //_CHARACTERLUIGI_H