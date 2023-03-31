#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H

#include "GameScreen.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"

class Character;

class GameScreenLevel2 : public GameScreen
{


private:

	Texture2D* m_background_texture;
	CharacterMario* my_character_P1;
	CharacterLuigi* my_character_P2;
	LevelMap* m_level_map;

	bool SetUpLevel();

public:

	GameScreenLevel2(SDL_Renderer* renderer);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

#endif //_GAMESCREENLEVEL2_H