#include "Game.h"
Game::Game(){
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DeepInAbyss");
    m_window.setFramerateLimit(120);
    m_player.init(Texture_Manager::get_texture(S_CHARACTER_PATH), {450,900});
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
bool Game::Enemie_Collides_With_Player() {
    for (const auto& i : m_enemies) {
        if (m_player.get_global_bounds().intersects(i->get_global_bounds())) {
            return true;
        }
    }
    return false;
}
void Game::Check_Enemie_Collision_with_spear() {
    if (m_spear == nullptr) return;
    if (m_spear->get_velocity() == sf::Vector2i({ 0,0 })) return;
    for (auto i = m_enemies.begin(); i != m_enemies.end(); i++) {
        //this check does not work yet, make fish move towards player's center.
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
void Game::Run_Title_Screen() {
    
    sf::RectangleShape back_ground;
    sf::RectangleShape play_button;
    sf::RectangleShape title_backing;
    sf::Text title;
    sf::Text play;
    back_ground.setSize({ 1000,1000 });
    back_ground.setPosition({ 0,0 });
    back_ground.setFillColor(sf::Color::Cyan);

    play_button.setSize({ 300,100 });
    play_button.setPosition({ 350,500 });
    play_button.setFillColor(sf::Color::Green);
    play_button.setOutlineColor(sf::Color::Black);
    play_button.setOutlineThickness(5);

    title_backing.setSize({975,120});
    title_backing.setPosition({ 5,110 });
    title_backing.setFillColor(sf::Color::Red);
    title_backing.setOutlineColor(sf::Color::Black);
    title_backing.setOutlineThickness(5);
    
    play.setFont(Texture_Manager::get_font(FONT_PATH));
    play.setCharacterSize(80);
    play.setOutlineColor(sf::Color::Black);
    play.setOutlineThickness(5);
    play.setPosition({ 400,490 });
    play.setString("Play");

    title.setFont(Texture_Manager::get_font(FONT_PATH));
    title.setCharacterSize(95);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(5);
    title.setPosition({ 10,100 });
    title.setString("Deep In The Abyss");

    bool button_pressed = false;
    while (m_window.isOpen()) {
        
        
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (play_button.getGlobalBounds().contains(
                        sf::Vector2f(sf::Mouse::getPosition(m_window)))) {
                        button_pressed = true;
                    }
                }
            }
        }
        if (button_pressed) break;
        m_window.clear();
        m_window.draw(back_ground);
        m_window.draw(title_backing);
        m_window.draw(play_button);
        m_window.draw(play);
        m_window.draw(title);
        m_window.display();
    }
}
void Game::Run_Main_Loop() {
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
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_spear != nullptr) {
                    delete m_spear;
                    m_spear = nullptr;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased && m_spear != nullptr) {
                m_spear->set_velocity(sf::Mouse::getPosition(m_window));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            m_player.move(Direction::LEFT, delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            m_player.move(Direction::RIGHT, delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Spawn_Enemies(1);
        }
        if (!(Is_Spear_Inbounds())) {
            delete m_spear;
            m_spear = nullptr;
        }
        if (m_spear != nullptr) {
            m_spear->move(delta_time);
        }
        if (Enemie_Collides_With_Player()) {
            break;
        }
        Move_Enemies(delta_time);
        Check_Enemie_Collision_with_spear();
        m_player.float_up(delta_time);


        m_window.clear();
        m_window.draw(m_back_ground);
        m_player.draw(m_window);
        Draw_Enemies();
        Draw_Spear();
        m_window.display();
    }
}
void Game::Run() {
    Run_Title_Screen();
    Run_Main_Loop();
}