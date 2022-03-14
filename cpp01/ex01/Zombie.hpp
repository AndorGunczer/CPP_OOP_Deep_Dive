/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:53:36 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/14 13:35:49 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie( std::string name );
		Zombie();
		~Zombie();
		void	announce( void );
		void	setName( std::string name );

	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif