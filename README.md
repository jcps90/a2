README.md
Authors: Juan Pina-Sanz, Mikhail Mineev

Users: cssc2147, cssc2160

Class: CS 570, Summer 2020

Assignment 2

Filename: README

File Manifest: Makefile main.cpp main.h README.md FileHandler.cpp

Compile Instructions: Compile and Run on Class Account cssc2147

Operation Instructions: The MicroShell will output a prompt initially, and despite there not being another one after the first command is entered, it will still accept commands afterwards.

Design Description: Our idea for this Microshell was to divide the user input into arguments that could be passed through to execvp and execlp based on the type of command or path entered. We check the input arguments and verify if there is a pipe or not and call the appropriate function to handle the execution of the command.

Bugs:After the initial input and command execution the username line dissappears, but the user is still able to type in commands as well as exit the microshell.


In the process of making this program we tried out a large number of solutions we believed would work. Unfortunately we wasted a large ammount of time on a solution which did not end up working. Overall all seemed well, however we essentially boxed ourselves in with the way we decided to handle arrays. We did not anticipate using the exec commands, and did not setup our program accordingly. We later realized that this was one of the requirements and instead of attempting to adopt or rather convoluted program we decided to start off from scratch and base our entire program around the exec functions. 
