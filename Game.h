#pragma once
#include "includes.hpp"
#include "Texture_Manager.hpp"
#include <vector>
#include "Entity.h"
#include <cstdlib>
#include "spear.h"
#include "Fish.h"
class Game
{
public:
	Game();
	~Game();
	void Spawn_Enemies(const int& amount);
	void Move_Enemies(const sf::Time& dt);
	void Check_Enemie_Collision_with_spear();
	void Draw_Enemies();
	void Draw_Spear();
	bool Is_Spear_Inbounds();
	void Run();
private:
	sf::RenderWindow m_window;
	Texture_Manager m_texture_manager{};
	std::vector<Fish*> m_enemies;
	Entity m_player;
	sf::Sprite m_back_ground;
	sf::Clock m_clock;
	Spear* m_spear;
};