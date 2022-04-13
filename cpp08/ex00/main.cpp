/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:15:15 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/13 09:40:08 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	{
		std::vector<int>  vect;
		vect.push_back(10);
		vect.push_back(20);
		vect.push_back(30);
	
		std::vector<int>::iterator it = easyfind(vect, 9);
		std::vector<int>::iterator it2 = easyfind(vect, 30);
	
		std::cout << &(*it) << std::endl;
		std::cout << &(*it2) << std::endl;
	
		// return 0;
	}

	{
		std::list<int> list;

		list.push_back(40);
		list.push_back(50);
		list.push_back(60);
	
		std::list<int>::iterator it = easyfind(list, 62);
		std::list<int>::iterator it2 = easyfind(list, 60);
	
		std::cout << &(*it) << std::endl;
		std::cout << &(*it2) << std::endl;
	
		// return 0;
	}

	{
		std::array<int, 3> array = {1, 2 ,3};
	
		std::array<int, 3>::iterator it1 = easyfind(array, 0);
		std::array<int, 3>::iterator it2 = easyfind(array, 1);
		std::array<int, 3>::iterator it3 = easyfind(array, 2);
		std::array<int, 3>::iterator it4 = easyfind(array, 3);
		std::array<int, 3>::iterator it5 = easyfind(array, 4);
	
		std::cout << "address of it1 at: " << &(*it1) << std::endl;
		std::cout << "address of it2 at: " << &(*it2) << std::endl;
		std::cout << "address of it3 at: " << &(*it3) << std::endl;
		std::cout << "address of it4 at: " << &(*it4) << std::endl;
		std::cout << "address of it5 at: " << &(*it5) << std::endl;
	
		// return 0;
	}

	// {
	// 	std::vector<int[3]>  vect;
	// 	int k[3] = {1, 2, 3};
	// 	vect.push_back(k);
	// 	vect.push_back(k);
	// 	vect.push_back(k);
	
	// 	std::vector<int[3]>::iterator it = easyfind(vect, 1);
	// 	std::vector<int[3]>::iterator it2 = easyfind(vect, 30);
	
	// 	std::cout << &(*it) << std::endl;
	// 	std::cout << &(*it2) << std::endl;
	
	// 	// return 0;
	// }
}
