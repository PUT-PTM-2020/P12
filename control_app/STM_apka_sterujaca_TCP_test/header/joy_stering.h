#pragma once
#include "joy_stering.cpp"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
using namespace std;

float pos_x;
float pos_y;
float pos_z;
float X_axis=0, Y_axis=0 , Z_axis=0 ;
float pos_stick_x = 0.0;
float pos_stick_y = 0.0;

void joystick_start(sf::Event &event){

    if(sf::Joystick::Axis::X == event.joystickMove.axis){
        pos_x = event.joystickMove.position;
    } else if(sf::Joystick::Axis::Y == event.joystickMove.axis){
        pos_y = event.joystickMove.position;
    } else if(sf::Joystick::Axis::Z == event.joystickMove.axis){
        pos_z = event.joystickMove.position;
    }
   
    X_axis = pos_x * 2;
    Y_axis = pos_y * 2;
    Z_axis = pos_z * 2;


}

void joystick();





