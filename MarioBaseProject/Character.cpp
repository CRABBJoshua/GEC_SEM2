#include <SDL_image.h>
#include <iostream>
#include "Character.h"
#include "Constants.h"
#include "GameScreenLevel1.h"
using namespace std;

//The constructor sets up values I made in the header.
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
	
	//Checking the texture and if the loadfile function return true if not then it will error catch it.
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load background texture!" << std::endl; 
	}
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
Character::~Character()
{
	m_renderer = nullptr;
}
//The Render function, creates the charater in world space.
void Character::Render()
{
	//These two variables help to set up the Camera.
	source = { 0, 0, m_texture->GetWidth(), m_texture->GetHeight() };
	draw = { (int)(m_position.x - m_currentScreen->GetCamPos().x), (int)(m_position.y - m_currentScreen->GetCamPos().y), m_texture->GetWidth(), m_texture->GetHeight() };

	//This code allows the sprites to flip.
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
//The update function will fire every second.
void Character::Update(float deltaTime, SDL_Event e)
{
	//DO NOT UNDERSTAND
	int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + (m_texture->GetHeight() - 10)) / TILE_HEIGHT;
	int head_position = (int)(m_position.y / TILE_HEIGHT);
	int right_position = (int)(m_position.x + (m_texture->GetWidth() - 10)) / TILE_WIDTH;

	//This allows the characters to jump.
	if (m_jumping)
	{
		m_position.y -= m_jump_force * deltaTime;

		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		if (m_jump_force <= 0.0f)
			m_jumping = false;
	}

	//DO NOT UNDERSTAND
	if (m_current_level_map->GetTileAt(foot_position, centralX_position) == 0)
	{
		AddGravity(deltaTime);
	}
	if (m_current_level_map->GetTileAt(head_position, centralX_position) == 1)
	{
		CancelJumping();
	}
	if (m_current_level_map->GetTileAt(right_position, centralX_position) == 1)
	{
		m_position.x + m_texture->GetWidth();
	}
	else
	{
		m_can_jump = true;
	}

	//This checks if m_moving_left or m_moving_right are true and if they are it will allow the characters to move left or right.
	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
}
//This function sets a characters position.
void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}
//This function gets a characters position.
Vector2D Character::GetPosition()
{
	return m_position;
}
//This function move the character left.
void Character::MoveLeft(float deltaTime)
{
	m_position.x -= deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_LEFT;
}
//This function move the character Right.
void Character::MoveRight(float deltaTime)
{
	m_position.x += deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_RIGHT;
}
//This function adds gravity to the characters.
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
//This function set values to be used in the update function.
void Character::Jump()
{
	if (m_can_jump)
	{
		m_jump_force = INITAL_JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}
}
//This function gets a characters CollisionRadius.
float Character::GetCollisionRadius()
{
	return m_collision_radius;
}
//This function gets a characters CollisionBox.
Rect2D Character::GetCollisionBox()
{
	return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
}
//This function Sets the current screen.
void Character::SetCurrentScreen(GameScreenLevel1* current)
{
	m_currentScreen = current;
}