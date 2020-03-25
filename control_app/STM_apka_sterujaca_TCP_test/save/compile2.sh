#!/bin/bash
g++ main_2.cpp -c
g++ ./main_2.o -o control_app2 -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -pthread
./control_app2