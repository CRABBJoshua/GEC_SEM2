#include <SDL_image.h>
#include <iostream>
#include "GameScreen.h"

using namespace std;

//The constructor sets up values I made in the header.
GameScreen::GameScreen(SDL_Renderer* renderer, GameScreenManager* screenManager)
{
	m_renderer = renderer;
	m_screenManager = screenManager;
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
GameScreen::~GameScreen()
{
	m_renderer = nullptr;
	m_screenManager = nullptr;
}
//DO NOT UNDERSTAND
void GameScreen::Render(){}
void GameScreen::Update(float deltaTime, SDL_Event e){}