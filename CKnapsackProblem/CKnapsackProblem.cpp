//
// Created by martkans on 29.11.18.
//


#include <iostream>
#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem(int knapsack_capacity, int number_of_items, vector <CItem*> &items) {
    this->knapsack_capacity = knapsack_capacity;
    this->number_of_items = number_of_items;
    this->items = items;
}

CKnapsackProblem::~CKnapsackProblem() {
    for (int i = 0; i < items.size(); ++i) {
        delete items.at(i);
    }
}

bool CKnapsackProblem::isValidData() {
    cout << "Walidacja danych problemu...\n";
    if(knapsack_capacity < MIN_KNAPSACK_CAPACITY){
        alert("Pojemność plecaka musi wynosić co najmniej " + convertIntToString(MIN_KNAPSACK_CAPACITY) + "!\n");
        return false;
    } else if(number_of_items != items.size()){
        alert("Zadeklarowana ilość rzeczy nie zgadza się z faktyczną!\n");
        return false;
    } else {
        for (int i = 0; i < number_of_items; ++i) {
            if(!items.at(i)->isValid()){
                return false;
            }
        }
    }
    cout << "Walidacja zakończona powodzeniem!\n\n";
    return true;
}

int CKnapsackProblem::calculateValueOfGenotype(vector<int> &genotype) {
    int genotype_score = 0;
    int genotype_size = 0;

    for (int i = 0; i < number_of_items; ++i) {
        genotype_score += genotype.at(i) * items.at(i)->value;
        genotype_size += genotype.at(i) * items.at(i)->size;
    }

    if(genotype_size > knapsack_capacity){
        genotype_score = 0;
    }

    return genotype_score;
}


