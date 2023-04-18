#include <string>
#include <SDL.h>
#include <iostream>
#include "CharacterLuigi.h"
#include "Character.h"
#include "Commons.h"
#include "Constants.h"
#include "Texture2D.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current) : Character(renderer, imagePath, start_position, map, current)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load background texture!" << std::endl;
	}
}
CharacterLuigi::~CharacterLuigi()
{
	m_renderer = nullptr;
}
void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
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