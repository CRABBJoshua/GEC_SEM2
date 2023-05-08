#include "CharacterKoopa.h"

//The constructor sets up values I made in the header.
CharacterKoopa::CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed, GameScreenLevel1* current) : Character(renderer, imagePath, start_position, map, current)
{
	m_facing_direction = start_facing;
	m_movement_speed = movement_speed;
	m_position = start_position;
	m_injured = false;
	m_alive = true;

	//DO NOT UNDERSTAND
	m_single_sprite_w = m_texture->GetWidth() / 2;
	m_single_sprite_h = m_texture->GetHeight();
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
CharacterKoopa::~CharacterKoopa()
{

}
//This function sets the values of variables which will alow the enemy to be damaged.
void CharacterKoopa::TakeDamage()
{
	m_injured = true;
	m_injured_time = INJURED_TIME;
}
//This function set values to be used in the update function.
void CharacterKoopa::Jump()
{
	if (!m_jumping)
	{
		m_jump_force = INITAL_JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}
}
//This function will make the enemy changing the way it is facing make it Jump, this to create a recover function allowing the enemy to get away.
void CharacterKoopa::FlipRightWayUp()
{
	m_facing_direction = FACING_RIGHT; 
	m_injured = false;
	Jump();
}
//The Render function, creates the charater in world space.
void CharacterKoopa::Render()
{
	//DO NOT UNDERSTAND V.

	//Variable to hold the left position of the sprite we want to draw
	int left = 0.0f;

	//If injured move the left position to be the left position of the second image of the sprite sheet
	if (m_injured)
		left = m_single_sprite_w;

	//Get the portion of the sprite sheet you want to draw {xPos, yPos, width of sprite, height of sprite}
	SDL_Rect portion_of_sprite = { left,0,m_single_sprite_w, m_single_sprite_h };

	//Determine where you want it drawn
	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	//Then draw it facing the correct direction
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}
}
//The update function will fire every second.
void CharacterKoopa::Update(float deltaTime, SDL_Event e)
{
	//Use the code within the base class
	Character::Update(deltaTime, e);

	//DO NOT UNDERSTAND
	if (m_position.x + m_single_sprite_w > SCREEN_WIDTH && m_facing_direction == FACING_RIGHT && m_position.y < 300.0f)
	{
		m_facing_direction = FACING_LEFT;
	}
	else if (m_position.x < 0 && m_facing_direction == FACING_LEFT && m_position.y < 300.0f)
	{
		m_facing_direction = FACING_RIGHT;
	}

	if (!m_injured)
	{
		//Enemy is not injured so move
		if (m_facing_direction == FACING_LEFT)
		{
			m_moving_left = true;
			m_moving_right = false;
		}
		else if (m_facing_direction == FACING_RIGHT)
		{
			m_moving_right = true;
			m_moving_left = false;
		}
	}
	else
	{
		//We should not be moving when injured
		m_moving_right = false;
		m_moving_left = false;

		//Count down the injured time
		m_injured_time -= deltaTime;

		if (m_injured_time <= 0.0)
			FlipRightWayUp();
	}
}
