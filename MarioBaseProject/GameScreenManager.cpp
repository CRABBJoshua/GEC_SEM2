#include "GameScreenManager.h"

using namespace std;



GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startscreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreens(startscreen);

	//cout << "I got called" << endl;
}
GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete(m_current_screen);
	m_current_screen = nullptr;
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}
void GameScreenManager::Update(float deltaTime, SDL_Event e) 
{
	m_current_screen->Update(deltaTime, e);
}
void GameScreenManager::ChangeScreens(SCREENS new_screen)
{
	GameScreen* tempScreen;

	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete(m_current_screen);
	}

	switch (new_screen)
	{
	case TITLE_SCREEN:
		tempScreen = new TitleScreen(m_renderer, this);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
		break;
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenLevel1(m_renderer, this);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
		break;
	case SCREEN_LEVEL2:
		tempScreen = new GameScreenLevel2(m_renderer, this);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
		break;
	default:;
	}
}