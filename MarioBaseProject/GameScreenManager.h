#pragma once
#ifndef _GAMESCREENMANAGER_H
#define _GAMESCREENMANAGER_H

#include <SDL.h>
#include <string>
#include "Commons.h"

//Forward Declares
class GameScreen;

//The GameScreenManager header file is being used to hold all the info and values of the GameScreenManager class. 
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
