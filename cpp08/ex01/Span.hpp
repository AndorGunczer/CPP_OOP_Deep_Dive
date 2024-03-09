/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:42 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/06 10:56:34 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span {
    private:
        typedef std::vector<int>::iterator vector_iterator;
        std::vector<int> *numberStore;
        vector_iterator currentMax;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &a);
        ~Span();
        Span& operator=(const Span &a);
        
        void addNumber();
        void addNumber(int amount);
        void fillVector();
        void getVector();
        int getSingleNumber(int index);
        int shortestSpan();
        int longestSpan();
};

#endif