#pragma once
#ifndef _GameScreen_H
#define _GameScreen_H
#include <SDL.h>
#include <string>
#include "Commons.h"
#endif

class GameScreen
{
protected:

	SDL_Renderer* m_renderer;

public:

	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

};

