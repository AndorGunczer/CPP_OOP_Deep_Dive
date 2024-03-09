/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:48 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/06 13:31:09 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
    this->numberStore = new std::vector<int>(0);
    this->currentMax = this->numberStore->begin();
}

Span::Span(unsigned int N) {
    this->numberStore = new std::vector<int>(N);
    this->currentMax = this->numberStore->begin();
}

Span::Span(const Span &a) {
    *this = a;
}

Span::~Span() {
    delete numberStore;
}

Span& Span::operator=(const Span &a) {
    this->currentMax = a.currentMax;
    return *this;
} 

void Span::addNumber() {
    int limit = 200000;

    try {
        if (this->currentMax < this->numberStore->end()) {
        *(this->currentMax) = rand() % limit;
        currentMax++;
        }
        else
            throw std::out_of_range("Err: Cannot Add Number to Container: Out of Range\n");
    } catch (const std::out_of_range &e) {
        std::cout << e.what();
        return;
    }
}

void Span::addNumber(int amount) {
    int limit = 200000;
    vector_iterator futureMax = this->currentMax + (amount);

    try {
        if (futureMax <= this->numberStore->end()) {
            for (; currentMax < futureMax; currentMax++) {
                *(this->currentMax) = rand() % limit;
            }
        }
        else
            throw std::out_of_range("Err: Cannot Add Number to Container: Out of Range\n");
    } catch ( const std::out_of_range &e ) {
        std::cout << e.what();
    }
}

void Span::fillVector() {
    int limit = 200000;
    
    for (std::vector<int>::iterator it = this->numberStore->begin(); it < this->numberStore->end(); it++) {
        *it = rand() % limit;
    }
}

void Span::getVector() {
    std::cout << "getvector called" << std::endl;

    for (std::vector<int>::iterator it = this->numberStore->begin(); it < this->numberStore->end(); it++)
        std::cout << *it << std::endl;
}

int Span::getSingleNumber( int index ) {
    return this->numberStore->at(index);
}

int Span::shortestSpan() {
    try {
        if (numberStore->size() <= 1)
            throw std::length_error("\n");
    } catch (const std::length_error &e) {
        std::cerr << e.what();
        return -1;
    }

    std::vector<int> * copiedNumberStore = new std::vector<int>(*(this->numberStore));
    std::vector<int>::iterator it = copiedNumberStore->begin();
    int smallestDifference = abs(*it - *(it+1));

    std::sort(copiedNumberStore->begin(), copiedNumberStore->end());
    for(it = copiedNumberStore->begin(); it < copiedNumberStore->end() - 1; it++) {
        int currentDifference = abs(*it - *(it+1));
        if (currentDifference < smallestDifference)
            smallestDifference = currentDifference;
    }

    delete copiedNumberStore;

    return smallestDifference;
}

int Span::longestSpan() {
    try {
        if (numberStore->size() <= 1)
            throw std::length_error("\n");
    } catch (const std::length_error &e) {
        std::cerr << e.what();
        return -1;
    }
    std::vector<int> * copiedNumberStore = new std::vector<int>(*(this->numberStore));

    std::sort(copiedNumberStore->begin(), copiedNumberStore->end());
    int first = *(copiedNumberStore->begin());
    int last = *(copiedNumberStore->end() - 1);

    delete copiedNumberStore;

    return abs(last - first);
}