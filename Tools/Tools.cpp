//
// Created by martkans on 30.11.18.
//

#include "Tools.h"

void alert(string message) {
    cout << "\nOperacja zakończona niepowodzeniem!\n"
         << message << "\n";
}

string convertIntVectorToString(vector<int> &converted_vector) {
    string temp = "";
    for (int i = 0; i < converted_vector.size(); ++i) {
        temp += convertIntToString(converted_vector.at(i));
    }

    return temp;
}

string convertIntToString(int number){
    stringstream ss;
    ss << number;
    return ss.str();
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