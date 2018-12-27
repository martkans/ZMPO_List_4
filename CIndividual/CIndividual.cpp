//
// Created by martkans on 29.11.18.
//

#include "CIndividual.h"

CIndividual::CIndividual(CKnapsackProblem *knapsack_problem, vector<int> genotype, double &mutation_probability) {
    this->genotype = genotype;
    this->knapsack_problem = knapsack_problem;
    this->mutation_probability = mutation_probability;
}

CIndividual::CIndividual(CIndividual &other_object) {
    this->fitness = other_object.fitness;
    this->mutation_probability = other_object.mutation_probability;
    this->genotype = other_object.genotype;
    this->knapsack_problem = other_object.knapsack_problem;
}

vector<CIndividual *> CIndividual::crossCIndividual(CIndividual *other_object) {
    int cross_position = (rand() % (genotype.size()-1)) + 1;


    CIndividual* first_child = new CIndividual(*this);
    CIndividual* second_child = new CIndividual(*other_object);

    for (int i = 0; i < cross_position; ++i) {
        first_child->genotype.at(i) = other_object->genotype.at(i);
        second_child->genotype.at(i) = this->genotype.at(i);
    }

    vector<CIndividual*> children;
    children.push_back(first_child);
    children.push_back(second_child);

    return children;
}

void CIndividual::performMutation() {
    for (int i = 0; i < genotype.size(); ++i) {
        if((double)(rand()%101)/100 < mutation_probability){
            genotype.at(i) = 1 - genotype.at(i);
        }
    }
}

void CIndividual::calculateFitness() {
    fitness = knapsack_problem->calculateValueOfGenotype(genotype);
}
