#include <iostream>
#include <string>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
//#include "./header/joy_stering.h"
//#include "./header/net.h"
#include <array>
#include <vector>
//#include <linux/joystick.h>
//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

using namespace std;


int main(){

    cout<<"TCP"<<endl;
    sf::TcpSocket socket;

    sf::Socket::Status status;

    while(true){
        cout<<"while"<<endl;
        if(status == sf::Socket::Done){
            break;
        } else {
            cout<<"brak połączenia - próba" <<endl;
        }

        sf::sleep(sf::seconds(2));
        status=socket.connect("192.168.4.1", 50100);
    }


    if(status != sf::Socket::Done){

        cout<<"nie nawiązano połączenia"<<endl;
    } else {
        cout <<"nawiązano połączenie"<<endl;
        char data[100] = {'a','b','c'};

        while(true){

            if(socket.send(data,100) != sf::Socket::Done){
                cout<<"błąd wysłania"<<endl;
            } else {
                cout<<"wysłano!"<<endl;
            }


        }
    }

   




    return 0;
}
