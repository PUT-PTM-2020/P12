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
