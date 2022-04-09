/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:27:07 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 20:43:00 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : filler(555) {

}

Data::~Data() {

}

Data::Data( const Data& obj ) {
	*this = obj;
}

Data& Data::operator=( const Data& obj ) {
	*this = obj;
	return (*this);
}


const int& Data::getFiller() {
	return filler;
}

void		Data::setFiller( const int& newValue ) {
	filler = newValue;
}
