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
