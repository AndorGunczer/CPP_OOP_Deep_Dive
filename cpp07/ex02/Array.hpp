/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:35 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/11 17:10:26 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array {
	private:
		T *array;
		int arraySize;

	public:
		Array() : array(new T[0]), arraySize(0) {}
		Array( const unsigned int& n ) : array(new T[n]), arraySize(n) {}
		~Array() { delete[] array; }
		Array( const Array& obj) {
			this->arraySize = obj.arraySize;
			this->array = new T[this->arraySize];

			for (int i = 0; i < this->arraySize; i++) {
				this->array[i] = obj.array[i];
			}
		}
		Array& operator=( const Array& obj ) {
			delete[] this->array;
			this->arraySize = obj.arraySize;
			this->array = new T[this->arraySize];

			for (int i = 0; i < this->arraySize; i++) {
				this->array[i] = obj.array[i];
			}
			return *this;
		}

		T& operator[](int i) { // this thing
			if (i >= arraySize) {
				std::cout << "Index out of bounds, first value returned" << std::endl;
            	return array[0];
			}
			return array[i];
		}
		int& size() { return this->arraySize; }
};

#endif