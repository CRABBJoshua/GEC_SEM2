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
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#endif

class Character;

class GameScreenLevel1 : public GameScreen
{
	

private:

	Texture2D* m_background_texture;
	CharacterMario* my_character_P1;
	CharacterLuigi* my_character_P2;

	bool SetUpLevel();

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

