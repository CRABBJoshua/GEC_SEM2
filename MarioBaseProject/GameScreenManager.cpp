#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "GameScreenLevel2.h"
#include "TitleScreen.h"

using namespace std;

//The constructor sets up values I made in the header.
GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startscreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreens(startscreen);

	//cout << "I got called" << endl;
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete(m_current_screen);
	m_current_screen = nullptr;
}
//The Render function, will render the current GameScreen.
void GameScreenManager::Render()
{
	m_current_screen->Render();
}
//The update function will fire every second. (Will call the current GameScreens update function.
void GameScreenManager::Update(float deltaTime, SDL_Event e) 
{
	m_current_screen->Update(deltaTime, e);
}
//This function will change the screen using the Enum SCREENS. (Changing Levels) 
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