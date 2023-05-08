#pragma once
#ifndef _COLLISION_H
#define _COLLISION_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "Commons.h"
#include "Character.h"

//The character header file is being used to hold all the info and values of the character class. 
class Collisions
{

private:

	Collisions();
	static Collisions* m_instance;

public:

	~Collisions();

	static Collisions* Instance();

	bool Circle(Character* character1, Character* character2);
	bool Box(Rect2D rect1, Rect2D rect2);

};
#endif //_COLLISION_H
