#include <SDL_image.h>
#include <iostream>
#include "Character.h"
#include "Constants.h"
#include "GameScreenLevel1.h"
using namespace std;

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current) 
{
	SetCurrentScreen(current);
	m_moving_left = false;
	m_moving_right = false;
	m_current_level_map = map;
	m_renderer = renderer;
	m_position = start_position;
	m_facing_direction = FACING_RIGHT;
	m_collision_radius = 15.0f;
	m_texture = new Texture2D(m_renderer);
	
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load background texture!" << std::endl; 
	}
}
Character::~Character()
{
	m_renderer = nullptr;
}
void Character::Render()
{
	source = { 0, 0, m_texture->GetWidth(), m_texture->GetHeight() };
	draw = { (int)(m_position.x - m_currentScreen->GetCamPos().x), (int)(m_position.y - m_currentScreen->GetCamPos().y), m_texture->GetWidth(), m_texture->GetHeight() };

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(source, draw, SDL_FLIP_HORIZONTAL);
		//m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(source, draw, SDL_FLIP_HORIZONTAL);
		//m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}
void Character::Update(float deltaTime, SDL_Event e)
{
	int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + (m_texture->GetHeight() - 10)) / TILE_HEIGHT;

	if (m_jumping)
	{
		m_position.y -= m_jump_force * deltaTime;

		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		if (m_jump_force <= 0.0f)
			m_jumping = false;
	}

	if (m_current_level_map->GetTileAt(foot_position, centralX_position) == 0)
	{
		AddGravity(deltaTime);
	}
	else
	{
		m_can_jump = true;
	}

	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
}
void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}
Vector2D Character::GetPosition()
{
	return m_position;
}

void Character::MoveLeft(float deltaTime)
{
	m_position.x -= deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_LEFT;
}
void Character::MoveRight(float deltaTime)
{
	m_position.x += deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_RIGHT;
}
void Character::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY * deltaTime;
	}
	else
	{
		m_can_jump = true;
	}
	
}
void Character::Jump()
{
	if (m_can_jump)
	{
		m_jump_force = INITAL_JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}
}
float Character::GetCollisionRadius()
{
	return m_collision_radius;
}
Rect2D Character::GetCollisionBox()
{
	return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
}

void Character::SetCurrentScreen(GameScreenLevel1* current)
{
	m_currentScreen = current;
}