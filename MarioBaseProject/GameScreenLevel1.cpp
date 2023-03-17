#include "GameScreenLevel1.h"
#include "SDL_image.h"
#include <iostream>
#include "Collisions.h"
using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();

}
GameScreenLevel1::~GameScreenLevel1()
{
	delete(m_background_texture);
	m_background_texture = nullptr;
	delete(my_character_P1);
	my_character_P1 = nullptr;
	delete(my_character_P2);
	my_character_P2 = nullptr;
}
void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character_P1->Render();
	my_character_P2->Render();
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	my_character_P1->Update(deltaTime, e);
	my_character_P2->Update(deltaTime, e);

	if (Collisions::Instance()->Circle(my_character_P1, my_character_P2))
	{
		cout << "Circle hit!" << endl;
	}
	if (Collisions::Instance()->Box(my_character_P1->GetCollisionBox(), my_character_P2->GetCollisionBox()))
	{
		cout << "Box hit!" << endl;
	}
}
bool GameScreenLevel1::SetUpLevel()
{
	my_character_P1 = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330));
	my_character_P2 = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(400, 330));
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