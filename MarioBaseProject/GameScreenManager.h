#pragma once
#ifndef _GAMESCREENMANAGER_H
#define _GAMESCREENMANAGER_H

#include <SDL.h>
#include <string>
#include "Commons.h"
#include "GameScreenLevel2.h"
#include "GameScreenLevel1.h"

class GameScreen;

class GameScreenManager
{

private:

	SDL_Renderer* m_renderer;
	GameScreen* m_current_screen;

	
public:

	GameScreenManager(SDL_Renderer* renderer, SCREENS startscreen);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreens(SCREENS new_screen);
};
#endif //_GAMESCREENMANAGER_H
