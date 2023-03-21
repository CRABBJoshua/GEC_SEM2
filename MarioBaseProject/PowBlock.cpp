#include "PowBlock.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
using namespace std;

PowBlock::PowBlock(SDL_Renderer* renderer, LevelMap* map)
{
	std::string imagePath = "Imgae/PowBlock.png";
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
	m_position = Vector2D((SCREEN_WIDTH * 0.5f) - m_single_sprite_w * 0.5f, 260);

}
PowBlock::~PowBlock()
{
	m_renderer = nullptr;
	delete(m_texture);
	m_texture = NULL;
	m_level_map = nullptr;
	//CONTINUE FROM HERE
}
void PowBlock::render()
{

}
void PowBlock::TakeHit()
{

}
