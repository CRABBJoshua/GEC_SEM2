#pragma once
#ifndef _TITLESCREEN_H
#define _TITLESCREEN_H


#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "Commons.h"
#include "GameScreen.h"
#include "Texture2D.h"
#include "TextRender.h"

class GameScreenManager;

class TitleScreen : public GameScreen
{
private:

	Texture2D* m_background_texture;
	Texture2D* m_logo;
	TextRender* m_text;
	TextRender* m_text_Exit;
	string message;
	SDL_Color ColourStart = { 255, 255, 255, 255 };
	SDL_Color ColourExit = { 255, 255, 255, 255 };
	int Counter;

	bool SetUpLevel();

public:

	TitleScreen(SDL_Renderer* renderer, GameScreenManager* screenManager);
	~TitleScreen();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_TITLESCREEN_H
