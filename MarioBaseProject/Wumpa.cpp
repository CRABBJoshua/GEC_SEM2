#include "Wumpa.h"
#include "GameScreenLevel1.h"

using namespace std;

Wumpa::Wumpa(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map, GameScreenLevel1* current) : Character(renderer, imagePath, start_position, map, current)
{
	m_texture = new Texture2D(renderer);
	if (!m_texture->LoadFromFile(imagePath.c_str()))
	{
		cout << "Failded to load texture." << endl;
		return;
	}
	m_level_map = map;
	m_single_sprite_w = m_texture->GetWidth() / 14;
	m_single_sprite_h = m_texture->GetHeight();
	m_frames_count = 0;
	m_position = Vector2D((SCREEN_WIDTH * 0.5f) - m_single_sprite_w * 0.5f, 260);
	animDelay = standardAnimDelay;
}
Wumpa::~Wumpa()
{
	m_renderer = nullptr;
	delete(m_texture);
	m_texture = NULL;
	m_level_map = nullptr;
}
void Wumpa::render()
{
	int left = m_single_sprite_w * (m_frames_count - 1);

	SDL_Rect portion_of_sprite = { left, 0, m_single_sprite_w, m_single_sprite_h };

	SDL_Rect dest_rect = { static_cast<int>(m_position.x - m_currentScreen->GetCamPos().x), static_cast<int>(m_position.y), m_single_sprite_w, m_single_sprite_h };

	m_texture->Render(portion_of_sprite, dest_rect, SDL_FLIP_NONE);
}
	
void Wumpa::Update(float deltaTime, SDL_Event e)
{
	animDelay -= deltaTime;
	if (animDelay < 0)
	{
		m_frames_count++;
		if (m_frames_count > 13)
			m_frames_count = 0;
		animDelay = standardAnimDelay;
	}
	
}