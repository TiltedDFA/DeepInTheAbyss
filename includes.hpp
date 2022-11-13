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
#ifdef SFML_STATIC
#define main WinMain()
#else
#define main main()
#endif // SFML_STATIC
#define FONT_PATH "assets/OETZTYP_.ttf"
#define PLYR_SPRITE_WIDTH 100
#define PLYR_SPRITE_HEIGHT 100
#define PLYR_SIDE_MOVEMENT_RATE 250.0f
#define PLYR_FLOAT_UP_RATE 5.0f
#define FRICTION 5
#define PI 3.1415926535
#define SPEAR_WIDTH 10
#define SPEAR_HEIGHT 30
#define PLYR_FLOAT_RATE 15.0f
#define STAGE_ONE_RND_SPEED rand() % 20 + 5
#define STAGE_TWO_RND_SPEED rand() % 30 + 15
#define STAGE_THREE_RND_SPEED rand() % 75 + 50
#define MENU_MUSIC_PATH "assets/menu_music.wav"
#define GAME_MUSIC_PATH "assets/game_music.ogg"
#define WIN_MUSIC_PATH "assets/win_music.wav"
#define LOSE_MUSIC_PATH "assets/lose_music.ogg"
#define S_POWER_UP_PATH "assets/power_up.png"
#define S_P_SPEAR_PATH "assets/p_spear_sprite.png"