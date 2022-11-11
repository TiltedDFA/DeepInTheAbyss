#include "Entity.h"
Entity::Entity(const sf::Texture& texture, const sf::Vector2i& position) {
	m_sprite.setTexture(texture);
	m_sprite.setPosition(sf::Vector2f(position));
}
void Entity::init(const sf::Texture& texture, const sf::Vector2i& position) {
	this->m_sprite.setTexture(texture);
	this->m_sprite.setPosition(sf::Vector2f(position));
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
