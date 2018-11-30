//
// Created by martkans on 29.11.18.
//

#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem *knapsack_problem, int population_size, int iteration_number,
                                     double crossing_possibility, double mutation_possibility)  {
    this->knapsack_problem = knapsack_problem;
    this->population_size = population_size;
    this->iteration_number = iteration_number;
    this->crossing_possibility = crossing_possibility;
    this->mutation_possibility = mutation_possibility;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    delete knapsack_problem;
    for (int i = 0; i < population_size; ++i) {
        delete population.at(i);
    }

    for (int i = 0; i < iteration_number; ++i) {
        delete best_individual_in_nth_iteration.at(i);
    }
}

void CGeneticAlgorithm::runAlgorithm() {

}

CIndividual *CGeneticAlgorithm::getBestSolution() {
    CIndividual* best_solution = population.at(0);

    for (int i = 1; i < iteration_number; ++i) {
        if (best_solution->genotype_score < population.at(i)->genotype_score){
            best_solution = population.at(i);
        }
    }

    return best_solution;
}
