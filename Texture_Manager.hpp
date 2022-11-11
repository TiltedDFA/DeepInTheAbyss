#pragma once
#include "includes.hpp"
class Texture_Manager
{
public:
	Texture_Manager();
	Texture_Manager(const Texture_Manager& other) = delete;//deleting copy constructor
	void operator=(const Texture_Manager& other) = delete;
	static sf::Texture& get_texture(const std::string& texture_name);
	static sf::Font& get_font(const std::string& font_name);
private:
	static Texture_Manager* m_s_instance;
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
};