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
#include "CharacterKoopa.h"
#include <vector>


class GameScreenLevel2 : public GameScreen
{
private:

	Texture2D* m_background_texture;
	CharacterMario* my_character_P1;
	CharacterLuigi* my_character_P2;
	LevelMap* m_level_map;
	vector<CharacterKoopa*> m_enemies;
	CharacterKoopa* Koopa;

	SDL_Rect Camera{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	float m_background_yPos;

	bool SetUpLevel();
	void SetLevelMap();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);

public:

	Vector2D GetCamPos();

	GameScreenLevel2(SDL_Renderer* renderer, GameScreenManager* screenManager);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

#endif //_GAMESCREENLEVEL2_H