#pragma once
#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include <SDL.h>
#include <string>
#include "Commons.h"
#include "GameScreenManager.h"

//The GameScreen header file is being used to hold all the info and values of the GameScreen class. 

class GameScreen
{
protected:

	SDL_Renderer* m_renderer;
	GameScreenManager* m_screenManager;

public:

	GameScreen(SDL_Renderer* renderer, GameScreenManager* screenManager);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

};
#endif //_GAMESCREEN_H
