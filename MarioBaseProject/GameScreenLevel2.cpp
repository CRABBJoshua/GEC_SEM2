#include <SDL_image.h>
#include <iostream>
#include "GameScreenLevel2.h"
#include "Collisions.h"
#include "LevelMap.h"
using namespace std;

GameScreenLevel2::GameScreenLevel2(SDL_Renderer* renderer, GameScreenManager* screenManager) : GameScreen(renderer, screenManager)
{
	SetUpLevel();
}
GameScreenLevel2::~GameScreenLevel2()
{
	delete(m_background_texture);
	m_background_texture = nullptr;
	delete(my_character_P1);
	my_character_P1 = nullptr;
}

void GameScreenLevel2::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character_P1->Render();

}
void GameScreenLevel2::Update(float deltaTime, SDL_Event e)
{
	my_character_P1->Update(deltaTime, e);
	
}
bool GameScreenLevel2::SetUpLevel()
{
	my_character_P1 = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map, (GameScreenLevel1*)this);
	//my_character_P2 = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(64, 330), m_level_map, (GameScreenLevel1*)this);
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