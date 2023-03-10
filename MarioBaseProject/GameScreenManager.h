#pragma once
#ifndef _GameScreenManager_H
#define _GameScreenManager_H
#include <SDL.h>
#include <string>
#include "Commons.h"
#endif

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

