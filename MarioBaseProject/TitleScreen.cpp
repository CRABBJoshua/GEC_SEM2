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
	m_logo->Render(Vector2D(48, 0), SDL_FLIP_NONE);
}
void TitleScreen::Update(float deltaTime, SDL_Event e)
{
	
}
bool TitleScreen::SetUpLevel()
{
	/*m_text = new TextRender = m_renderer;*/

	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/BlackScreen.jpg"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}

	m_logo = new Texture2D(m_renderer);

	if (!m_logo->LoadFromFile("Images/Crash_bandicoot_logo.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}

	return true;

	/*
	m_logo = new Texture2D(m_renderer);

	if (!m_logo->LoadFromFile("Images/Crash_bandicoot_logo.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}*/
}