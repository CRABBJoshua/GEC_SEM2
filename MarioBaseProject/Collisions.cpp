#include <string>
#include <SDL.h>
#include <iostream>
#include "Collisions.h"
#include "Character.h"
#include "Commons.h"
#include "Constants.h"
#include "Texture2D.h"

//Singleton is a creational design pattern, which ensures that only one object of its kind exists and provides a single point of access to it for any other code
Collisions* Collisions::m_instance = nullptr;

//The constructor sets up values I made in the header.
Collisions::Collisions() 
{
	
}
//The deconstructor sets values to Null as they are no longer in use. (Deconstructor happens when the character leaves a level).
Collisions::~Collisions()
{

}
//Singleton is a creational design pattern, which ensures that only one object of its kind exists and provides a single point of access to it for any other code
Collisions* Collisions::Instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}

	return m_instance;
}
//This function is used to create a Circle collision
bool Collisions::Circle(Character* character1, Character* character2)
{
	Vector2D vec = Vector2D((character1->GetPosition().x - character2->GetPosition().x), (character1->GetPosition().y - character2->GetPosition().y));

	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

	double combined_distance = (character1->GetCollisionRadius() + character2->GetCollisionRadius());

	return distance < combined_distance;
}
//This function is used to create a Box collision
bool Collisions::Box(Rect2D rect1, Rect2D rect2) 
{
	if (rect1.x + (rect1.width / 2) > rect2.x &&
		rect1.x + (rect1.width / 2) < rect2.x + rect2.width &&
		rect1.y + (rect1.height / 2) > rect2.y &&
		rect1.y + (rect1.height / 2) < rect2.y + rect2.height)
	{
		return true;
	}
	return false;
}

