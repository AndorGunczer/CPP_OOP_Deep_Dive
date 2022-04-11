/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:38 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/11 14:56:41 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void) {
	// testing basic functionality of template class
	// {
	// 	Array<int> myArray;

	// 	myArray[0] = 5;
	// 	// std::cout << myArray[6] << std::endl;
	// }
	// testing of copy constructor and assignment operator
	
	// {
	// 	Array<char> myArray(3);

	// 	myArray[0] = 'a';
	// 	myArray[1] = 'b';
	// 	myArray[2] = 'c';
	// 	Array<char> copiedArray(myArray);
	// 	std::cout << "myArray[1]: " << myArray[1] << std::endl;
	// 	std::cout << "copiedArray[1]: " <<  copiedArray[1] << std::endl;
	// 	myArray[1] = 'z';
	// 	std::cout << "myArray[1]: " <<  myArray[1] << std::endl;
	// 	std::cout << "copiedArray[1]: " <<  copiedArray[1] << std::endl;
	// }
	
	{
		Array<char> myArray(3);

		myArray[0] = 'a';
		myArray[1] = 'b';
		myArray[2] = 'c';
		Array<char> copiedArray;
		copiedArray = myArray;
		std::cout << "myArray[1]: " << myArray[1] << std::endl;
		std::cout << "copiedArray[1]: " <<  copiedArray[1] << std::endl;
		myArray[1] = 'z';
		std::cout << "myArray[1]: " <<  myArray[1] << std::endl;
		std::cout << "copiedArray[1]: " <<  copiedArray[1] << std::endl;	
	}
}