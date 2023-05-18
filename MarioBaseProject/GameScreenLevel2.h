#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H


#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "GameScreen.h"
#include "Texture2D.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"


class GameScreenLevel2 : public GameScreen
{
private:

	Texture2D* m_background_texture;
	CharacterMario* my_character_P1;
	CharacterLuigi* my_character_P2;
	LevelMap* m_level_map;

	bool SetUpLevel();
	void SetLevelMap();

public:

	GameScreenLevel2(SDL_Renderer* renderer, GameScreenManager* screenManager);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

#endif //_GAMESCREENLEVEL2_H