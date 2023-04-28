#include "TextRender.h"
#include <iostream> 

TextRender::TextRender(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
TextRender::~TextRender()
{
	delete(m_renderer);
	m_renderer = nullptr;
}
void TextRender::Render(int x, int y)
{
	m_textRect.x = x;
	m_textRect.y = y;

	SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_textRect);
}
bool TextRender::LoadFont(const std::string filePath, int FontSize, const std::string Message, SDL_Color Colour)
{
	m_font = TTF_OpenFont(filePath.c_str(), FontSize);
	if (!m_font)
	{
		std::cout << TTF_GetError();
	}

	SDL_Surface* text_surface = TTF_RenderText_Solid(m_font, Message.c_str(), Colour);
	if (!text_surface)
	{
		std::cout << SDL_GetError();
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
	if (!m_texture)
	{
		std::cout << SDL_GetError();
	}

	TTF_CloseFont(m_font);
	SDL_FreeSurface(text_surface);

	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_textRect.w, &m_textRect.h);

	return m_texture;
}