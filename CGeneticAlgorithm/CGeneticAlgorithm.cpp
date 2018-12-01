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

    srand(time(NULL));
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    for (int i = 0; i < population.size(); ++i) {
        delete population.at(i);
    }

    for (int i = 0; i < best_individual_in_nth_iteration.size(); ++i) {
        delete best_individual_in_nth_iteration.at(i);
    }

}

bool CGeneticAlgorithm::isValidData() {
    cout<<"Walidacja danych algorytmu genetycznego...\n";
    if(population_size < 2){
        alert("Populacja musi liczyć więcej niż 1 osobnika!\n");
        return false;
    } else if(iteration_number < 1) {
        alert("Liczba iteracji musi być większa niż 1!\n");
        return false;
    } else if(crossing_possibility >= 1 || crossing_possibility <= 0){
        alert("Prawdopodobieństwo krzyżowania musi zawierać się pomiędzy (0;1)\n");
        return false;
    } else if(mutation_possibility >= 1 || mutation_possibility <= 0){
        alert("Prawdopodobieństwo mutacji musi zawierać się pomiędzy (0;1)\n");
        return false;
    }
    cout<<"Walidacja zakończona powodzeniem!\n\n";
    return true;
}

void CGeneticAlgorithm::showResults() {
    if(valid_knapsack_problem && valid_genetic_algorithm){
        cout << "Najlepszy osobnik w n-tej generacji: \n"
                "Lp.\tWartość\tGenotyp\n";
        for (int j = 0; j < iteration_number; ++j) {
            cout << j+1 << ".\t" << best_individual_in_nth_iteration.at(j)->fitness <<"\t\t"
                 << convertIntVectorToString(best_individual_in_nth_iteration.at(j)->genotype) <<"\n";
        }

        CIndividual* best_solution = getBestSolution(best_individual_in_nth_iteration);
        cout << "\nNajlepszy osobnik ogólnie: \n"
                "Wartość\tGenotyp\n";
        cout << best_solution->fitness <<"\t\t"
             << convertIntVectorToString(best_solution->genotype) <<"\n";
    }

}

CIndividual *CGeneticAlgorithm::getBestSolution() {
    return getBestSolution(best_individual_in_nth_iteration);
}

void CGeneticAlgorithm::runAlgorithm() {
    valid_knapsack_problem = knapsack_problem->isValidData();
    valid_genetic_algorithm = this->isValidData();
    if (valid_knapsack_problem && valid_genetic_algorithm){
        generateFirstPopulation();

        for (int i = 0; i < iteration_number; ++i) {
            calculateFitness();
            best_individual_in_nth_iteration.push_back(new CIndividual(*getBestSolution(population)));


            vector <CIndividual*> temp_population = crossObjects();

            for (int i = 0; i < population.size(); ++i) {
                delete population.at(i);
            }

            population = temp_population;

            mutateObjects();
        }

        calculateFitness();
        best_individual_in_nth_iteration.push_back(new CIndividual(*getBestSolution(population)));
    }

}

CIndividual *CGeneticAlgorithm::getBestSolution(vector <CIndividual*> &population) {
    CIndividual* best_solution = population.at(0);

    for (int i = 1; i < population.size(); ++i) {
        if (best_solution->fitness < population.at(i)->fitness){
            best_solution = population.at(i);
        }
    }

    return best_solution;
}

void CGeneticAlgorithm::generateFirstPopulation() {
    for (int i = 0; i < population_size; ++i) {
        vector <int> genotype;
        for (int j = 0; j < knapsack_problem->number_of_items; ++j) {
            genotype.push_back(rand()%2);
        }
        population.push_back(new CIndividual(knapsack_problem, genotype, mutation_possibility));
    }
}

void CGeneticAlgorithm::calculateFitness() {
    for (int i = 0; i < population_size; ++i) {
        population.at(i)->calculateAdaptation();
    }
}

int CGeneticAlgorithm::getPositionOfRandomCIndividual() {
    int first = rand() % population_size;
    int second = rand() % population_size;

    if(population.at(first)->fitness > population.at(second)->fitness){
        return first;
    } else {
        return second;
    }
}

vector<CIndividual *> CGeneticAlgorithm::crossObjects() {
    vector <CIndividual*> temp_population;

    if(population_size % 2 == 1){
        temp_population.push_back(new CIndividual(*population.at(getPositionOfRandomCIndividual())));
    }

    do{
        int first_parent = getPositionOfRandomCIndividual();
        int second_parent = getPositionOfRandomCIndividual();

        if((double)(rand()%101)/100 < crossing_possibility){
            vector <CIndividual*> children = population.at(first_parent)->crossCIndividual(population.at(second_parent));

            for (int j = 0; j < children.size(); ++j) {
                temp_population.push_back(children.at(j));
            }
        } else {
            temp_population.push_back(new CIndividual(*population.at(first_parent)));
            temp_population.push_back(new CIndividual(*population.at(second_parent)));
        }

    }while (temp_population.size() != population_size);

    return temp_population;
}

void CGeneticAlgorithm::mutateObjects() {
    for (int i = 0; i < population_size; ++i) {
        population.at(i)->performMutation();
    }
}
