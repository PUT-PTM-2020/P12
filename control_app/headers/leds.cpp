#pragma once
// headers for all files
#include <iostream>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <array>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>

#include "./global.h"

void create_led_letter(int leds_on){

    
    char led_stat;
    led_stat = leds_on + 48;


    char data[100]={'1',',',led_stat,';'};

    if(socket.send(data,100) != sf::Socket::Done){
        cout<<"błąd wysłania"<<endl;
    } else {
        //cout<<"wysłano!"<<endl;
    } 
}

void change_led_state(
    int led_stat, 
    sf::CircleShape &led_f_1_l, 
    sf::CircleShape &led_f_1_r,
    sf::CircleShape &led_f_2_l,
    sf::CircleShape &led_f_2_r,
    sf::CircleShape &led_f_3_l,
    sf::CircleShape &led_f_3_r,
    sf::CircleShape &led_f_4_l,
    sf::CircleShape &led_f_4_r,
    sf::CircleShape &led_b_1_l,
    sf::CircleShape &led_b_1_r,
    sf::CircleShape &led_b_2_l,
    sf::CircleShape &led_b_2_r
    ){


    switch (led_stat)
    {
    case 0:
        // back
        led_b_1_l.setFillColor(led_grey);
        led_b_1_r.setFillColor(led_grey);
        led_b_2_l.setFillColor(led_grey);
        led_b_2_r.setFillColor(led_grey);

        //front
        led_f_1_l.setFillColor(led_grey);
        led_f_1_r.setFillColor(led_grey);
        led_f_2_l.setFillColor(led_grey);
        led_f_2_r.setFillColor(led_grey);
        led_f_3_l.setFillColor(led_grey);
        led_f_3_r.setFillColor(led_grey);
        led_f_4_l.setFillColor(led_grey);
        led_f_4_r.setFillColor(led_grey);

        break;

    case 1:
        // back
        led_b_1_l.setFillColor(led_red);
        led_b_1_r.setFillColor(led_red);
        led_b_2_l.setFillColor(led_red);
        led_b_2_r.setFillColor(led_red);

        //front
        led_f_1_l.setFillColor(led_yellow);
        led_f_1_r.setFillColor(led_yellow);
        led_f_2_l.setFillColor(led_grey);
        led_f_2_r.setFillColor(led_grey);
        led_f_3_l.setFillColor(led_grey);
        led_f_3_r.setFillColor(led_grey);
        led_f_4_l.setFillColor(led_grey);
        led_f_4_r.setFillColor(led_grey);

        break;

    case 2:
        // back
        led_b_1_l.setFillColor(led_red);
        led_b_1_r.setFillColor(led_red);
        led_b_2_l.setFillColor(led_red);
        led_b_2_r.setFillColor(led_red);

        //front
        led_f_1_l.setFillColor(led_yellow);
        led_f_1_r.setFillColor(led_yellow);
        led_f_2_l.setFillColor(led_yellow);
        led_f_2_r.setFillColor(led_yellow);
        led_f_3_l.setFillColor(led_grey);
        led_f_3_r.setFillColor(led_grey);
        led_f_4_l.setFillColor(led_grey);
        led_f_4_r.setFillColor(led_grey);

        break;

    case 3:
        // back
        led_b_1_l.setFillColor(led_red);
        led_b_1_r.setFillColor(led_red);
        led_b_2_l.setFillColor(led_red);
        led_b_2_r.setFillColor(led_red);

        //front
        led_f_1_l.setFillColor(led_yellow);
        led_f_1_r.setFillColor(led_yellow);
        led_f_2_l.setFillColor(led_yellow);
        led_f_2_r.setFillColor(led_yellow);
        led_f_3_l.setFillColor(led_yellow);
        led_f_3_r.setFillColor(led_yellow);
        led_f_4_l.setFillColor(led_grey);
        led_f_4_r.setFillColor(led_grey);

        break;

    case 4:
        // back
        led_b_1_l.setFillColor(led_red);
        led_b_1_r.setFillColor(led_red);
        led_b_2_l.setFillColor(led_red);
        led_b_2_r.setFillColor(led_red);

        //front
        led_f_1_l.setFillColor(led_yellow);
        led_f_1_r.setFillColor(led_yellow);
        led_f_2_l.setFillColor(led_yellow);
        led_f_2_r.setFillColor(led_yellow);
        led_f_3_l.setFillColor(led_yellow);
        led_f_3_r.setFillColor(led_yellow);
        led_f_4_l.setFillColor(led_yellow);
        led_f_4_r.setFillColor(led_yellow);

        break;
    default:

        break;
    }
    
}