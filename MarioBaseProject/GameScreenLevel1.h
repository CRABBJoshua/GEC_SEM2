#pragma once
#ifndef _GameScreenLevel1_H
#define _GameScreenLevel1_H
#include "GameScreen.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "Character.h"
#endif

class Character;

class GameScreenLevel1 : public GameScreen
{
	

private:

	Texture2D* m_background_texture;
	Character* my_character;

	bool SetUpLevel();

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

