########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 2
# Filename: Makefile
#
#######################################################
msh: main.o FileFunctions.o
	g++ -o msh main.o FileFunctions.o; rm *.o
functions.o: FileFunctions.cpp main.h
	g++ -Wall -c FileFunctions.cpp
main.o: main.cpp main.h
	g++ -Wall -c main.cpp
####################[ EOF: Makefile ]##################