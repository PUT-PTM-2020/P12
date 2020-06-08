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
#include <algorithm>
#include <cmath>

#include "./global.h"
#include "./draw_graph.cpp"

//void load_file(char &table[320 * 120 * 2]);
void load_graph(char frame[320 * 120 * 2]);
