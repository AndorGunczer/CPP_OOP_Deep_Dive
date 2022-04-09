/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:12:51 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 22:19:30 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <math.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand(time(NULL));
	int randomNum = (rand() % 3) + 1;
	Base* instance;

	switch (randomNum) {
		case 1: instance = new A(); break;
		case 2: instance = new B(); break;
		case 3: instance = new C(); break;
	}
	return instance;
}

void identify(Base* p) {
	if (A* a = dynamic_cast<A*>(p))
		std::cout << "the type is A" << std::endl;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "the type is B" << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "the type is C" << std::endl;
	else
		std::cout << "Undefined Type" << std::endl;
}

void identify(Base& p) {
	try {
    	A &item = dynamic_cast<A&>(p);
		std::cout << "the type is A" << std::endl;
	}
	catch(const std::bad_cast& e) {
		try {
    		B &item = dynamic_cast<B&>(p);
			std::cout << "the type is B" << std::endl;
		}
		catch(const std::bad_cast& e) {
    		try {
    			C &item = dynamic_cast<C&>(p);
				std::cout << "the type is C" << std::endl;
			}
			catch(const std::bad_cast& e) {
    			std::cout << "Undefined Type" << std::endl;
			}
		}
	}
}

int	main(void) {
	Base* newData = generate();
	identify(newData);
	identify(&(*newData));
}