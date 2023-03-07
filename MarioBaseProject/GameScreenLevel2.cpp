#include "GameScreenLevel2.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

GameScreenLevel2::GameScreenLevel2(SDL_Renderer* renderer) : GameScreen(renderer)
{
	GameScreenLevel2::SetUpLevel();
}
GameScreenLevel2::~GameScreenLevel2()
{
	delete(m_background_texture);
	m_background_texture = nullptr;
}

void GameScreenLevel2::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}
void GameScreenLevel2::Update(float deltaTime, SDL_Event e)
{

}
bool GameScreenLevel2::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/Green Hill.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}