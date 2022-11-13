#include "player.h"
player::player(const sf::Vector2i& starting_position): Entity(Texture_Manager::get_texture(S_CHARACTER_PATH), starting_position) {

}
void player::float_up(const sf::Time& dt) {
	m_sprite.setPosition({ m_sprite.getPosition().x,
		m_sprite.getPosition().y - PLYR_FLOAT_RATE * dt.asSeconds()});
}