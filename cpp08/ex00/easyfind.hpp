/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:15:13 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/13 09:49:54 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <string>

template <typename T>
	typename T::iterator easyfind(T cont, const int& toFind) {
		typename T::iterator it = std::find(cont.begin(), cont.end(), toFind);
		
		if (it == cont.end())
		{
			std::cout << "not found" << std::endl;
			return it;
		}
		else
			return it;
	}