#include "Character.h"
#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position) 
{
	m_renderer = renderer;
	m_position = start_position;
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
	m_texture->Render(m_position, SDL_FLIP_NONE);
}
void Character::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_position.x -= 1;
		}
		case SDLK_d:
			m_position.x += 1;
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
