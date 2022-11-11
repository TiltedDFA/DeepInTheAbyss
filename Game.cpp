#include "Game.h"
Game::Game(){
	
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DeepInAbyss");
	m_player.init(Texture_Manager::get_texture(S_CHARACTER_PATH));

}
void Game::Run() {
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear();
        m_player.draw(m_window);
        m_window.display();
    }
}