#pragma once
#include "Entity.h"
class Fish :public Entity
{
public:
	Fish(const int& speed, const sf::Vector2i& position);
	void move(const sf::Vector2f& player_position, const sf::Time& dt);
	void set_speed(const int& speed);
	const int& get_speed()const;
private:
	int m_speed;

};

