#pragma once
#include "includes.hpp"
#include "Texture_Manager.hpp"
#include <vector>
#include "Entity.h"
class Game
{
public:
	Game();
	void Run();
private:
	sf::RenderWindow m_window;
	Texture_Manager m_texture_manager{};
	std::vector<Entity> m_enemies;
	Entity m_player;
};

