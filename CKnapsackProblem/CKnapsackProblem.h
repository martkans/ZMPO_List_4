//
// Created by martkans on 29.11.18.
//

#ifndef LISTA4_CKNAPSACKPROBLEM_H
#define LISTA4_CKNAPSACKPROBLEM_H


#include "../CItem/CItem.h"
#include "../Tools/Tools.h"

#include <vector>
#include <string>

using namespace std;

class CKnapsackProblem {
    public:
        friend class CGeneticAlgorithm;

        CKnapsackProblem(int knapsack_capacity, int number_of_items, vector <CItem*> &items);
        ~CKnapsackProblem();

        bool isValidData();
        int calculateValueOfGenotype(vector <int> &genotype);

    private:

        int knapsack_capacity;
        int number_of_items;

        vector <CItem*> items;
};


#endif //LISTA4_CKNAPSACKPROBLEM_H
