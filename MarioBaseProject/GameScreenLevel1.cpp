#include <SDL_image.h>
#include <iostream>
#include "GameScreenLevel1.h"
#include "Collisions.h"
#include "PowBlock.h"
using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
	m_level_map = nullptr;
}
GameScreenLevel1::~GameScreenLevel1()
{
	delete(m_background_texture);
	m_background_texture = nullptr;
	delete(my_character_P1);
	my_character_P1 = nullptr;
	delete(my_character_P2);
	my_character_P2 = nullptr;
	delete(m_pow_block);
	m_pow_block = nullptr;
}
void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);
	my_character_P1->Render();
	my_character_P2->Render();
	m_pow_block->render();
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	my_character_P1->Update(deltaTime, e);
	my_character_P2->Update(deltaTime, e);

	UpdatePOWBlock();

	if (m_screenshake)
	{
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);
		m_background_yPos *= 3.0f;

		if (m_shake_time <= 0.0f)
		{
			m_shake_time = false;
			m_background_yPos = 0.0f;
		}
	}

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
	SetLevelMap();
	m_pow_block = new PowBlock(m_renderer, m_level_map);
	m_screenshake = false;
	m_background_yPos = 0, 0;
	my_character_P1 = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	my_character_P2 = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(400, 330), m_level_map);
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
					  { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	//set the new one
	m_level_map = new LevelMap(map);

}
void GameScreenLevel1::UpdatePOWBlock()
{
	if (Collisions::Instance()->Box(my_character_P1->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			if (my_character_P1->IsJumping())
			{
				DoScreenShake();
				m_pow_block->TakeHit();
				my_character_P1->CancelJumping();
			}
		}
	}

	if (Collisions::Instance()->Box(my_character_P2->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			if (my_character_P2->IsJumping())
			{
				DoScreenShake();
				m_pow_block->TakeHit();
				my_character_P2->CancelJumping();
			}
		}
	}
}

void GameScreenLevel1::DoScreenShake()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;
}