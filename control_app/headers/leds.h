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
#include "./leds.cpp"

void create_led_letter(int leds_on);
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
    );