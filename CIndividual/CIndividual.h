//
// Created by martkans on 29.11.18.
//

#ifndef LISTA4_CINDIVIDUAL_H
#define LISTA4_CINDIVIDUAL_H

#include <vector>
#include "../CKnapsackProblem/CKnapsackProblem.h"

using namespace std;
/*
 * Prawdopodobna modyfikacja - przekształcić genotyp na typ szablonowy*/
class CIndividual {
    public:
        friend class CGeneticAlgorithm;

        CIndividual(CKnapsackProblem *knapsack_problem, vector<int> &genotype);


private:
        CKnapsackProblem* knapsack_problem;
        vector <int> genotype;
        int genotype_score;

        vector <CIndividual*> crossCIndividual(CIndividual* other_object);
        void performMutation();
        void calculateAdaptation();

};


#endif //LISTA4_CINDIVIDUAL_H
