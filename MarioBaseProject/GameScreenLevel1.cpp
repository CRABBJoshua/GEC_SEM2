#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "GameScreenLevel1.h"
#include "GameScreenManager.h"
#include "Collisions.h"
#include "PowBlock.h"
#include "Wumpa.h"
using namespace std;

//The constructor sets up values I made in the header.
GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer, GameScreenManager* screenManager) : GameScreen(renderer, screenManager)
{
	SetUpLevel();
	m_level_map = nullptr;
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
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

	//DO NOT UNDERSTAND
	for (int i = 0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
	}
	m_enemies.clear();

	for (int i = 0; i < m_wumpaFruit.size(); i++)
	{
		delete m_wumpaFruit[i];
	}
	m_wumpaFruit.clear();
}
//The Render function, creates the charater in world space.
//CONTINUE HERE
void GameScreenLevel1::Render()
{	
	m_background_texture->Render(Vector2D(0, m_background_yPos), Camera, SDL_FLIP_NONE, 0.0f);

	//Draw the enemies
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Render();
	}

	for (int i = 0; i < m_wumpaFruit.size(); i++)
	{
		m_wumpaFruit[i]->Render();
	}

	//m_pow_block->render();
	m_pow_block->render();
	my_character_P1->Render();
	my_character_P2->Render();
	m_text->Render(0,0);
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	my_character_P1->Update(deltaTime, e);
	my_character_P2->Update(deltaTime, e);

	Camera.x = (my_character_P1->GetPosition().x + my_character_P1->GetCollisionBox().width) - (SCREEN_WIDTH/2);

	if (Camera.x < 0)
	{
		Camera.x = 0;
	}
	else if (Camera.x > LEVEL_WIDTH - Camera.w)
	{
		Camera.x = LEVEL_WIDTH - Camera.w;
	}

	UpdatePOWBlock();
	UpdateEnemies(deltaTime, e);
	UpdateWumpa(deltaTime, e);

	if (m_text != nullptr && Score != Old_Score)
	{
		Old_Score = Score;
		m_text->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "Wumpa Fruit: " + std::to_string(Score), Colour);
	}

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
	CreateKoopa(Vector2D(150, 100), FACING_LEFT, KOOPA_SPEED);
	CreateKoopa(Vector2D(325, 100), FACING_LEFT, KOOPA_SPEED);
	CreateWumpa(Vector2D(260, 320));
	CreateWumpa(Vector2D(300, 320));
	m_pow_block = new PowBlock(m_renderer, "Images/PowBlock.png", Vector2D(500, 1000), m_level_map, this);
	m_screenshake = false;
	m_background_yPos = 0, 0;
	my_character_P1 = new CharacterMario(m_renderer, "Images/Crash.png", Vector2D(64, 300), m_level_map, this);
	my_character_P2 = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(400, 1000), m_level_map, this);
	m_background_texture = new Texture2D(m_renderer);

	m_text = new TextRender(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/1-1 Edit.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	if (!m_text->LoadFont("Fonts/CrashBandicootWumpa.ttf", 40, "Wumpa Fruit: " + std::to_string(Score), Colour))
	{
		cout << "Failed to load Font!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
void GameScreenLevel1::SetLevelMap()
{
	/*int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
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
					  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };*/

	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};


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
				//DoScreenShake();
				//m_pow_block->TakeHit();
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
				/*DoScreenShake();
				m_pow_block->TakeHit();*/
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
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->TakeDamage();
	}
	/*
	Koopa->TakeDamage();*/
}
void GameScreenLevel1::UpdateEnemies(float deltaTime, SDL_Event e)
{
	if (!m_enemies.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_enemies.size(); i++)
		{
			//Check if the enemy is on the bottom row of tiles
			if (m_enemies[i]->GetPosition().y > 300.0f)
			{
				//Is the enemy off screen to the left / right?
				if (m_enemies[i]->GetPosition().x < (float)(-m_enemies[i]->GetCollisionBox().width * 0.5f) || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - (float)(m_enemies[i]->GetCollisionBox().width * 0.55f))
				{
					//m_enemies[i]->SetAlive(false);
				}
			}
			//Now do the Update

			m_enemies[i]->Update(deltaTime, e);

			//Check to see if the enemy collides with the player
			if ((m_enemies[i]->GetPosition().y > 300.0f || m_enemies[i]->GetPosition().y <= 64.0f) && (m_enemies[i]->GetPosition().x < 64.0f || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - 96.0f))
			{
				//Ingore Collisions if behind pipe
			}
			else
			{
				if (Collisions::Instance()->Circle(m_enemies[i], my_character_P1))
				{ 
					if (my_character_P1->IsAttacking())
					{
							m_enemies[i]->SetAlive(false);
					}
					
					else
					{
						//Kill mario
					}
				}
			}

			//If the enemy is no longer alive then schedule it for deletion
			if (!m_enemies[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
		}

		//Remove dead enemies -1 each update

		if (enemyIndexToDelete != -1)
		{
			m_enemies.erase(m_enemies.begin() + enemyIndexToDelete);
		}
	}
}
void GameScreenLevel1::CreateKoopa(Vector2D position, FACING direction, float speed)
{
	Koopa = new CharacterKoopa(m_renderer, "Images/Koopa.png", m_level_map, position, direction, speed, this);
	m_enemies.push_back(Koopa);
}
void GameScreenLevel1::CreateWumpa(Vector2D position)
{
	Wumpa* m_wumpa = new Wumpa(m_renderer, "Images/WumpaCropped.png", position, m_level_map, this);
	m_wumpaFruit.push_back(m_wumpa);
}

Vector2D GameScreenLevel1::GetCamPos()
{
	return Vector2D(Camera.x, Camera.y);
}

void GameScreenLevel1::UpdateWumpa(float deltaTime, SDL_Event e)
{
	if (!m_wumpaFruit.empty())
	{
		int wumpaFruitIndexToDelete = -1;
		for (unsigned int i = 0; i < m_wumpaFruit.size(); i++)
		{
			//Check if the enemy is on the bottom row of tiles
			if (m_wumpaFruit[i]->GetPosition().y > 300.0f)
			{
				//Is the enemy off screen to the left / right?
				if (m_wumpaFruit[i]->GetPosition().x < (float)(-m_wumpaFruit[i]->GetCollisionBox().width * 0.5f) || m_wumpaFruit[i]->GetPosition().x > SCREEN_WIDTH - (float)(m_wumpaFruit[i]->GetCollisionBox().width * 0.55f))
				{
					//m_wumpaFruit[i]->SetAlive(false);
				}
			}
			//Now do the Update

			m_wumpaFruit[i]->Update(deltaTime, e);

			if (Collisions::Instance()->Circle(m_wumpaFruit[i], my_character_P1))
			{
				wumpaFruitIndexToDelete = i;
				Score++;
			}
		}

		//Remove dead enemies -1 each update

		if (wumpaFruitIndexToDelete != -1)
		{
			m_wumpaFruit.erase(m_wumpaFruit.begin() + wumpaFruitIndexToDelete);
		}
	}
}