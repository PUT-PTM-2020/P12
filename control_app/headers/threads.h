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
#include "./threads.cpp"
#include "./draw_graph.h"
#include "./listener.h"


//void ster_app_thread(sf::RenderWindow &window, sf::Event &event);
void ster_app_thread();

void graph_thread();
