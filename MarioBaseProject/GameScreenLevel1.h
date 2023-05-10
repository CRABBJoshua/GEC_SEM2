#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H


#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include "Commons.h"
#include "Texture2D.h"
#include "GameScreen.h"
#include "CharacterKoopa.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"
#include "TextRender.h"

//Forward Declares
class PowBlock;
class Character;
class Wumpa;

//The GameScreenLevel1 header file is being used to hold all the info and values of the GameScreenLevel1 class and uses the GameScreen class as a base.
//This means that GameScreenLevel1 can access certain variables from GameScreen. 
class GameScreenLevel1 : public GameScreen
{

private:

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	int Score;
	int Old_Score;
	string score;

	Texture2D* m_background_texture;
	Character* my_character_P1;
	Character* my_character_P2;
	CharacterKoopa* Koopa;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	TextRender* m_text;
	Wumpa* m_wumpa;
	vector<Wumpa*> m_wumpaFruit;
	SDL_Color Colour = { 255, 255, 255, 255 };
	vector<CharacterKoopa*> m_enemies;

	//ScreenScrolling
	SDL_Rect Camera{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	void SetLevelMap();
	void DoScreenShake();
	bool SetUpLevel();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void UpdateWumpa(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	void CreateWumpa(Vector2D position);

public:

	Vector2D GetCamPos();
	
	//GameScreenLevel1();
	GameScreenLevel1(SDL_Renderer* renderer, GameScreenManager* screenManager);
	~GameScreenLevel1();

	void UpdatePOWBlock();
	void LoadMusic(string path);
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_GAMESCREENLEVEL1_H
