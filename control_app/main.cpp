#include <iostream>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
//#include "SFML/Image.hpp"
//#include <Image.hpp>
#include <array>
#include <vector>
//#include <linux/joystick.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <bitset>

#include "./headers/global.h"
#include "./headers/connection.h"
#include "./headers/motor.h"
#include "./headers/leds.h"
#include "./headers/threads.h"
#include "./headers/draw_graph.h"
#include "./headers/listener.h"


//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

using namespace std;


//color defines end

void camera_view(int cam_i, sf::Sprite &cam, sf::Texture &cam_tex){

    sf::Image cam_img;

    string photo_number;

    photo_number = "";
    photo_number += to_string(cam_i);
    photo_number += ".png";
    photo_number = "1.png"; // do testów
    if(!cam_tex.loadFromFile(photo_number)){
        cout<<"error photo"<<endl;
    }
    //cout << photo_number << ", ";

    cam.setPosition(10,6);
    cam.setTexture(cam_tex, true);

}

int main(){


    //connection(); //connection to STM

    connection(); //connection to STM

    //fonts end


/*    bind_arg_wind bind_arg;

    bind_arg.event = event;
    bind_arg.window = window;*/
    // set window end
    sf::Thread ster_thread(&ster_app_thread);
    ster_thread.launch();
   //ster_app_thread();

    sf::Thread gra_thread(&graph_thread);
    gra_thread.launch();

    // set video end

  /*  while(window.isOpen()){

        window.clear(sf::Color::White);
        //window.pollEvent(event);



        //window led show end

        window.display();

    } */

    return 0;
}
