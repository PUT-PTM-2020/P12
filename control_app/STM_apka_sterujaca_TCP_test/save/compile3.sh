#!/bin/bash
g++ main_3.cpp -c
g++ ./main_3.o -o control_app3 -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -pthread
./control_app3