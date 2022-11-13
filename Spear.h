#pragma once
#include "Entity.h"
#include "includes.hpp"

class Spear :  public Entity
{
public:
	Spear(const sf::Vector2f& player_pos);
	void set_intial_mouse_pos(const sf::RenderWindow& window);
	//uses pythag's to get distance between current mouse pos
	//and old mouse pos
	void set_velocity(const sf::Vector2i& current_mouse_pos);	
	void set_texture(const sf::Texture& texture);
	void move(const sf::Time& time);
	const sf::Vector2i& get_velocity()const;
private:
	sf::Vector2i m_inital_mouse_pos;
	sf::Vector2i m_velocity;
};

