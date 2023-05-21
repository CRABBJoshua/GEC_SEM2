#include "TextRender.h"
#include <iostream> 

//The constructor sets up values I made in the header.
TextRender::TextRender(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
TextRender::~TextRender()
{
	delete(m_renderer);
	m_renderer = nullptr;
}
//This Render function will render the Text depending on the x and y position
void TextRender::Render(int x, int y)
{
	m_textRect.x = x;
	m_textRect.y = y;

	SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_textRect);
}
//This function loads the font and makes sure to catch any errors
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