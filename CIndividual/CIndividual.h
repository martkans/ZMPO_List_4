//
// Created by martkans on 29.11.18.
//

#ifndef LISTA4_CINDIVIDUAL_H
#define LISTA4_CINDIVIDUAL_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../CKnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CIndividual {
    public:
        friend class CGeneticAlgorithm;
        CIndividual(CKnapsackProblem *knapsack_problem, vector<int> genotype, double &mutation_possibility);
        CIndividual(CIndividual &other_object);


private:
        CKnapsackProblem* knapsack_problem;
        vector <int> genotype;
        int fitness;
        double mutation_possibility;


        vector <CIndividual*> crossCIndividual(CIndividual* other_object);
        void performMutation();
        void calculateFitness();

};


#endif //LISTA4_CINDIVIDUAL_H
