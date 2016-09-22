#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/** Asks the user to enter a number between min and max, inclusive */
int userInput(int min, int max);


/** Asks the user to enter multiple numbers between min and max */
std::vector<int>* userMultiInput(int min, int max);

/** Pauses the program and waits for input */
void pauseProgram();
#endif
