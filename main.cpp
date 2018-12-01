#include <iostream>

#include "CKnapsackProblem/CKnapsackProblem.h"
#include "CGeneticAlgorithm/CGeneticAlgorithm.h"

using namespace std;

int main() {
    vector <CItem*> items;
    items.push_back(new CItem(5,4));
    items.push_back(new CItem(1,1));
    items.push_back(new CItem(4,3));
    items.push_back(new CItem(3,2));

    CKnapsackProblem* knapsack_problem = new CKnapsackProblem(5, 4, items);
    CGeneticAlgorithm* geneticAlgorithm = new CGeneticAlgorithm(knapsack_problem, 4, 50, 0.7, 0.1);

    geneticAlgorithm->runAlgorithm();
    geneticAlgorithm->showResults();

    delete knapsack_problem;
    delete geneticAlgorithm;

    return 0;
}