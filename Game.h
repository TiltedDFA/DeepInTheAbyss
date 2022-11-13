#pragma once
#include "includes.hpp"
#include "Texture_Manager.hpp"
#include <vector>
#include "Entity.h"
#include <cstdlib>
#include "spear.h"
#include "player.h"
#include "Fish.h"
#include <SFML/Audio.hpp>
class Game
{
public:
	Game();
	~Game();
	void Spawn_Enemies();
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
	sf::Sound m_menu_music;
	sf::Sound m_game_music;
	sf::Sound m_win_music;
	sf::Sound m_lose_music;
	sf::RenderWindow m_window;
	Texture_Manager m_texture_manager{};
	std::vector<Fish*> m_enemies;
	player m_player;
	sf::Sprite m_back_ground;
	sf::Clock m_clock;
	sf::Clock m_game_time;
	//this will be used to decided the speed of enemies
	//depending on which stage the game is in
	int m_num_clock_resets;
	Spear* m_spear;
};