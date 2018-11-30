//
// Created by martkans on 29.11.18.
//

#include "CIndividual.h"

CIndividual::CIndividual(CKnapsackProblem *knapsack_problem, vector<int> &genotype) {
    this->genotype = genotype;
    this->knapsack_problem = knapsack_problem;
}

vector<CIndividual *> CIndividual::crossCIndividual(CIndividual *other_object) {
    return vector<CIndividual *>();
}

void CIndividual::performMutation() {

}

void CIndividual::calculateAdaptation() {
    genotype_score = knapsack_problem->calculateValueOfGenotype(genotype);
}
