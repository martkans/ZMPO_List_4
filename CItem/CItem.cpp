//
// Created by martkans on 30.11.18.
//

#include "CItem.h"


CItem::CItem(int value, int size) {
    this->size = size;
    this->value = value;
}

bool CItem::isValid() {
    if(value < MIN_ITEM_VALUE){
        alert("Wartość przedmiotu nie może być mniejsza niż " + convertIntToString(MIN_ITEM_VALUE) + "!\n");
        return false;
    } else if(size < MIN_ITEM_SIZE){
        alert("Rozmiar przedmiotu nie może być mniejszy niż " + convertIntToString(MIN_ITEM_SIZE) + "!\n");
        return false;
    }
    return true;
}
