#pragma once
#include "Entity.h"
class player :  public Entity
{
public:
	player() = default;
	player(const sf::Vector2i& starting_position);
	void float_up(const sf::Time& dt);
private:

};

