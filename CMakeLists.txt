cmake_minimum_required(VERSION 3.12)
project(Lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista4 main.cpp CIndividual/CIndividual.cpp CIndividual/CIndividual.h CGeneticAlgorithm/CGeneticAlgorithm.cpp CGeneticAlgorithm/CGeneticAlgorithm.h CKnapsackProblem/CKnapsackProblem.cpp CKnapsackProblem/CKnapsackProblem.h CItem/CItem.cpp CItem/CItem.h Tools/Tools.cpp Tools/Tools.h)