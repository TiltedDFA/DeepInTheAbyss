#include "Game.h"
Game::Game(){
	
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DeepInAbyss");
    m_window.setFramerateLimit(120);
    m_player.init(Texture_Manager::get_texture(S_CHARACTER_PATH));
    srand(time(0));
}
void Game::Spawn_Enemies(const int& amount) {
    for (int i = 0; i < amount; ++i) {
        int x_position = rand() % 1000 + 0;//rnd num 0-999
        int y_position = rand() % 250 + 0 ;//rnd num 0-249
        Entity new_enemie(Texture_Manager::get_texture(S_FISH_ENEMIE_PATH),
            sf::Vector2i(x_position, y_position));
        m_enemies.push_back(new_enemie);
    }
}
void Game::Draw_Enemies() {
    for (const auto& enemie : m_enemies) {
        enemie.draw(m_window);
    }
}
void Game::Run() {
    while (m_window.isOpen())
    {
        sf::Time delta_time = m_clock.restart();
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_player.move(Direction::LEFT,delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_player.move(Direction::RIGHT,delta_time);
        }
        
        m_window.clear();
        m_player.draw(m_window);
        Draw_Enemies();
        m_window.display();
    }
}