#pragma once
#include "includes.hpp"
#include "Texture_Manager.hpp"
#include <vector>
#include "Entity.h"
#include <cstdlib>
#include "spear.h"
#include "player.h"
#include "Fish.h"
class Game
{
public:
	Game();
	~Game();
	void Spawn_Enemies(const int& amount);
	void Move_Enemies(const sf::Time& dt);
	bool Enemie_Collides_With_Player();
	void Check_Enemie_Collision_with_spear();
	void Draw_Enemies();
	void Draw_Spear();
	bool Is_Spear_Inbounds();

	void Run_Title_Screen();
	void Run_Lose_Screen();
	void Run_Win_Screen();
	void Run_Main_Loop();

	void Run();
private:
	sf::RenderWindow m_window;
	Texture_Manager m_texture_manager{};
	std::vector<Fish*> m_enemies;
	player m_player;
	sf::Sprite m_back_ground;
	sf::Clock m_clock;
	Spear* m_spear;
};