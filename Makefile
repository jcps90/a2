########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 2
# Filename: Makefile
#
#######################################################
msh: main.o FileHandler.o
	g++ -o msh main.o FileHandler.o; rm *.o
functions.o: FileHandler.cpp main.h
	g++ -Wall -c FileHandler.cpp
main.o: main.cpp main.h
	g++ -Wall -c main.cpp
####################[ EOF: Makefile ]##################