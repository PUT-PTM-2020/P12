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

#include <fstream>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <vector>

#include <algorithm>
#include <cmath>


//#include "header/joy_stering.h"
//#include <SFML/Joystick.hpp>

using namespace std;

/*
uint16_t ReadU16(istream& file)
{
  uint16_t val;
  char bytes[2];

  file.read( (char*)bytes, 2 );  // read 2 bytes from the file
  val = bytes[0] | (bytes[1] << 8);  // construct the 16-bit value from those bytes

  return val;
}*/

void load_file(array<char, 320 * 120 * 2>  &table){
   ifstream myData("./image.raw", ios::in | ios::binary);
   char bytes[2];

   int i = 0;

   if(!myData){
        cout<<"nie dziala to"<<endl;
    } else {
        // myData.read(value, 8)

        while (myData.read((char*)&bytes, 2))
        {
            table[i] = bytes[0];
            i++;
            table[i] = bytes[1];
            i++;
        }
    }
}

void load_graph(sf::RenderWindow &window){

    //ifstream myData("./image.raw", ios::in | ios::binary);
    array<char, 320 * 120 * 2> file;
    load_file(file);

    char bytes[2];
    uint16_t pixel;
    sf::RectangleShape pixel_rect;
    pixel_rect.setSize(sf::Vector2f(2,2));
    int x=0, y=0;
    std::bitset<16> bit_pix;
    std::bitset<16> bit_pix_reverse;
    std::bitset<5> r;
    std::bitset<6> g;
    std::bitset<5> b;
    //std::string r, g, b;
    uint16_t rgb;
    int r_pix, g_pix, b_pix;
    string str ;

    int wind = 0;


    int while_i = 0;
  
      while (while_i != file.size())
        {
            
            bytes [0] = file[while_i];
            while_i ++;
            bytes [1] = file[while_i];
            while_i ++;
            pixel = bytes[0] | (bytes[1] << 8);
            //pixel << bytes[0];
            //pixel << bytes[1];
            bit_pix = pixel;

            cout<<bit_pix<<" - ";

            for(int i=0; i<16; i++){
              cout<<bit_pix[i];
            }

            cout<<" - "<<pixel<<endl;

            int pix_i = 0; // bitpix [0] = lower bit
            for(int r_i=0; r_i<=4; r_i++, pix_i ++){
              r[r_i] = bit_pix[pix_i];
            }
            r_pix = (int)(r.to_ulong());
            cout<<r<<" = "<<r_pix<<endl;

            for(int r_i=0; r_i<=5; r_i++, pix_i ++){
              g[r_i] = bit_pix[pix_i];
            }
            g_pix = (int)(g.to_ulong());
            cout<<g<<" = "<<g_pix<<endl;

            for(int r_i=0; r_i<=4; r_i++, pix_i ++){
              b[r_i] = bit_pix[pix_i];
              //cout<<b[r_i];
            }
            b_pix = (int)(b.to_ulong());
            cout<<b<<" = "<<b_pix<<endl;

/*
            r_pix = (r_pix * 255) / 31;
            g_pix = (g_pix * 255) / 63;
            b_pix = (b_pix * 255) / 31;
/*
       r_pix = ( r_pix * 527 + 23 ) >> 6;
            g_pix = ( g_pix * 259 + 33 ) >> 6;
            b_pix = ( b_pix * 527 + 23 ) >> 6;

r_pix = (int) floor( r_pix * 255.0 / 31.0 + 0.5);
 g_pix = (int) floor( g_pix * 255.0 / 63.0 + 0.5);
 b_pix = (int) floor( b_pix * 255.0 / 31.0 + 0.5);

*/
            r_pix   = (r_pix   * 255 + 15) / 31;
            g_pix = (g_pix * 255 + 31) / 63;
            b_pix  = (b_pix  * 255 + 15) / 31;



            //cout<<pixel<<" ,";
            //cout<<bit_pix<<" , ";
            cout<<r_pix<<", "<<g_pix<<", "<<b_pix<<endl;

 

            pixel_rect.setFillColor(sf::Color(r_pix, g_pix, b_pix));
            pixel_rect.setPosition(x,y);
            x+=2;

            if(x >= 640){
                x = 0;
                y += 2;
            }
            window.draw(pixel_rect);


        }
    
    cout<<"END"<<endl;
}


int main(){


    //fonts end

    sf::Event event;

    // set window begin
    sf::RenderWindow window(sf::VideoMode(1200,730), "Control");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);
    // set window end

    // set show leds begin
    sf::RectangleShape frame;
    frame.setSize(sf::Vector2f(320,240));
    frame.setPosition(0,0);
    frame.setFillColor(sf::Color(29525));




   //uint16_t aa = 26456;
  // std::bitset<16> bbb;
    //string str;
   //str = bbb.to_string<char,string::traits_type,string::allocator_type>();

      //  cout<<"przed "<<bbb<<endl;
        //reverse(str.begin(), str.end() + str.size());
     //   bbb.flip();
     //   cout<<"po"<<bbb<<" , ";


    while(window.isOpen()){

        window.clear(sf::Color::White);
        //window.pollEvent(event);
        //window.draw(frame);
        load_graph(window);

        window.display();

    }

    return 0;
}
