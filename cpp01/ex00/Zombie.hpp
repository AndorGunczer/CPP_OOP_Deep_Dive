/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:53:36 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/14 12:38:34 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce( void );

	private:
		std::string _name;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif