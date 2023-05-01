#include <SDL_image.h>
#include <iostream>
#include "GameScreen.h"

using namespace std;

GameScreen::GameScreen(SDL_Renderer* renderer, GameScreenManager* screenManager)
{
	m_renderer = renderer;
	m_screenManager = screenManager;
}
GameScreen::~GameScreen()
{
	m_renderer = nullptr;
	m_screenManager = nullptr;
}
void GameScreen::Render(){}
void GameScreen::Update(float deltaTime, SDL_Event e){}