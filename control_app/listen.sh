#!/bin/bash
g++ listen.cpp -c
g++ ./listen.o -o listen_app -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -pthread
./listen_app
