#pragma once
#ifndef _GameScreenLevel2_H
#define _GameScreenLevel2_H
#include "GameScreen.h"
#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#endif

class GameScreenLevel2 : public GameScreen
{


private:

	Texture2D* m_background_texture;

	bool SetUpLevel()
	{
		m_background_texture = new Texture2D(m_renderer);
		if (!m_background_texture->LoadFromFile("Images/Green Hill.png"))
		{
			std::cout << "Failed to load background texture!" << std::endl;
			return false;
		}
		else
		{
			return true;
		}
	}

public:

	GameScreenLevel2(SDL_Renderer* renderer);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};