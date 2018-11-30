//
// Created by martkans on 29.11.18.
//

#ifndef LISTA4_CGENETICALGORITHM_H
#define LISTA4_CGENETICALGORITHM_H

#include "../CKnapsackProblem/CKnapsackProblem.h"
#include "../CIndividual/CIndividual.h"


#include <vector>

using namespace std;
class CGeneticAlgorithm {
    public:
        CGeneticAlgorithm(CKnapsackProblem *knapsack_problem, int population_size, int iteration_number,
                          double crossing_possibility, double mutation_possibility);

        ~CGeneticAlgorithm();

        void runAlgorithm();
        CIndividual* getBestSolution();

private:
        CKnapsackProblem* knapsack_problem;

        int population_size;
        int iteration_number;

        double crossing_possibility;
        double mutation_possibility;

        vector <CIndividual*> population;
        vector <CIndividual*> best_individual_in_nth_iteration;
};


#endif //LISTA4_CGENETICALGORITHM_H
