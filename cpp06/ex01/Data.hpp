/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:23:21 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 20:43:50 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
		int filler;

	public:
		Data();
		~Data();
		Data( const Data& obj );
		Data& operator=( const Data& obj );

		const int& getFiller();
		void		setFiller( const int& newValue );
};

# endif