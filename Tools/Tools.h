//
// Created by martkans on 30.11.18.
//

#ifndef LISTA4_TOOLS_H
#define LISTA4_TOOLS_H

#define ASCII_ZERO_VALUE 47
#define ASCII_NINE_VALUE 58


#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int convertStringToInt(string input, bool   &error);

bool isInRange(int number, int lower_limit, int upper_limit);

void alert(string message);

//string trim(string processed_string);


#endif //LISTA4_TOOLS_H
