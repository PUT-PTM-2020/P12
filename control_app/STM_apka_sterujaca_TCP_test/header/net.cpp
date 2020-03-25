#pragma once
#include "net.h"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
sf::UdpSocket socket_udp;

using namespace std;



void connection() {

	if (socket_udp.bind(50100) != sf::Socket::Done) {
		cout << "Blad socketu" << endl;
	}
	else {
		cout << "Socket pomyslnie zainicjowany" << endl;
	}

}

string create_pack_motor_drive(string dir_left, string dir_right, string pow_left, string pow_right){

	string letter="";

	letter += "op_type:0;";
	letter += "dir_left:"+dir_left+";";
	letter += "dir_right:"+dir_right+";";
	letter += "pow_left:"+pow_left+";";
	letter += "pow_right:"+pow_right+";";

	return letter;

}

void send(string letter){

	sf::IpAddress recipient = "192.168.4.1";
	unsigned short port = 50100;
	

	if (socket_udp.send(letter.c_str(), letter.length(), recipient, port) != sf::Socket::Done) {
		cout << "Blad przesylu wiadomosci" << endl;
	}
	else {
		cout << "Wiadomosc wyslano" << endl;
	}

}

void net_stering(){

	string letter;
	letter=create_pack_motor_drive("DL","DR","PL","PR");
	send(letter);
	
}