/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:37:07 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/13 18:57:14 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

class Span {
	private:
		unsigned int	_N;

	public:
		std::vector<int> _vect;
		Span(unsigned int N);
		~Span();
		Span( const Span& obj );
		Span& operator=( const Span& obj );

		// const int& getVect( int index );
		// void setVect( int index, int value );
		
		void addNumber( int number );
		int	shortestSpan();
		int	longestSpan();
		void fillSpan();
};

#endif