#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include "Commons.h"
#include "Texture2D.h"
#include "Character.h"
#include "CharacterKoopa.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"

class Character;
class PowBlock;

class GameScreenLevel1 : public GameScreen
{
	

private:

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;

	Texture2D* m_background_texture;
	Character* my_character_P1;
	Character* my_character_P2;
	CharacterKoopa* Koopa;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	vector<CharacterKoopa*> m_enemies;

	void SetLevelMap();
	void DoScreenShake();
	bool SetUpLevel();

	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	//START HERE!!!!

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void UpdatePOWBlock();
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_GAMESCREENLEVEL1_H
