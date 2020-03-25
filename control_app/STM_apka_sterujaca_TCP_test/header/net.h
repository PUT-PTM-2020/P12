#pragma once
#include "net.cpp"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>



void connection();
string create_pack_motor_drive(string dir_left, string dir_right, string pow_left, string pow_right);
void net_stering();
