#include "Collisions.h"
#include "Character.h"
#include <string>
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Constants.h"
#include "Texture2D.h"

Collisions* Collisions::m_instance = nullptr;

Collisions::Collisions() 
{
	
}
Collisions::~Collisions()
{

}
Collisions::Instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}

	return m_instance;
	//CONTINUE FROM HERE!!!!!!!!
}

