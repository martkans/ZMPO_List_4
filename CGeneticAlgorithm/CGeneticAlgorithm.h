//
// Created by martkans on 29.11.18.
//

#ifndef LISTA4_CGENETICALGORITHM_H
#define LISTA4_CGENETICALGORITHM_H

#include "../CKnapsackProblem/CKnapsackProblem.h"
#include "../CIndividual/CIndividual.h"


#include <vector>
#include <cstdlib>
#include <ctime>

#define MIN_POPULATION_SIZE     2
#define MIN_ITERATION_NUMBER    1

#define MIN_CROSSING_PROBABILITY    0
#define MAX_CROSSING_PROBABILITY    1

#define MIN_MUTATION_PROBABILITY    0
#define MAX_MUTATION_PROBABILITY    1


using namespace std;
class CGeneticAlgorithm {
    public:
        CGeneticAlgorithm(CKnapsackProblem *knapsack_problem, int population_size, int iteration_number,
                          double crossing_possibility, double mutation_possibility);

        ~CGeneticAlgorithm();

        void runAlgorithm();
        void showResults();

        CIndividual* getBestSolution();


private:
        CKnapsackProblem* knapsack_problem;

        bool valid_knapsack_problem;
        bool valid_genetic_algorithm;

        int population_size;
        int iteration_number;

        double crossing_possibility;
        double mutation_possibility;

        vector <CIndividual*> population;
        vector <CIndividual*> best_individual_in_nth_iteration;

        bool isValidData();

        CIndividual* getBestSolution(vector <CIndividual*> &population);

        void generateFirstPopulation();
        void calculateFitness();
        int getPositionOfRandomCIndividual();

        vector<CIndividual*> crossObjects();

        void mutateObjects();

};


#endif //LISTA4_CGENETICALGORITHM_H
