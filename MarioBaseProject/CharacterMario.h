#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"

class CharacterMario : public Character
{
public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current);
	~CharacterMario();

	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_CHARACTERMARIO_H
