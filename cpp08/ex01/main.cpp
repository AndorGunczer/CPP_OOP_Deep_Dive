/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:52 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/06 13:32:08 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    srand(time(NULL)); 
    Span *first = new Span(100000);
    Span *second = new Span(6);

    std::cout << first << std::endl;
    std::cout << second << std::endl;

    // member functions test: FIRST

    first->fillVector();

    // first->getVector();
    std::cout << "\n\n";
    std::cout << "shortest span: " << first->shortestSpan() << std::endl;
    std::cout << "first number: " << first->getSingleNumber(0) << std::endl;
    std::cout << "last number: " << first->getSingleNumber(99999) << std::endl;
    std::cout << "longest span: " << first->longestSpan() << std::endl;
    // first->getVector();

    // member functions test: SECOND

    second->fillVector();

    second->getVector();
    std::cout << "\n\n";
    std::cout << "shortest span: " << second->shortestSpan() << std::endl;
    std::cout << "longest span: " << second->longestSpan() << std::endl;
    second->getVector();

    // test empty copy and reverse size
    delete first;
    delete second;

    /* Test: Not Enough Number to Calculate Span */

    {
        Span *noSpan = new Span(1);
        std::cout << "Calling shortestSpan() with 1 or less numbers: " << noSpan->shortestSpan() << std::endl;
        delete noSpan;
    }

    /* Test Adding a certain amount of number */

    {
        std::cout << "Test Addnumber(int) OK" << std::endl;

        Span *testSpan = new Span(5);
        testSpan->addNumber(3);
        testSpan->addNumber(2);
        testSpan->getVector();
        delete testSpan;

        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "Test Addnumber(int) exceeding range" << std::endl;

        Span *testSpan = new Span(5);
        testSpan->addNumber(3);
        testSpan->addNumber(3);
        testSpan->getVector();
        delete testSpan;

        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "Testing addNumber()" << std::endl;

        Span *testSpan = new Span(3);
        testSpan->addNumber();
        testSpan->addNumber();
        testSpan->addNumber();
        testSpan->addNumber();
        testSpan->getVector();

        std::cout << "Shortest Span addNumber(): " << testSpan->shortestSpan() << std::endl;
        std::cout << "Longest Span addNumber(): " << testSpan->longestSpan() << std::endl;
        delete testSpan;

        std::cout << std::endl << std::endl;
    }
}