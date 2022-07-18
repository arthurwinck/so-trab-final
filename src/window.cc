#include "window.h"
#include "traits.h"
#include <chrono>
__BEGIN_API

/**
 * Tile defined as an enum where each type is defined as:
 *      W: Wall
 *      G: Ghost Pen Gate
 *      P: Portal
 *      u: Empty path
 *      o: Pill
 *      e: Eaten Pill
 *      O: Big Pill
 *      E: Eaten Big Pill
 */


// 2D array defines the size of the maze and also what each tile contains
// tile maze[28][31] =
//         {
//                 {W,W,W,W,W,W,W,W,W,W,W,W,u,u,u,W,P,W,u,u,u,W,W,W,W,W,W,W,W,W,W},
//                 {W,o,o,o,o,W,W,O,o,o,o,W,u,u,u,W,u,W,u,u,u,W,o,o,o,o,O,o,o,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,W,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,u,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
//                 {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,W,W,o,u,u,u,u,u,u,u,u,u,W,W,o,o,o,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,W,W,W,W,u,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,u,u,u,W,u,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,o,o,o,W,W,o,o,o,o,W,W,u,W,u,u,u,W,u,u,u,o,W,W,o,o,o,o,o,W},
//                 {W,o,W,W,W,W,W,u,W,W,W,W,W,u,W,u,u,u,G,u,W,W,W,W,W,o,W,W,W,W,W},
//                 {W,o,W,W,W,W,W,u,W,W,W,W,W,u,W,u,u,u,G,u,W,W,W,W,W,o,W,W,W,W,W},
//                 {W,o,o,o,o,W,W,o,o,o,o,W,W,u,W,u,u,u,W,u,u,u,o,W,W,o,o,o,o,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,u,u,u,W,u,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,W,W,W,W,u,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,W,W,o,u,u,u,u,u,u,u,u,u,W,W,o,o,o,o,W,W,W,o,W},
//                 {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
//                 {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,u,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,W,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,o,o,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,W,W,o,W,W,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
//                 {W,o,o,o,o,W,W,O,o,o,o,W,u,u,u,W,u,W,u,u,u,W,o,o,o,o,O,o,o,o,W},
//                 {W,W,W,W,W,W,W,W,W,W,W,W,u,u,u,W,P,W,u,u,u,W,W,W,W,W,W,W,W,W,W}
//         };


//31 por 28
char Window::maze[868] = {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'O', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'O', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'G', 'G', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
    'P', 'u', 'u', 'u', 'u', 'u', 'o', 'u', 'u', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'u', 'u', 'o', 'u', 'u', 'u', 'u', 'u', 'P',
    'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'u', 'u', 'u', 'u', 'u', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'u', 'u', 'u', 'u', 'u',
    'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'u', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'u', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'O', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'O', 'W',
    'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W',
    'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'W', 'W', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W', 'W', 'o', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'o', 'W',
    'W', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'W',
    'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'};

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
auto start_time = std::chrono::high_resolution_clock::now();
auto end_time = std::chrono::high_resolution_clock::now();
Window::Window()
{   
    runbool=1;
    load_and_bind_textures();
}

int Window::running(){
    return Window::runbool;
}

sf::RenderWindow * Window::getWindowobj() {
    return &window;
}

void Window::draw_texture(unsigned int texture, int length, int height, float angle)
{
}

void Window::draw_pacman(unsigned int texture, int length, int height, float angle, sf::RenderWindow* window) {
    this->pacman_animate[texture].setPosition(length, height);
    this->pacman_animate[texture].setRotation(angle);
    window->draw(pacman_animate[texture]);
}

void Window::draw_ghost(unsigned int texture, int length, int height, float angle, sf::Sprite sprite_list[2], sf::RenderWindow* window) {
    sprite_list[texture].setPosition(length, height);
    sprite_list[texture].rotate(angle);
    this->eye_left_sprite.setPosition(length, height);
    window->draw(sprite_list[texture]);
    window->draw(eye_left_sprite);
}


void Window::run(int pacman_pos_x, int pacman_pos_y, int pacman_offset, int pacman_dir)
{

    //sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    window.setKeyRepeatEnabled(false);


    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::Closed:
                window.close();
                runbool=0;
                break;
        }
    }
    //    
    //    // key pressed
    //    case sf::Event::KeyPressed:
    //        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //            std::cout << "Keyboard esquerda!" << std::endl;
    //        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //            std::cout << "Keyboard direita!" << std::endl;
    //        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    //            std::cout << "Keyboard para baixo!" << std::endl;
    //        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //            std::cout << "Keyboard para cima!" << std::endl;
    //        } else
    //            std::cout << "Keyboard pressed = " << event.key.code << std::endl;
    //        break;
    //    
    //    }
    //}
    window.clear();
    window.draw(maze_sprite);



//rendereriza pontos
    div_t position;
    for (int tile=0; tile<868;tile++) {
        if (maze[tile]=='o'){
            position = div (tile,28);
            //Vetor de 28x31=868 posições usado como "grid"
            //calculo de pos(x): 16x (Tile Mod 28) + (offset de 3 se quiser deixar mais bonito)
            //calculo de pos(y): (Tile//28) * 16
            pill_sprite.setPosition ((position.rem) * 16 + 3 ,(position.quot) * 16 );
            window.draw(pill_sprite);
        }
            
    }

//renderiza os 4 energizadores
    if ((((int) clock.getElapsedTime().asMilliseconds()/300) % 2) == 1) {
        if (maze[138]=='O'){
                position = div (138,28);
                bigPill_sprite.setPosition ((position.rem) * 16 + 3,(int)(position.quot) * 16 );
                window.draw(bigPill_sprite);
        }

        if (maze[645]=='O'){
                position = div (645,28);
                bigPill_sprite.setPosition ((position.rem) * 16 + 3,(int)(position.quot) * 16 );
                window.draw(bigPill_sprite);
        }

        if (maze[670]=='O'){
                position = div (670,28);
                bigPill_sprite.setPosition ((position.rem) * 16 + 3,(int)(position.quot) * 16 );
                window.draw(bigPill_sprite);
        }

        if (maze[113]=='O'){
                position = div (113,28);
                bigPill_sprite.setPosition ((position.rem) * 16 + 3,(int)(position.quot) * 16 );
                window.draw(bigPill_sprite);
        }
    }

    window.draw(pill_sprite);

    // Função para desenhar personagens na tela - Usamos o clock do SFML para saber qual sprite vamos blitar
    // Lembrar de mudar para posição inicial e atualizar
    while(1){
        
        end_time = std::chrono::high_resolution_clock::now();
        if (end_time>start_time+std::chrono::milliseconds(100)){
            start_time=std::chrono::high_resolution_clock::now();
            break;
        }
    }

    switch (pacman_dir){
        case 0: pacman_rotation=0;pacman_pos_x=pacman_pos_x*16 + pacman_offset;pacman_pos_y*=16;break;
        case 1: pacman_rotation=180;pacman_pos_x=pacman_pos_x*16 + pacman_offset;pacman_pos_y= pacman_pos_y * 16 + 15;break;
        case 2: pacman_rotation=270;pacman_pos_y=pacman_pos_y*16 + pacman_offset;pacman_pos_x*=16;break;
        case 3: pacman_rotation=90;pacman_pos_y=pacman_pos_y*16 + pacman_offset;pacman_pos_x=pacman_pos_x *16 + 15;break;
    }
    draw_pacman(((int) clock.getElapsedTime().asMilliseconds()/200) % 3 , pacman_pos_x, pacman_pos_y, pacman_rotation, &window);
    draw_ghost(((int) clock.getElapsedTime().asMilliseconds()/200) % 2 , 245, 150, 0, pink_ghost_animate, &window);
    draw_ghost(((int) clock.getElapsedTime().asMilliseconds()/200) % 2 , 670, 150, 0, blue_ghost_animate, &window);
    draw_ghost(((int) clock.getElapsedTime().asMilliseconds()/200) % 2 , 113, 150, 0, yellow_ghost_animate, &window);
    draw_ghost(((int) clock.getElapsedTime().asMilliseconds()/200) % 2 , 138, 150, 0, red_ghost_animate, &window);

    /*if (maze[pacman_pos_y*28 + pacman_pos_x]='o'){
        std::cout<< "Uau";
        maze[pacman_pos_y*28 + pacman_pos_x]='u';
    }*/
    window.display();

}

void Window::load_and_bind_textures()
{
    // Bind map textures    
    maze_tex.loadFromFile("sprites/maze/maze.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(2, 2);
    pill_tex.loadFromFile("sprites/maze/p-0.png");
    pill_sprite.setTexture(pill_tex);
    bigPill_tex.loadFromFile("sprites/maze/p-1.png");
    bigPill_sprite.setTexture(bigPill_tex);

    // Bind Pacman textures
    pac_0_tex.loadFromFile("sprites/pacman/0.png");
    pac_0_sprite.setTexture(pac_0_tex);
    pac_1_tex.loadFromFile("sprites/pacman/1.png");
    pac_1_sprite.setTexture(pac_1_tex);
    pac_2_tex.loadFromFile("sprites/pacman/2.png");
    pac_2_sprite.setTexture(pac_2_tex);
    dead_0_tex.loadFromFile("sprites/pacman/d-0.png");
    dead_0_sprite.setTexture(dead_0_tex);
    dead_1_tex.loadFromFile("sprites/pacman/d-1.png");
    dead_1_sprite.setTexture(dead_1_tex);
    dead_2_tex.loadFromFile("sprites/pacman/d-2.png");
    dead_2_sprite.setTexture(dead_2_tex);
    dead_3_tex.loadFromFile("sprites/pacman/d-3.png");
    dead_3_sprite.setTexture(dead_3_tex);
    dead_4_tex.loadFromFile("sprites/pacman/d-4.png");
    dead_4_sprite.setTexture(dead_4_tex);
    dead_5_tex.loadFromFile("sprites/pacman/d-5.png");
    dead_5_sprite.setTexture(dead_5_tex);
    dead_6_tex.loadFromFile("sprites/pacman/d-6.png");
    dead_6_sprite.setTexture(dead_6_tex);
    dead_7_tex.loadFromFile("sprites/pacman/d-7.png");
    dead_7_sprite.setTexture(dead_7_tex);
    dead_8_tex.loadFromFile("sprites/pacman/d-8.png");
    dead_8_sprite.setTexture(dead_8_tex);
    dead_9_tex.loadFromFile("sprites/pacman/d-9.png");
    dead_9_sprite.setTexture(dead_9_tex);
    dead_10_tex.loadFromFile("sprites/pacman/d-10.png");
    dead_10_sprite.setTexture(dead_10_tex);

    // Bind ghost textures
    ghost_r_0_tex.loadFromFile("sprites/ghosts/r-0.png");
    ghost_r_0_sprite.setTexture(ghost_r_0_tex);
    ghost_r_1_tex.loadFromFile("sprites/ghosts/r-1.png");
    ghost_r_1_sprite.setTexture(ghost_r_1_tex);
    ghost_p_0_tex.loadFromFile("sprites/ghosts/p-0.png");
    ghost_p_0_sprite.setTexture(ghost_p_0_tex);
    ghost_p_1_tex.loadFromFile("sprites/ghosts/p-1.png");
    ghost_p_1_sprite.setTexture(ghost_p_1_tex);
    ghost_b_0_tex.loadFromFile("sprites/ghosts/b-0.png");
    ghost_b_0_sprite.setTexture(ghost_b_0_tex);
    ghost_b_1_tex.loadFromFile("sprites/ghosts/b-1.png");
    ghost_b_1_sprite.setTexture(ghost_b_1_tex);
    ghost_y_0_tex.loadFromFile("sprites/ghosts/y-0.png");
    ghost_y_0_sprite.setTexture(ghost_y_0_tex);
    ghost_y_1_tex.loadFromFile("sprites/ghosts/y-1.png");
    ghost_y_1_sprite.setTexture(ghost_y_1_tex);
    ghost_scared_0_tex.loadFromFile("sprites/ghosts/s-0.png");
    ghost_scared_0_sprite.setTexture(ghost_scared_0_tex);
    ghost_scared_1_tex.loadFromFile("sprites/ghosts/s-1.png");
    ghost_scared_1_sprite.setTexture(ghost_scared_1_tex);
    ghost_scared_2_tex.loadFromFile("sprites/ghosts/s-2.png");
    ghost_scared_2_sprite.setTexture(ghost_scared_2_tex);
    ghost_scared_3_tex.loadFromFile("sprites/ghosts/s-3.png");
    ghost_scared_3_sprite.setTexture(ghost_scared_3_tex);

     // Bind ghost eye textures
    eye_up_tex.loadFromFile("sprites/eyes/up.png");
    eye_up_sprite.setTexture(eye_up_tex);
    eye_right_tex.loadFromFile("sprites/eyes/right.png");
    eye_right_sprite.setTexture(eye_right_tex);
    eye_down_tex.loadFromFile("sprites/eyes/down.png");
    eye_down_sprite.setTexture(eye_down_tex);
    eye_left_tex.loadFromFile("sprites/eyes/left.png");
    eye_left_sprite.setTexture(eye_left_tex);

    // Bind UI textures
    num_0_tex.loadFromFile("sprites/ui/0.png");
    num_0_sprite.setTexture(num_0_tex);
    num_1_tex.loadFromFile("sprites/ui/1.png");
    num_1_sprite.setTexture(num_1_tex);
    num_2_tex.loadFromFile("sprites/ui/2.png");
    num_2_sprite.setTexture(num_2_tex);
    num_3_tex.loadFromFile("sprites/ui/3.png");
    num_3_sprite.setTexture(num_3_tex);
    num_4_tex.loadFromFile("sprites/ui/4.png");
    num_4_sprite.setTexture(num_4_tex);
    num_5_tex.loadFromFile("sprites/ui/5.png");
    num_5_sprite.setTexture(num_5_tex);
    num_6_tex.loadFromFile("sprites/ui/6.png");
    num_6_sprite.setTexture(num_6_tex);
    num_7_tex.loadFromFile("sprites/ui/7.png");
    num_7_sprite.setTexture(num_7_tex);
    num_8_tex.loadFromFile("sprites/ui/8.png");
    num_8_sprite.setTexture(num_8_tex);
    num_9_tex.loadFromFile("sprites/ui/9.png");
    num_9_sprite.setTexture(num_9_tex);
    score_200_tex.loadFromFile("sprites/ui/200.png");
    score_200_sprite.setTexture(score_200_tex);
    score_400_tex.loadFromFile("sprites/ui/400.png");
    score_400_sprite.setTexture(score_400_tex);
    score_800_tex.loadFromFile("sprites/ui/800.png");
    score_800_sprite.setTexture(score_800_tex);
    score_1600_tex.loadFromFile("sprites/ui/1600.png");
    score_1600_sprite.setTexture(score_1600_tex);
    ready_tex.loadFromFile("sprites/ui/ready.png");
    ready_sprite.setTexture(ready_tex);
    gameover_tex.loadFromFile("sprites/ui/gameover.png");
    gameover_sprite.setTexture(gameover_tex);
    life_tex.loadFromFile("sprites/ui/life.png");
    life_sprite.setTexture(life_tex);
    score_tex.loadFromFile("sprites/ui/score_tex.png");
    score_sprite.setTexture(score_tex);
    high_tex.loadFromFile("sprites/ui/high.png");
    high_sprite.setTexture(high_tex);
    score_100_tex.loadFromFile("sprites/ui/100.png");
    score_100_sprite.setTexture(score_100_tex);
    score_300_tex.loadFromFile("sprites/ui/300.png");
    score_300_sprite.setTexture(score_300_tex);

    // Fruit textures
    cherry_tex.loadFromFile("sprites/fruits/cherry.png");
    cherry_sprite.setTexture(cherry_tex);
    strawberry_tex.loadFromFile("sprites/fruits/strawberry.png");
    strawberry_sprite.setTexture(strawberry_tex);

    // Array de animação do pacman
    pacman_animate[0] = pac_0_sprite;
    pacman_animate[1] = pac_1_sprite;
    pacman_animate[2] = pac_2_sprite;

    red_ghost_animate[0] = ghost_r_0_sprite;
    red_ghost_animate[1] = ghost_r_1_sprite;

    blue_ghost_animate[0] = ghost_b_0_sprite;
    blue_ghost_animate[1] = ghost_b_1_sprite;

    pink_ghost_animate[0] = ghost_p_0_sprite;
    pink_ghost_animate[1] = ghost_p_1_sprite;

    yellow_ghost_animate[0] = ghost_y_0_sprite;
    yellow_ghost_animate[1] = ghost_y_1_sprite;

    
}

__END_API