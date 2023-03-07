#include "GameScreenLevel1.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	GameScreenLevel1::SetUpLevel();
}
GameScreenLevel1::~GameScreenLevel1()
{
	delete(m_background_texture);
	m_background_texture = nullptr;
}

void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}