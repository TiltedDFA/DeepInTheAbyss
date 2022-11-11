#include "Texture_Manager.hpp"
#include <assert.h>

//need to redeclare the datatype upon init of a static var
Texture_Manager* Texture_Manager::m_s_instance = nullptr;

Texture_Manager::Texture_Manager() {
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}
sf::Texture& Texture_Manager::get_texture(const std::string& name) {
	auto& texture_map = m_s_instance->m_textures;
	auto keyValuePair = texture_map.find(name);

	if (keyValuePair != texture_map.end())
	{
		return keyValuePair->second;
	}
	else {
		auto& texture = texture_map[name];
		if (!texture.loadFromFile(name))
		{
			throw std::runtime_error("FAILED TO LOAD TEXTURE");
		}
		return texture;
	}
}
sf::Font& Texture_Manager::get_font(const std::string& font_name) {
	auto& font_map = m_s_instance->m_fonts;
	auto keyValuePair = font_map.find(font_name);
	if (keyValuePair != font_map.end()) {
		return keyValuePair->second;
	}
	else {
		auto& font = font_map[font_name];
		if (!font.loadFromFile(font_name))
		{
			throw std::runtime_error("FAILED TO LOAD FONT");
		}
		return font;
	}
}