#include <iostream>

#include "CKnapsackProblem/CKnapsackProblem.h"
#include "CGeneticAlgorithm/CGeneticAlgorithm.h"

#define KNAPSACK_CAPACITY           5
#define KNAPSACK_NUMBER_OF_ITEMS    4

#define POPULATION_SIZE             4
#define ITERATION_NUMBER            50
#define CROSSING_POSSIBILITY        0.7
#define MUTATION_POSSIBILITY        0.1

using namespace std;

int main() {
    vector <CItem*> items;
    items.push_back(new CItem(5,4));
    items.push_back(new CItem(1,1));
    items.push_back(new CItem(4,3));
    items.push_back(new CItem(3,2));

    CKnapsackProblem* knapsack_problem = new CKnapsackProblem(KNAPSACK_CAPACITY, KNAPSACK_NUMBER_OF_ITEMS, items);
    CGeneticAlgorithm* geneticAlgorithm = new CGeneticAlgorithm(knapsack_problem, POPULATION_SIZE, ITERATION_NUMBER, CROSSING_POSSIBILITY, MUTATION_POSSIBILITY);

    geneticAlgorithm->runAlgorithm();
    geneticAlgorithm->showResults();

    delete knapsack_problem;
    delete geneticAlgorithm;

    return 0;
}