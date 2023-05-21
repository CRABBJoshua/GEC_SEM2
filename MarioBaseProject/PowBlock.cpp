#include "PowBlock.h"

using namespace std;

//The constructor sets up values I made in the header.
PowBlock::PowBlock(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current) : Character(renderer, imagePath, start_position, map, current)
{
	imagePath = "Images/PowBlock.png";
	m_texture = new Texture2D(renderer);
	if (!m_texture->LoadFromFile(imagePath.c_str()))
	{
		cout << "Failded to load texture." << endl;
		return;
	}
	m_level_map = map;
	m_single_sprite_w = m_texture->GetWidth() / 3;
	m_single_sprite_h = m_texture->GetHeight();
	m_num_hits_left = 3;
	m_position = start_position;
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
PowBlock::~PowBlock()
{
	m_renderer = nullptr;
	delete(m_texture);
	m_texture = NULL;
	m_level_map = nullptr;
}
//The Render function, creates the PowBlock and animates it.
void PowBlock::render()
{
	int left = m_single_sprite_w * (m_num_hits_left - 1);

	SDL_Rect portion_of_sprite = { left, 0, m_single_sprite_w, m_single_sprite_h };

	SDL_Rect dest_rect = { static_cast<int>(m_position.x - m_currentScreen->GetCamPos().x), static_cast<int>(m_position.y), m_single_sprite_w, m_single_sprite_h };

	m_texture->Render(portion_of_sprite, dest_rect, SDL_FLIP_NONE);
}
//This function doesn't do anything anymore.
void PowBlock::TakeHit()
{
	//m_num_hits_left--;
	m_level_map->ChangeTileAt(8, 7, 0);
	m_level_map->ChangeTileAt(8, 8, 0);
}
