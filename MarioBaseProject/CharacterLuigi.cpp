#include <string>
#include <SDL.h>
#include <iostream>
#include "CharacterLuigi.h"
#include "Character.h"
#include "Commons.h"
#include "Constants.h"
#include "Texture2D.h"

//The constructor sets up values I made in the header.
CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current) : Character(renderer, imagePath, start_position, map, current)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);

	//Checking the texture and if the loadfile function return true if not then it will error catch it.
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load background texture!" << std::endl;
	}
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
CharacterLuigi::~CharacterLuigi()
{
	m_renderer = nullptr;
}
//The update function will fire every second.
void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
	//Allows Luigi to move.
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		case SDLK_UP:
			Jump();
			break;
		}
	}

	Character::Update(deltaTime, e);
}