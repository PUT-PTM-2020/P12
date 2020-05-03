#!/bin/bash
g++ main.cpp -c
g++ ./main.o -o control_app -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -pthread
./control_app
