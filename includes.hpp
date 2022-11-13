#pragma once
#include <SFML/graphics.hpp>
#include <map>
#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1000
#define S_CHARACTER_PATH "assets/char_sprite_ph.png"
#define S_FISH_ENEMIE_PATH "assets/fish_sprite_enemy.png"
#define S_SPEAR_PATH "assets/spear_sprite.png"
#define S_BACK_GROUND_PATH "assets/back_ground.png"
enum class Direction {
	LEFT = 0,
	RIGHT
};
#define PLYR_SPRITE_WIDTH 100
#define PLYR_SPRITE_HEIGHT 100
#define PLYR_SIDE_MOVEMENT_RATE 250.0f
#define PLYR_FLOAT_UP_RATE 5.0f
#define FRICTION 5
#define PI 3.1415926535
#define SPEAR_WIDTH 10
#define SPEAR_HEIGHT 30