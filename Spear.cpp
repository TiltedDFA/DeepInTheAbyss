#include "Spear.h"
Spear::Spear() : Entity(Texture_Manager::get_texture(S_SPEAR_PATH)) {
	m_inital_mouse_pos = { 0,0 };
	m_velocity = { 0,0 };
}
void Spear::set_intial_mouse_pos(const sf::Vector2i& pos) {

}