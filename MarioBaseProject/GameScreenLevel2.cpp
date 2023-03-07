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