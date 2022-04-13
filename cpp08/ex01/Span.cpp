/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:37:09 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/13 19:04:36 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {} 
Span::~Span() {}
Span::Span( const Span& obj ) {
	this->_N = obj._N;
	std::copy(obj._vect.begin(), obj._vect.end(), this->_vect.begin());
}
Span& Span::operator=( const Span& obj ) {
	this->_N = obj._N;
	std::copy(obj._vect.begin(), obj._vect.end(), this->_vect.begin());
	return *this;
}

void Span::addNumber( int number ) {
	if (this->_vect.size() < _N) _vect.push_back(number);
	else throw std::runtime_error("You Failed\n");
}

int	Span::shortestSpan() {
	std::vector<int>::iterator i1;
	std::vector<int>::iterator j1;
	int shortest = INT_MAX;

	for ( i1 = _vect.begin(); i1 != _vect.end(); i1++)
	{
		for (j1 = std::next(i1, 1); j1 != _vect.end(); j1++)
		{
			// std::cout << abs(*j1 - *i1) << std::endl;
			if (abs(*j1 - *i1) < shortest) shortest = abs(*j1 - *i1);
		}
		
	}
	return shortest;
}

int	Span::longestSpan() {
	std::vector<int>::iterator i1;
	std::vector<int>::iterator j1;
	int longest = 0;

	for ( i1 = _vect.begin(); i1 != _vect.end(); ++i1)
	{
		for (j1 = std::next(i1, 1); j1 != _vect.end(); ++j1)
		{
			if (abs(*j1 - *i1) > longest) longest = abs(*j1 - *i1);
		}
	}
	return longest;
}

void Span::fillSpan() {
	_vect.assign(_N, true);
}
