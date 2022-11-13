#include "Entity.h"
Entity::Entity(const sf::Texture& texture, const sf::Vector2i& position) {
	m_sprite.setTexture(texture);
	m_sprite.setPosition(sf::Vector2f(position));
}
void Entity::init(const sf::Texture& texture, const sf::Vector2i& position) {
	this->m_sprite.setTexture(texture);
	this->m_sprite.setPosition(sf::Vector2f(position));
}
void Entity::move(const Direction& var, const sf::Time& dt) {
	if (var == Direction::LEFT && m_sprite.getPosition().x > 0)
	{
		m_sprite.setPosition((m_sprite.getPosition().x - (PLYR_SIDE_MOVEMENT_RATE*dt.asSeconds())),
			m_sprite.getPosition().y);
		return;
	}
	if (m_sprite.getPosition().x < (1000-PLYR_SPRITE_WIDTH)) {
		m_sprite.setPosition((m_sprite.getPosition().x + (PLYR_SIDE_MOVEMENT_RATE * dt.asSeconds())),
		m_sprite.getPosition().y);		
	}
}
void Entity::draw(sf::RenderWindow& window)const {
	window.draw(m_sprite);
}
void Entity::set_position(const sf::Vector2f& position) {
	m_sprite.setPosition(position);
}
const sf::Vector2f& Entity::get_position()const{
	return m_sprite.getPosition();
}
const sf::FloatRect& Entity::get_global_bounds()const {
	return m_sprite.getGlobalBounds();
}