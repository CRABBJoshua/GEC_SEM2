#pragma once

//Commons is used to store info useful for all classes and can be access by all of them.
struct Vector2D
{
	//DO NOT UNDERSTAND
	float x;
	float y;

	//DO NOT UNDERSTAND
	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	//DO NOT UNDERSTAND
	Vector2D(float initial_x, float initial_y)
	{
		x = initial_x;
		y = initial_y;
	}
};

//DO NOT UNDERSTAND
enum SCREENS
{
	TITLE_SCREEN,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};

//DO NOT UNDERSTAND
enum FACING
{
	FACING_LEFT,
	FACING_RIGHT,
};

//DO NOT UNDERSTAND
struct Rect2D
{
	float x;
	float y;
	float width;
	float height;

	Rect2D(float x_pos, float y_pos, float width, float height) 
	{
		x = x_pos;
		y = y_pos;
		this->width = width;
		this->height = height;
	};
	
};


