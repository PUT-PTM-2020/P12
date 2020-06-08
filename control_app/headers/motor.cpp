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

using namespace std;
/*
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
    //cout<<char_dir_left<<" : "<<char_dir_right<<";"<<dir_left<<"- "<<dir_right<<endl;

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

*/
void create_motor_letter(float pos_x, float pos_y){
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

    } else if(pos_x > 0 && pos_y < 0){ //pierwsza ćwiartka

        pos_y *= -1;
        //if(pos_x <= pos_y){
            dir_left = 1;
            dir_right = 1;
            Duty_left = pos_y;
            Duty_right = pos_y - (pos_x / 100 * pos_y) * 0.8;


        cout<<pos_x<<": "<<pos_y<<"- DR: "<<Duty_right<<" - DL"<< Duty_left <<endl;



    } else if(pos_x < 0 && pos_y < 0){ // druga ćwiartka

        pos_y *= -1;
        pos_x *= -1;
       // if(pos_x <= pos_y){
            dir_left = 1;
            dir_right = 1;
            Duty_left = pos_y - (pos_x / 100 * pos_y) * 0.8;
            Duty_right = pos_y;



    } else if(pos_x < 0 && pos_y > 0){ //trzecia ćwiartka
        pos_x *= -1;
        if(pos_x <= pos_y){
            dir_left = 0;
            dir_right = 0;
            Duty_left = pos_y - pos_x * 0.80;
            Duty_right = pos_y;

        } else if(pos_x > pos_y){
            cout<<"warun!"<<endl;
            dir_left = 1;
            dir_right = 0;
            Duty_left = pos_x - pos_y * 0.80;
            Duty_right = pos_x;
        }

        cout<<pos_x<<"- DR: "<<Duty_right<<" - DL"<< Duty_left <<endl;

    } else if(pos_x > 0 && pos_y > 0){ // czwarta ćwiartka

        if(pos_x <= pos_y){
            dir_left = 0;
            dir_right = 0;
            Duty_left = pos_y;
            Duty_right = pos_y - pos_x * 0.80;

        } else if(pos_x > pos_y){
            cout<<"warun!"<<endl;
            dir_left = 0;
            dir_right = 1;
            Duty_left = pos_x;
            Duty_right = pos_x - pos_y * 0.80;
        }
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
