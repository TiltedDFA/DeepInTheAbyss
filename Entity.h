#pragma once
#include "includes.hpp"
#include "Texture_Manager.hpp"
class Entity
{
public:
	Entity() = default;
	Entity(const sf::Texture& texture,const sf::Vector2i& position = { 500,500 });

	virtual void init(const sf::Texture& texture, const sf::Vector2i& position = { 500,500 });
	virtual void move(const Direction& var,const sf::Time& dt);
	virtual void draw(sf::RenderWindow& window)const;

	virtual void set_position(const sf::Vector2f& position);
	virtual const sf::Vector2f& get_position()const;
	virtual const sf::FloatRect get_global_bounds()const;

protected:
	sf::Sprite m_sprite;
};

