#include "Game.h"
Game::Game(){
	
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DeepInAbyss");
    m_window.setFramerateLimit(120);
    m_player.init(Texture_Manager::get_texture(S_CHARACTER_PATH));
    m_back_ground.setTexture(Texture_Manager::get_texture(S_BACK_GROUND_PATH));
    m_back_ground.setPosition({ 0,0 });
    m_spear = nullptr;
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
void Game::Draw_Spear() {
    if (m_spear == nullptr) return;
    m_spear->draw(m_window);
}
bool Game::Is_Spear_Inbounds() {
    if (m_spear == nullptr) return true;
    sf::Vector2f spear_position = m_spear->get_position();
    if (spear_position.x > 0 && spear_position.x < 1000 &&
        spear_position.y > 0 && spear_position.y < 1000)
    {
        return true;
    }
    return false;
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
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_spear == nullptr) {
                    m_spear = new Spear(m_player.get_position());
                    m_spear->set_intial_mouse_pos(m_window);
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                m_spear->set_velocity(sf::Mouse::getPosition(m_window));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_player.move(Direction::LEFT,delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_player.move(Direction::RIGHT,delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Spawn_Enemies(1);
        }
        if (!(Is_Spear_Inbounds())) {
            delete m_spear;
            m_spear = nullptr;
        }
        if(m_spear != nullptr) {
            m_spear->move(delta_time);
        }
        
        m_window.clear();
        m_window.draw(m_back_ground);
        m_player.draw(m_window);
        Draw_Enemies();
        Draw_Spear();
        m_window.display();
    }
}