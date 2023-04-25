#pragma once
#ifndef _TITLESCREEN_H
#define _TITLESCREEN_H

#include "GameScreen.h"
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <string>
#include "Commons.h"
#include "Texture2D.h"
#include "TextRender.h"

class TitleScreen : public GameScreen
{
private:

	Texture2D* m_background_texture;
	Texture2D* m_logo;
	TextRender* m_text;
	string message;

	bool SetUpLevel();

public:

	TitleScreen(SDL_Renderer* renderer);
	~TitleScreen();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

};
#endif //_TITLESCREEN_H
