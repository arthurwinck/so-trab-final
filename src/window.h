#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include "traits.h"

__BEGIN_API

class Window
{
public:
    Window();

    int running();

    int runbool;

    void run(int pacman_pos_x, int pacman_pos_y, int pacman_offset, int pacman_dir,
    int blinky_pos_x, int blinky_pos_y, int blinky_offset, int blinky_dir, int blinky_state,
    int pinky_pos_x, int pinky_pos_y, int pinky_offset, int pinky_dir, int pinky_state,
    int inky_pos_x, int inky_pos_y, int inky_offset, int inky_dir, int inky_state,
    int clyde_pos_x, int clyde_pos_y, int clyde_offset, int clyde_dir, int clyde_state);

    void draw_texture(unsigned int texture, int length, int height, float angle);

    void draw_pacman(unsigned int texture, int length, int height, float angle, sf::RenderWindow* window);
    void draw_ghost(unsigned int texture, int length, int height, int angle, sf::Sprite sprite_list[2], sf::RenderWindow* window);

    void draw_pontos(int pacman_pos_x, int pacman_pos_y, sf::RenderWindow* window);

    sf::RenderWindow* getWindowobj();
    int pacman_rotation;
    int blinky_rotation;
    int pinky_rotation;
    int inky_rotation;
    int clyde_rotation;
    static char* get_maze() {
        return Window::maze;
    }

private:
    void load_and_bind_textures();


private:

    static char maze[868];

    // Animation lists
    sf::Sprite pacman_animate[3];
    sf::Sprite red_ghost_animate[2];
    sf::Sprite yellow_ghost_animate[2];
    sf::Sprite pink_ghost_animate[2];
    sf::Sprite blue_ghost_animate[2];


    //Clock
    sf::Clock clock;


    // Maze Textures
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;
    sf::Texture pill_tex;
    sf::Sprite pill_sprite;
    sf::Texture bigPill_tex;
    sf::Sprite bigPill_sprite;

    // Pacman Textures
    sf::Texture pac_0_tex;
    sf::Sprite pac_0_sprite;
    sf::Texture pac_1_tex;
    sf::Sprite pac_1_sprite;
    sf::Texture pac_2_tex;
    sf::Sprite pac_2_sprite;
    sf::Texture dead_0_tex;
    sf::Sprite dead_0_sprite;
    sf::Texture dead_1_tex;
    sf::Sprite dead_1_sprite;
    sf::Texture dead_2_tex;
    sf::Sprite dead_2_sprite;
    sf::Texture dead_3_tex;
    sf::Sprite dead_3_sprite;
    sf::Texture dead_4_tex;
    sf::Sprite dead_4_sprite;
    sf::Texture dead_5_tex;
    sf::Sprite dead_5_sprite;
    sf::Texture dead_6_tex;
    sf::Sprite dead_6_sprite;
    sf::Texture dead_7_tex;
    sf::Sprite dead_7_sprite;
    sf::Texture dead_8_tex;
    sf::Sprite dead_8_sprite;
    sf::Texture dead_9_tex;
    sf::Sprite dead_9_sprite;
    sf::Texture dead_10_tex;
    sf::Sprite dead_10_sprite;

    // Ghost Textures
    sf::Texture ghost_r_0_tex;
    sf::Sprite ghost_r_0_sprite;
    sf::Texture ghost_r_1_tex;
    sf::Sprite ghost_r_1_sprite;
    sf::Texture ghost_p_0_tex;
    sf::Sprite ghost_p_0_sprite;
    sf::Texture ghost_p_1_tex;
    sf::Sprite ghost_p_1_sprite;
    sf::Texture ghost_b_0_tex;
    sf::Sprite ghost_b_0_sprite;
    sf::Texture ghost_b_1_tex;
    sf::Sprite ghost_b_1_sprite;
    sf::Texture ghost_y_0_tex;
    sf::Sprite ghost_y_0_sprite;
    sf::Texture ghost_y_1_tex;
    sf::Sprite ghost_y_1_sprite;
    sf::Texture ghost_scared_0_tex;
    sf::Sprite ghost_scared_0_sprite;
    sf::Texture ghost_scared_1_tex;
    sf::Sprite ghost_scared_1_sprite;
    sf::Texture ghost_scared_2_tex;
    sf::Sprite ghost_scared_2_sprite;
    sf::Texture ghost_scared_3_tex;
    sf::Sprite ghost_scared_3_sprite;

    // Eye Textures
    sf::Texture eye_up_tex;
    sf::Sprite eye_up_sprite;
    sf::Texture eye_right_tex;
    sf::Sprite eye_right_sprite;
    sf::Texture eye_down_tex;
    sf::Sprite eye_down_sprite;
    sf::Texture eye_left_tex;
    sf::Sprite eye_left_sprite;

    // UI Textures
    sf::Texture num_0_tex;
    sf::Sprite num_0_sprite;
    sf::Texture num_1_tex;
    sf::Sprite num_1_sprite;
    sf::Texture num_2_tex;
    sf::Sprite num_2_sprite;
    sf::Texture num_3_tex;
    sf::Sprite num_3_sprite;
    sf::Texture num_4_tex;
    sf::Sprite num_4_sprite;
    sf::Texture num_5_tex;
    sf::Sprite num_5_sprite;
    sf::Texture num_6_tex;
    sf::Sprite num_6_sprite;
    sf::Texture num_7_tex;
    sf::Sprite num_7_sprite;
    sf::Texture num_8_tex;
    sf::Sprite num_8_sprite;
    sf::Texture num_9_tex;
    sf::Sprite num_9_sprite;
    sf::Texture score_200_tex;
    sf::Sprite score_200_sprite;
    sf::Texture score_400_tex;
    sf::Sprite score_400_sprite;
    sf::Texture score_800_tex;
    sf::Sprite score_800_sprite;
    sf::Texture score_1600_tex;
    sf::Sprite score_1600_sprite;
    sf::Texture ready_tex;
    sf::Sprite ready_sprite;
    sf::Texture gameover_tex;
    sf::Sprite gameover_sprite;
    sf::Texture life_tex;
    sf::Sprite life_sprite;
    sf::Texture score_tex;
    sf::Sprite score_sprite;
    sf::Texture high_tex;
    sf::Sprite high_sprite;
    sf::Texture score_100_tex;
    sf::Sprite score_100_sprite;
    sf::Texture score_300_tex;
    sf::Sprite score_300_sprite;

    // Fruit Textures
    sf::Texture cherry_tex;
    sf::Sprite cherry_sprite;
    sf::Texture strawberry_tex;
    sf::Sprite strawberry_sprite;
};

__END_API

#endif