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


//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

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

    int led_state = 4; // status oświetlenia pojazdu;
    

    //fonts begin
    sf::Font font_bar;

    if(!font_bar.loadFromFile("arial.ttf")){
        cout<<"font loading error!"<<endl;
    }


    //fonts end

    sf::Event event;

    // set window begin
    sf::RenderWindow window(sf::VideoMode(1200,730), "Control");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    // set window end

    // set show leds begin
    sf::Sprite leds_rect;
    sf::Texture leds_rect_tex;

    if(!leds_rect_tex.loadFromFile("pogladowy.png")){
        cout<<"error photo"<<endl;
    }

    leds_rect.setOrigin(200,150);
    leds_rect.setPosition(920, 570);
    leds_rect.setTexture(leds_rect_tex, true);

    // set led front - circle begin

    sf::CircleShape led_front_1_l;
    sf::CircleShape led_front_1_r;
    sf::CircleShape led_front_2_l;
    sf::CircleShape led_front_2_r;
    sf::CircleShape led_front_3_l;
    sf::CircleShape led_front_3_r;
    sf::CircleShape led_front_4_l;
    sf::CircleShape led_front_4_r;

    led_front_4_r.setRadius(7.5);
    led_front_4_r.setFillColor(led_yellow);
    led_front_4_r.setOrigin(5,5);
    led_front_4_r.setPosition(760,470);

    led_front_4_l.setRadius(7.5);
    led_front_4_l.setFillColor(led_yellow);
    led_front_4_l.setOrigin(5,5);
    led_front_4_l.setPosition(760,665);

    led_front_3_r.setRadius(7.5);
    led_front_3_r.setFillColor(led_yellow);
    led_front_3_r.setOrigin(5,5);
    led_front_3_r.setPosition(760,490);

    led_front_3_l.setRadius(7.5);
    led_front_3_l.setFillColor(led_yellow);
    led_front_3_l.setOrigin(5,5);
    led_front_3_l.setPosition(760,645);

    led_front_2_r.setRadius(7.5);
    led_front_2_r.setFillColor(led_yellow);
    led_front_2_r.setOrigin(5,5);
    led_front_2_r.setPosition(760,510);

    led_front_2_l.setRadius(7.5);
    led_front_2_l.setFillColor(led_yellow);
    led_front_2_l.setOrigin(5,5);
    led_front_2_l.setPosition(760,625);

    led_front_1_r.setRadius(7.5);
    led_front_1_r.setFillColor(led_yellow);
    led_front_1_r.setOrigin(5,5);
    led_front_1_r.setPosition(760,530);

    led_front_1_l.setRadius(7.5);
    led_front_1_l.setFillColor(led_yellow);
    led_front_1_l.setOrigin(5,5);
    led_front_1_l.setPosition(760,605);

    // set led front - cirlce end

    // set led back begin

    sf::CircleShape led_back_1_l;
    sf::CircleShape led_back_1_r;
    sf::CircleShape led_back_2_l;
    sf::CircleShape led_back_2_r;

    led_back_2_r.setRadius(7.5);
    led_back_2_r.setFillColor(led_red);
    led_back_2_r.setOrigin(5,5);
    led_back_2_r.setPosition(1093,470);

    led_back_2_l.setRadius(7.5);
    led_back_2_l.setFillColor(led_red);
    led_back_2_l.setOrigin(5,5);
    led_back_2_l.setPosition(1093,665);

    led_back_1_r.setRadius(7.5);
    led_back_1_r.setFillColor(led_red);
    led_back_1_r.setOrigin(5,5);
    led_back_1_r.setPosition(1093,490);

    led_back_1_l.setRadius(7.5);
    led_back_1_l.setFillColor(led_red);
    led_back_1_l.setOrigin(5,5);
    led_back_1_l.setPosition(1093,645);


    // set led back end

    // set show leds end

    // set bars begin

    //set bar text begin

    sf::Text bar_1_txt("X:", font_bar);
    sf::Text bar_2_txt("Y:", font_bar);
    sf::Text bar_3_txt("Z:", font_bar);

    bar_1_txt.setCharacterSize(23);
    bar_1_txt.setStyle(sf::Text::Bold);
    bar_1_txt.setFillColor(sf::Color::Black);
    bar_1_txt.setPosition(90,517.5);
    bar_1_txt.setOrigin(5,5);

    bar_2_txt.setCharacterSize(23);
    bar_2_txt.setStyle(sf::Text::Bold);
    bar_2_txt.setFillColor(sf::Color::Black);
    bar_2_txt.setPosition(90,567.5);
    bar_2_txt.setOrigin(5,5);

    bar_3_txt.setCharacterSize(23);
    bar_3_txt.setStyle(sf::Text::Bold);
    bar_3_txt.setFillColor(sf::Color::Black);
    bar_3_txt.setPosition(90,617.5);
    bar_3_txt.setOrigin(5,5);


    //set bar tet end

    sf::RectangleShape joy_position;
    sf::CircleShape joy_stick_pos;
    float pos_stick_x = 0.0;
    float pos_stick_y = 0.0;

    float pos_x;
    float pos_y;
    float pos_z;

    sf::RectangleShape X_bar;
    sf::RectangleShape Y_bar;
    sf::RectangleShape Z_bar;
    float X_axis =0, Y_axis=0 , Z_axis=0 ;

    X_bar.setSize(sf::Vector2f(X_axis,20));
    X_bar.setPosition(330,520);
    X_bar.setFillColor(bar_1_col);
    X_bar.setOutlineThickness(3);
    X_bar.setOutlineColor(sf::Color::Red);

    Y_bar.setSize(sf::Vector2f(Y_axis, 20));
    Y_bar.setPosition(330,570);
    Y_bar.setFillColor(bar_2_col);
    Y_bar.setOutlineThickness(3);
    Y_bar.setOutlineColor(sf::Color::Red);

    Z_bar.setSize(sf::Vector2f(Z_axis, 20));
    Z_bar.setPosition(330,620);
    Z_bar.setFillColor(bar_3_col);
    Z_bar.setOutlineThickness(3);
    Z_bar.setOutlineColor(sf::Color::Red);

    //window.draw(X_bar);
    //window.draw(Y_bar);
    //window.draw(Z_bar);

    X_axis = pos_x * 2;
    Y_axis = pos_y * 2;
    Z_axis = pos_z * 2;

    joy_position.setSize(sf::Vector2f(400,400));
    joy_position.setOrigin(sf::Vector2f(200,200));
    joy_position.setPosition(920, 210);
    joy_position.setOutlineThickness(4);
    joy_position.setFillColor(joy_pad_grey);
    joy_position.setOutlineColor(sf::Color::Black);

    //joy_stick_pos.setSize(sf::Vector2f(10,10));
    joy_stick_pos.setRadius(10);
    joy_stick_pos.setPosition(920, 210);
    joy_stick_pos.setOrigin(sf::Vector2f(10,10));
    joy_stick_pos.setFillColor(sf::Color::Yellow);
    joy_stick_pos.setOutlineColor(sf::Color::Green);

    window.draw(joy_position);
    window.draw(joy_stick_pos);
    window.draw(X_bar);
    window.draw(Y_bar);
    window.draw(Z_bar);

    // lines begin
    sf::RectangleShape V_lines;
    sf::RectangleShape H_lines;

    V_lines.setFillColor(sf::Color::Black);
    V_lines.setSize(sf::Vector2f(400,4));
    V_lines.setPosition(720,208);

    H_lines.setFillColor(sf::Color::Black);
    H_lines.setSize(sf::Vector2f(4,400));
    H_lines.setPosition(918,10);

    // lines end

    // set bars end

    // set video begin
    sf::Sprite cam;
    sf::Texture cam_tex;
    int cam_i = 1, cam_j=0;
    //sf::Thread thread_cam(&camera_view, cam_i, cam, cam_tex);

    // set video end

    while(window.isOpen()){

        window.clear(sf::Color::White);
        //window.pollEvent(event);

        if(cam_i > 10){
            cam_i = 1;
        }

        if(cam_j >= 1){
          // thread_cam.launch();
           //thread_cam.terminate();
            camera_view(cam_i, cam, cam_tex); // funkcja odpowiedzialna za wyświetlenie obrazu
            cam_i++;
            cam_j = 0;
        }
        cam_j ++;
            
        while (window.pollEvent(event))
        {         
            //window.pollEvent(event);

            switch(event.type){

                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::EventType::JoystickButtonPressed:
                    cout<< "JOY! pressed"<<endl;
                    cout<<"ID"<<event.joystickButton.joystickId<<" Button: "<< event.joystickButton.button<<endl;

                    if(event.joystickButton.button == 3 && led_state < 4){
                        led_state ++;
                        cout<<"led +  : "<<led_state<<endl;
                        create_led_letter(led_state);

                        change_led_state(led_state, 
                                        led_front_1_l, 
                                        led_front_1_r, 
                                        led_front_2_l,
                                        led_front_2_r,
                                        led_front_3_l, 
                                        led_front_3_r, 
                                        led_front_4_l, 
                                        led_front_4_r, 
                                        led_back_1_l, 
                                        led_back_1_r, 
                                        led_back_2_l, 
                                        led_back_2_r);


                    } else if(event.joystickButton.button == 2 && led_state > 0){
                        led_state --;
                        cout<<"led -  : "<<led_state<<endl;
                        create_led_letter(led_state);

                        change_led_state(led_state, 
                                        led_front_1_l, 
                                        led_front_1_r, 
                                        led_front_2_l,
                                        led_front_2_r,
                                        led_front_3_l, 
                                        led_front_3_r, 
                                        led_front_4_l, 
                                        led_front_4_r, 
                                        led_back_1_l, 
                                        led_back_1_r, 
                                        led_back_2_l, 
                                        led_back_2_r);

                    }


                    // change led on view

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

                    pos_stick_x = pos_x * 2 + 920;
                    pos_stick_y = pos_y * 2 + 210;

                    X_bar.setSize(sf::Vector2f(X_axis, 20));
                    Y_bar.setSize(sf::Vector2f(-Y_axis, 20));
                    Z_bar.setSize(sf::Vector2f(-Z_axis, 20));
                    //cout<<pos_x<<endl;
                    //cout<<"s_X "<<pos_stick_x<<"s_Y "<<pos_stick_y<<endl;
                    joy_stick_pos.setPosition(sf::Vector2f(pos_stick_x, pos_stick_y));
                    create_motor_letter(pos_x,pos_y);
                    break;

            }   
            
        }




        window.draw(joy_position);
        window.draw(V_lines);
        window.draw(H_lines);
        window.draw(joy_stick_pos);

        window.draw(X_bar);
        window.draw(Y_bar);
        window.draw(Z_bar);

        window.draw(leds_rect);

        window.draw(cam);

        //window led show begin
        window.draw(led_front_4_l);
        window.draw(led_front_4_r);
        window.draw(led_front_3_l);
        window.draw(led_front_3_r);
        window.draw(led_front_2_l);
        window.draw(led_front_2_r);
        window.draw(led_front_1_l);
        window.draw(led_front_1_r);

        window.draw(led_back_2_r);
        window.draw(led_back_2_l);
        window.draw(led_back_1_r);
        window.draw(led_back_1_l);

        window.draw(bar_1_txt);
        window.draw(bar_2_txt);
        window.draw(bar_3_txt);
        
        //window led show end

        window.display();

    }

    return 0;
}