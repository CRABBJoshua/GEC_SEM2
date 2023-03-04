#pragma once
#ifndef _GameScreenLevel1_H
#define _GameScreenLevel1_H
#include "GameScreen.h"
#include <SDL.h>
#include <string>
#include "Commons.h"
#endif

class GameScreenLevel1 : GameScreen
{
	class Texture2D
	{
		
	};

private:

	Texture2D* m_background_texture;

	bool SetUpLevel()
	{
		m_background_texture = new Texture2D(m_renderer);
		if (!m_background_texture->LoadFromFile("Images/test.bmp"))
		{
			cout << "Failed to load background texture!" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};

