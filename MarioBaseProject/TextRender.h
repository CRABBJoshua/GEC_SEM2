#pragma once
#ifndef _TEXTRENDER_H
#define _TEXTRENDER_H
#include <SDL_ttf.h>
#include <string>

//The TextRender header file is being used to hold all the info and values of the TextRender class. 
class TextRender
{
public:
	TextRender(SDL_Renderer* renderer);
	~TextRender();

	void Render(int x, int y);
	bool LoadFont(const std::string filePath, int FontSize, const std::string Message, SDL_Color Colour);

private:

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	SDL_Rect m_textRect;
	TTF_Font* m_font;
};

#endif //_TEXTRENDER_H