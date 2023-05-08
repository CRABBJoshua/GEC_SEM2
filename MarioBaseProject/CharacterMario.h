#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"

//The CharacterMario header file is being used to hold all the info and values of the CharacterMario class and uses the character class as a base.
//This means that CharacterMario can access certain variables from character. 

class CharacterMario : public Character
{
public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~CharacterMario();

	//The override keyword is used so that we can access the other Update function the character class.
	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_CHARACTERMARIO_H
