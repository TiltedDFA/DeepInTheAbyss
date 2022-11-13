#include "Spear.h"
//should only include cmath locally here
#include <cmath>
Spear::Spear(const sf::Vector2f& player_pos) : Entity(Texture_Manager::get_texture(S_SPEAR_PATH)) {
	m_sprite.setPosition({ player_pos.x + PLYR_SPRITE_WIDTH / 2,player_pos.y + PLYR_SPRITE_HEIGHT / 2 });
	m_inital_mouse_pos = { 0,0 };
	m_velocity = { 0,0 };
}
void Spear::set_intial_mouse_pos(const sf::RenderWindow& window) {
	this->m_inital_mouse_pos = sf::Mouse::getPosition(window);
}
void Spear::set_velocity(const sf::Vector2i& current_mouse_pos) {
	m_velocity = { -(current_mouse_pos.x - m_inital_mouse_pos.x) * 2,
		-(current_mouse_pos.y - m_inital_mouse_pos.y) * 2 };
		
	if (m_velocity.y == 0) return;
	float rotation = atan(m_velocity.x / m_velocity.y) * 180 / PI;
	if (m_velocity.y > 0) rotation += 180;
	m_sprite.setRotation(-rotation);
}
void Spear::move(const sf::Time& time) {
	m_sprite.setPosition({ m_sprite.getPosition().x + m_velocity.x * time.asSeconds(),
		m_sprite.getPosition().y + m_velocity.y * time.asSeconds() });
}
const sf::Vector2i& Spear::get_velocity()const {
	return m_velocity;
}