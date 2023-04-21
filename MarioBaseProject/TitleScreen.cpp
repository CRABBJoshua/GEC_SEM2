#include "TitleScreen.h"
#include <SDL_image.h>
#include <iostream>
#include "Collisions.h"
#include "LevelMap.h"
using namespace std;

TitleScreen::TitleScreen(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}
TitleScreen::~TitleScreen()
{
	delete(m_background_texture);
	m_background_texture = nullptr;;
}
void TitleScreen::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}
void TitleScreen::Update(float deltaTime, SDL_Event e)
{
	
}
bool TitleScreen::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}