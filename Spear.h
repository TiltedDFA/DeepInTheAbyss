#pragma once
#include "Entity.h"
#include "includes.hpp"

class Spear :  public Entity
{
public:
	Spear();
private:
	sf::Vector2i m_inital_mouse_pos;
	sf::Vector2i m_velocity;
};

