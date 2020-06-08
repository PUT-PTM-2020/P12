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

#include "./global.cpp"
using namespace std;

bool polaczenie = false;
sf::TcpSocket socket;

//color defines begin
sf::Color led_grey(61,61,61);
sf::Color led_yellow(250,250,0);
sf::Color led_red(255,0,0);
sf::Color joy_pad_grey(160,160,160);
sf::Color bar_1_col(0,188,53);
sf::Color bar_2_col(242,201,0);
sf::Color bar_3_col(0,143,232);
//color defines end

struct bind_arg_wind{
    sf::Event event;
    sf::RenderWindow window;
};

// frame graphics
//array<char, 320 * 120 * 2> frame;
char frame[320 * 120 * 2];
array<sf::RectangleShape, 320 * 120> frame_graph;
