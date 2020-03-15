#include <iostream>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <array>
#include <vector>
#include <linux/joystick.h>
//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

using namespace std;

int main(){

    sf::RenderWindow window(sf::VideoMode(1200,800), "Control");
    float pos_x;
    float pos_y;
    float pos_z;

    sf::RectangleShape X_bar;
    sf::RectangleShape Y_bar;
    sf::RectangleShape Z_bar;
    float X_axis =0, Y_axis=0 , Z_axis=0 ;


    X_bar.setSize(sf::Vector2f(30, X_axis));
    X_bar.setPosition(20,300);
    X_bar.setFillColor(sf::Color::Green);
    X_bar.setOutlineColor(sf::Color::Red);

    Y_bar.setSize(sf::Vector2f(30, Y_axis));
    Y_bar.setPosition(70,300);
    Y_bar.setFillColor(sf::Color::White);
    Y_bar.setOutlineColor(sf::Color::Red);

    Z_bar.setSize(sf::Vector2f(30, Z_axis));
    Z_bar.setPosition(140,300);
    Z_bar.setFillColor(sf::Color::Yellow);
    Z_bar.setOutlineColor(sf::Color::Red);

    //window.draw(X_bar);
    //window.draw(Y_bar);
    //window.draw(Z_bar);


    sf::RectangleShape joy_position;

    joy_position.setSize(sf::Vector2f(400,400));
    joy_position.setPosition(700, 350);
    joy_position.setOrigin(sf::Vector2f(200,200));
    joy_position.setFillColor(sf::Color::Blue);
    joy_position.setOutlineColor(sf::Color::Green);
    window.draw(joy_position);

    sf::RectangleShape joy_stick_pos;
    float pos_stick_x = 0.0;
    float pos_stick_y = 0.0;

    joy_stick_pos.setSize(sf::Vector2f(10,10));
    joy_stick_pos.setPosition(700, 350);
    joy_stick_pos.setOrigin(sf::Vector2f(5,5));
    joy_stick_pos.setFillColor(sf::Color::Red);
    joy_stick_pos.setOutlineColor(sf::Color::Green);
    window.draw(joy_stick_pos);

    sf::Event event;

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

    window.draw(X_bar);
    window.draw(Y_bar);
    window.draw(Z_bar);


    while( window.isOpen()){


        while (window.pollEvent(event))
        {
            window.clear(sf::Color::Black);
            window.pollEvent(event);
            
            switch(event.type){

                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::EventType::TextEntered:
                    if(event.text.unicode < 128){
                        cout<<event.text.unicode << endl;
                    }
                    break;
                case sf::Event::EventType::KeyPressed:
                    cout<<"Key pressed"<<endl;
                    break;
                case sf::Event::EventType::JoystickButtonPressed:
                    cout<< "JOY! pressed"<<endl;
                    cout<<"ID"<<event.joystickButton.joystickId<<"Button: "<< event.joystickButton.button<<endl;
                    break;
                case sf::Event::EventType::JoystickButtonReleased:
                    cout<< "JOY! Relased"<<endl;
                    cout<<"ID"<<event.joystickButton.joystickId<<"Button: "<< event.joystickButton.button<<endl;
                    break;
                case sf::Event::EventType::JoystickMoved:
                    cout<<"Joy - move"<<endl;
                    
                    //cout<<event.joystickMove.position<<endl;
        
                    if(sf::Joystick::Axis::X == event.joystickMove.axis){
                        pos_x = event.joystickMove.position;
                    } else if(sf::Joystick::Axis::Y == event.joystickMove.axis){
                        pos_y = event.joystickMove.position;
                    } else if(sf::Joystick::Axis::Z == event.joystickMove.axis){
                        pos_z = event.joystickMove.position;
                    }

                    cout<<"JS0: x: "<<pos_x<<", y: "<<pos_y<<", z: "<<pos_z<<endl;
                    break;

            }
            X_axis = pos_x * 2;
            Y_axis = pos_y * 2;
            Z_axis = pos_z * 2;

            pos_stick_x = pos_x * 2 + 700;
            pos_stick_y = pos_y * 2 + 350;

            X_bar.setSize(sf::Vector2f(30, X_axis));
            Y_bar.setSize(sf::Vector2f(30, Y_axis));
            Z_bar.setSize(sf::Vector2f(30, Z_axis));
            cout<<"s_X"<<pos_stick_x<<" s_Y"<<pos_stick_y<<endl;
            joy_stick_pos.setPosition(sf::Vector2f(pos_stick_x, pos_stick_y));


            window.clear();
            window.draw(joy_position);
            window.draw(joy_stick_pos);
            window.draw(X_bar);
            window.draw(Y_bar);
            window.draw(Z_bar);
            window.display();
        }
       


       
        window.display();
       //  window.clear();
    }

    return 0;
}
