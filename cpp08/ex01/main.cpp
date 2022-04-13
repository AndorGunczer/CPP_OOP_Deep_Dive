/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:37:12 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/13 19:03:21 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int	main(void) {
	Span *var = new Span(5);

	var->fillSpan();
	var->addNumber(7);

	std::cout << var->_vect[0] << std::endl;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }