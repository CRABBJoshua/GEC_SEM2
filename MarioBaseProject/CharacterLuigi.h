#pragma once
#ifndef _CHARACTERLUIGI_H
#define _CHARACTERLUIGI_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"

//The CharacterLuigi header file is being used to hold all the info and values of the CharacterLuigi class and uses the character class as a base.
//This means that CharacterLuigi can access certain variables from character. 

class CharacterLuigi : public Character
{
public:

	CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~CharacterLuigi();

	//The override keyword is used so that we can access the other Update function the character class.
	void Update(float deltaTime, SDL_Event e) override;
};

#endif //_CHARACTERLUIGI_H