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
Game::~Game() {
    if (m_spear != nullptr) delete m_spear;
    for (auto& i : m_enemies) {
        delete i;
    }
}
void Game::Spawn_Enemies(const int& amount) {
    for (int i = 0; i < amount; ++i) {
        int x_position = rand() % 1000 + 0;//rnd num 0-999
        int y_position = rand() % 250 + 0 ;//rnd num 0-249
        Fish* new_enemie = new Fish((rand()% 25 + 5),
            sf::Vector2i(x_position, y_position));
        m_enemies.push_back(new_enemie);
    }
}
void Game::Move_Enemies(const sf::Time& dt) {
    for (auto& enemie : m_enemies) {
        enemie->move(m_player.get_position(),dt);
    }
}
bool Game::Enemie_Collides_With_Spear(const Fish* enemie) {
    /*
      rect1.x < rect2.x + rect2.w &&
    rect1.x + rect1.w > rect2.x &&
    rect1.y < rect2.y + rect2.h &&
    rect1.h + rect1.y > rect2.y
    */
    auto fish_pos = enemie->get_global_bounds();
    auto spear_pos = m_spear->get_global_bounds();
    
    //if(fish_pos.x < spear_pos.x + )
    return true;
}
void Game::Check_Enemie_Collision_with_spear() {
    if (m_spear == nullptr) return;
    if (m_spear->get_velocity() == sf::Vector2i({ 0,0 })) return;
    for (auto i = m_enemies.begin(); i != m_enemies.end(); i++) {
        //this check does not work yet, make fish move towards player's center.
        Enemie_Collides_With_Spear(*i);
        if (m_spear->get_global_bounds().intersects((*i)->get_global_bounds())) {
            //m_spear->get_global_bounds().intersects((*i)->get_global_bounds())
            delete m_spear;
            m_spear = nullptr;
            delete (*i);
            m_enemies.erase(i);
            return;
        }
    }
}
void Game::Draw_Enemies() {
    for (const auto& enemie : m_enemies) {
        enemie->draw(m_window);
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
            if (event.type == sf::Event::MouseButtonReleased && m_spear != nullptr) {
                m_spear->set_velocity(sf::Mouse::getPosition(m_window));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || 
            sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            m_player.move(Direction::LEFT,delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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
        Move_Enemies(delta_time);
        Check_Enemie_Collision_with_spear();



        m_window.clear();
        m_window.draw(m_back_ground);
        m_player.draw(m_window);
        Draw_Enemies();
        Draw_Spear();
        m_window.display();
    }
}