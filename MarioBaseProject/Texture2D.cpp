#include "Texture2D.h"

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

Texture2D::~Texture2D()
{
	Free();

	m_renderer = nullptr;
}

bool Texture2D::LoadFromFile(std::string path)
{
	//remove memory used for a previous texture
	Free();

	//load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		//create the texture from the pixels on the surface
		SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0XFF, 0XFF));

		m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);
		if (m_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		else
		{
			m_width = p_surface->w;
			m_height = p_surface->h;
		}
		//remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}

	//return the texture
	return m_texture != nullptr;
}

void Texture2D::Free()
{
	//check if texture exists before removing it
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	SDL_Rect renderlocation = { new_position.x,new_position.y,m_width, m_height };

	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderlocation, angle, nullptr, flip);

}

void Texture2D::Render(SDL_Rect src_rect, SDL_Rect dst_rect, SDL_RendererFlip flip, double angle)
{
	SDL_RenderCopyEx(m_renderer, m_texture, &src_rect, &dst_rect, angle, nullptr, flip);
}

void Texture2D::Render(Vector2D new_position, SDL_Rect clip, SDL_RendererFlip flip, double angle)
{
	SDL_Rect render_location = { new_position.x,new_position.y,m_width, m_height };

	if (&clip != NULL)
	{
		render_location.w = clip.w;
		render_location.y = clip.y;
	}

	SDL_RenderCopyEx(m_renderer, m_texture, &clip, &render_location, angle, nullptr, flip);
}
