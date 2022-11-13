#include "Fish.h"
Fish::Fish(const int& speed, const sf::Vector2i& position) 
	: Entity(Texture_Manager::get_texture(S_FISH_ENEMIE_PATH), position) {
	m_speed = speed;
}
void Fish::move(const sf::Vector2f& player_position, const sf::Time& dt) {
	//will get fish to move towards the CENTER of the player at a given speed
	if (player_position.x > m_sprite.getPosition().x - PLYR_SPRITE_WIDTH/2) {
		m_sprite.setPosition(m_sprite.getPosition().x + m_speed * dt.asSeconds(), m_sprite.getPosition().y);
	}
	else {
		m_sprite.setPosition(m_sprite.getPosition().x - m_speed * dt.asSeconds(), m_sprite.getPosition().y);
	}
	if (player_position.y > m_sprite.getPosition().y - PLYR_SPRITE_HEIGHT/2) {
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y + m_speed * dt.asSeconds());
	}
	else {
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - m_speed * dt.asSeconds());
	}
}
void Fish::set_speed(const int& speed) {
	m_speed = speed;
}
const int& Fish::get_speed()const {
	return m_speed;
}
