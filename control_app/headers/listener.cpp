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
#include <unistd.h>


#include "./global.h"
#include "./connection.h"


void listener_f(){

    //char buffer[320*120*2];
    //array<char, 320 * 120 * 2> buffer;
		std::size_t received = 0;
		socket.receive(frame, sizeof(frame), received);

		cout<<"server: OK - "<<received<<endl;
	//	load_graph(window, buf);
}
