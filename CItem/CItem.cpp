//
// Created by martkans on 30.11.18.
//

#include "CItem.h"


CItem::CItem(int value, int size) {
    this->size = size;
    this->value = value;
}

bool CItem::isValid() {
    if(value < 1){
        alert("Wartość przedmiotu nie może być mniejsza niż 1!\n");
        return false;
    } else if(size < 1){
        alert("Rozmiar przedmiotu nie może być mniejszy niż 1!\n");
        return false;
    }
    return true;
}
