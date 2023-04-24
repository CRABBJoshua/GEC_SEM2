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
	m_background_texture = nullptr;
	delete(m_logo);
	m_logo = nullptr;
}
void TitleScreen::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	//m_logo->Render(Vector2D(), SDL_FLIP_NONE, 90);
}
void TitleScreen::Update(float deltaTime, SDL_Event e)
{
	
}
bool TitleScreen::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/BlackScreen.jpg"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}

	/*m_logo = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/Crash_bandicoot_logo.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}*/
}