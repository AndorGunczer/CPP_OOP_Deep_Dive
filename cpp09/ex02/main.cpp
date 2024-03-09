/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:53:30 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/15 11:35:51 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <stdio.h>

float calculateRunTime(struct timeval begin, struct timeval end, std::string datatype) {
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    float elapsed = (seconds + microseconds*1e-6)* 1000000;
    
    // printf("Time measured: %.3f seconds.\n", elapsed);
    std::cout << "Time to process the input elements with " << datatype << " is :  " << elapsed << "us\n";
    
    return 0;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

/* Vector Test */

    struct timeval beginVector, endVector;

    PmergeMe<std::vector< std::vector<int> >, std::vector<int> > test(argv);

    gettimeofday(&beginVector, 0);
    try { test.run(); } catch(std::invalid_argument &e) { std::cout << e.what() << std::endl; return -1; }
    gettimeofday(&endVector, 0);

/* Deque Test */

    struct timeval beginDeque, endDeque;

    PmergeMe<std::deque< std::deque<int> >, std::deque<int> > test2(argv);

    gettimeofday(&beginDeque, 0);
    try { test2.run(); } catch(std::invalid_argument &e) { std::cout << e.what() << std::endl; return -1; }
    gettimeofday(&endDeque, 0);

    test.exercisePrint();
    calculateRunTime(beginVector, endVector, "std::vector");
    calculateRunTime(beginDeque, endDeque, "std::deque");
}