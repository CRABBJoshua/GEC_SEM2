#include "TitleScreen.h"
#include <SDL_image.h>
#include <iostream>
#include "Collisions.h"
#include "LevelMap.h"

#include <iostream>

using namespace std;

TitleScreen::TitleScreen(SDL_Renderer* renderer, GameScreenManager* screenManager) : GameScreen(renderer, screenManager
)
{
	SetUpLevel();
	Counter = 0;
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
	m_text_Level1->Render(180, 200);
	m_text_Level2->Render(180, 250);
	m_text_Exit->Render(180, 300);
	m_text_Arrow->Render(ArrowPositionX, ArrowPositionY);
}
void TitleScreen::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			Counter--;
			ArrowPositionY -= 50;
			if (ArrowPositionY < 200)
			{
				ArrowPositionY = 200;
				Counter = 0;
			}
			cout << Counter << endl;
			break;
		case SDLK_DOWN:
			Counter++;
			ArrowPositionY += 50;
			if (ArrowPositionY > 300)
			{
				ArrowPositionY = 300;
				Counter = 2;
			}
			cout << Counter << endl;
			break;
		case SDLK_RETURN:
			if (Counter == 0) 
			{
				m_screenManager->ChangeScreens(SCREEN_LEVEL1);
				cout << "I pressed Enter" << endl;
			}
			else if (Counter == 1)
			{
				m_screenManager->ChangeScreens(SCREEN_LEVEL2);
				cout << "I pressed Enter" << endl;
			}
			else if (Counter == 2)
			{
				cout << "I pressed Enter" << endl;
				SDL_Quit();
			}
			break;
		}
	}
}
bool TitleScreen::SetUpLevel()
{
	m_text_Level1 = new TextRender(m_renderer);
	m_text_Level2 = new TextRender(m_renderer);
	m_text_Exit = new TextRender(m_renderer);
	m_text_Arrow = new TextRender(m_renderer);

	if (!m_text_Exit->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "Exit", ColourStart))
	{
		cout << "Failed to load Font!" << endl;
		return false;
	}

	if (!m_text_Level1->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "Start Level 1", ColourExit))
	{
		cout << "Failed to load Font!" << endl;
		return false;
	}

	if (!m_text_Level2->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "Start Level 2", ColourExit))
	{
		cout << "Failed to load Font!" << endl;
		return false;
	}

	if (!m_text_Arrow->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "-", ColourStart))
	{
		cout << "Failed to load Font!" << endl;
		return false;
	}

	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/BlackScreen.jpg"))
	{
		cout << "Failed to load background texture!" << endl;
		return false;
	}

	m_logo = new Texture2D(m_renderer);

	if (!m_logo->LoadFromFile("Images/Crash_bandicoot_logo.png"))
	{
		cout << "Failed to load background texture!" << endl;
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