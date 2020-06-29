########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 2
# Filename: Makefile
#
#######################################################
EXEC = msh
CC=g++
$(EXEC):
	$(CC) -o $(EXEC) main.cpp msh.cpp FileHandler.cpp
	rm -f *.o
clean:
	rm msh
	rm -f *.o $(EXEC)
####################[ EOF: Makefile ]##################