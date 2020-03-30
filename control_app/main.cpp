#include <iostream>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <array>
#include <vector>
//#include <linux/joystick.h>
#include <string>
#include <stdio.h>

//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

using namespace std;

bool polaczenie = false;
sf::TcpSocket socket;



void connection() {

	cout<<"TCP"<<endl;
    
    sf::Socket::Status status=socket.connect("192.168.4.1", 50100);

	if(status != sf::Socket::Done){

        cout<<"nie nawiązano połączenia"<<endl;
    } else {
        cout <<"nawiązano połączenie!"<<endl;
		polaczenie = true;
    }

}

void create_motor_letter(int pos_x, int pos_y){
    int dir_left, dir_right;
    int Duty_left, Duty_right;

    if(pos_x==100){
        pos_x = 99;
    }

    if(pos_x == -100){
        pos_x = -99;
    }

    if(pos_y == 100){
        pos_y = 99;
    }

    if(pos_y == -100){
        pos_y = -99;
    }

    if(pos_x == 0 && pos_y == 0){ // stoi
        dir_left = 2;
        dir_right = 2;
        Duty_left = 0;
        Duty_right = 0;

    }else if(pos_x == 0 && pos_y < 0){ // prosto przód
        dir_left = 1;
        dir_right = 1;
        pos_y *= -1;
        Duty_left = pos_y; 
        Duty_right = pos_y;
    } else if(pos_x == 0 && pos_y > 0){ // prosto tył
        dir_left = 0;
        dir_right = 0;
        Duty_left = pos_y; 
        Duty_right = pos_y;
    } else if(pos_x > 0 && pos_y == 0){ // prawo w miejscu
        dir_left = 1;
        dir_right = 0;
        Duty_left = pos_x; 
        Duty_right = pos_x;
    } else if(pos_x < 0 && pos_y == 0){ // lewo w miejscu
        dir_left = 0;
        dir_right = 1;
        pos_x *= -1;
        Duty_left = pos_x; 
        Duty_right = pos_x;
    } if(pos_x > 0 && pos_y < 0){
        
        
        //pos_y *= -1;
       // Duty_left = 100 - pos_y; 
    }

    char char_dir_left = dir_left + 48;
    char char_dir_right = dir_right + 48;
    cout<<char_dir_left<<" : "<<char_dir_right<<";"<<dir_left<<"- "<<dir_right<<endl;

    string s_Duty_left = to_string(Duty_left);
    string s_Duty_right = to_string(Duty_right);

    if(Duty_left < 10){
        s_Duty_left = "00";    
    }

    if(Duty_right < 10){
        s_Duty_right = "00";
    }


    char data[100]={'0',',',char_dir_left,',',char_dir_right,',',s_Duty_left[0],s_Duty_left[1],',',s_Duty_right[0],s_Duty_right[1],';'};

    if(socket.send(data,100) != sf::Socket::Done){
        cout<<"błąd wysłania"<<endl;
    } else {
        //cout<<"wysłano!"<<endl;
    }



}



int main(){


    connection();
    float pos_x;
    float pos_y;
    float pos_z;

    sf::RectangleShape X_bar;
    sf::RectangleShape Y_bar;
    sf::RectangleShape Z_bar;
    float X_axis =0, Y_axis=0 , Z_axis=0 ;

    sf::RectangleShape joy_position;

    sf::RectangleShape joy_stick_pos;
    float pos_stick_x = 0.0;
    float pos_stick_y = 0.0;

    sf::Event event;


    sf::RenderWindow window(sf::VideoMode(1200,800), "Control");


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

    X_axis = pos_x * 2;
    Y_axis = pos_y * 2;
    Z_axis = pos_z * 2;

    joy_position.setSize(sf::Vector2f(400,400));
    joy_position.setPosition(700, 350);
    joy_position.setOrigin(sf::Vector2f(200,200));
    joy_position.setFillColor(sf::Color::Blue);
    joy_position.setOutlineColor(sf::Color::Green);
    window.draw(joy_position);


    joy_stick_pos.setSize(sf::Vector2f(10,10));
    joy_stick_pos.setPosition(700, 350);
    joy_stick_pos.setOrigin(sf::Vector2f(5,5));
    joy_stick_pos.setFillColor(sf::Color::Red);
    joy_stick_pos.setOutlineColor(sf::Color::Green);

    window.draw(joy_stick_pos);

    window.draw(X_bar);
    window.draw(Y_bar);
    window.draw(Z_bar);

   // sf::Thread send_motor_f(&create_motor_letter, pos_x, pos_y);
   // send_motor_f.launch();

    while( window.isOpen()){


        while (window.pollEvent(event))
        {
            window.clear(sf::Color::Black);
            window.pollEvent(event);
            
              switch(event.type){

                case sf::Event::EventType::Closed:
                    window.close();
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
                    //cout<<"Joy - move"<<endl;
                    
                    //cout<<event.joystickMove.position<<endl;
        
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

                    pos_stick_x = pos_x * 2 + 700;
                    pos_stick_y = pos_y * 2 + 350;

                    X_bar.setSize(sf::Vector2f(30, X_axis));
                    Y_bar.setSize(sf::Vector2f(30, Y_axis));
                    Z_bar.setSize(sf::Vector2f(30, Z_axis));
                    //cout<<pos_x<<endl;
                    //cout<<"s_X "<<pos_stick_x<<"s_Y "<<pos_stick_y<<endl;
                    joy_stick_pos.setPosition(sf::Vector2f(pos_stick_x, pos_stick_y));
                    create_motor_letter(pos_x,pos_y);
                    break;

            }
            
            //joy_stick_pos.setPosition(sf::Vector2f(pos_stick_x, pos_stick_y));


          
        window.draw(joy_position);
        window.draw(joy_stick_pos);
        window.draw(X_bar);
        window.draw(Y_bar);
        window.draw(Z_bar);
        window.display();
            
            
        }

      
       //  window.clear();
    }

    return 0;
}