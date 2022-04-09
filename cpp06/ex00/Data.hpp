/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:06 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 19:02:00 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define STRING 5

class Data {
	private:
		std::string	_input;
		int	*typeSelector;
		char _charVal;
		int	_intVal;
		float _floatVal;
		double _doubleVal;
		// void (Data::*ptr[4])(int*);
		// errors
		std::string	_charError;
		std::string	_intError;
		std::string	_floatError;
		std::string _doubleError;
		
	public:
		Data();
		Data( std::string input );
		~Data();
		Data( const Data& obj );
		// void	operator=( const Data& obj );

		const int&			getCurrent();
		const char&			getChar();
		const int&			getInt();
		const float&		getFloat();
		const double&		getDouble();
		const std::string&	getString();

		void	setCurrent( const int& input );
		void	setChar( const char& input );
		void	setInt( const int& input );
		void	setFloat( const float& input );
		void	setDouble( const double& input );
		void	setString( const std::string& input );
		
		void	isChar();
		void	isInt();
		void	isFloat();
		void	isDouble();

		void	convertToFloat();
		void	convertToDouble();
		void	convertToInt();
		void	convertToChar();
		void	nonsense();
		void	converter();
		std::string	checkFloatingPointOrigin();
		void	printCurrent();
		void	printAll();
};