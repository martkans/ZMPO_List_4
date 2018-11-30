//
// Created by martkans on 30.11.18.
//

#include "Tools.h"

int convertStringToInt(string input, bool &error){
    int number;

    istringstream is(input);
    is >> number;
    error = false;
    for (unsigned long i = 0; i < input.length(); ++i) {
        if(!isInRange(input.at(i), ASCII_ZERO_VALUE, ASCII_NINE_VALUE)){
            error = true;
        }
    }
    return number;
}

bool isInRange(int number, int lower_limit, int upper_limit) {
    if(number >= lower_limit && number <= upper_limit){
        return true;
    } else {
        return false;
    }
}

void alert(string message) {
    cout << "\nOperacja zakończona niepowodzeniem!\n"
         << message << "\n";
}

//string trim(string processed_string) {
//    int index_counter = 0;
//    while (index_counter < processed_string.length() && processed_string.at(index_counter) == ' '){
//        index_counter++;
//    }
//    processed_string = processed_string.substr(index_counter, processed_string.length() - index_counter);
//
//    index_counter = processed_string.length() - 1;
//    while (index_counter >= 0 && processed_string.at(index_counter) == ' '){
//        index_counter--;
//    }
//    processed_string = processed_string.substr(0, index_counter + 1);
//
//    return processed_string;
//}