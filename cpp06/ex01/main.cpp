/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:28:48 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 20:45:11 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>
#include <stdio.h>


uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int	main(void) {
	Data* newData = new Data();
	uintptr_t thisThing;

	std::cout << "newData address after initialization: " << newData << std::endl;

	newData = deserialize(serialize(newData));
	
	std::cout << "newData address after serialization-deserialization: " << newData << std::endl;

	std::cout << newData->getFiller() << std::endl;
}