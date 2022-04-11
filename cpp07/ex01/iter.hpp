/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:26 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/11 12:44:51 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

template <typename T> void iter(T *ptr, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++)
	{
		f(ptr[i]);
	}
}

// template <typename T, template <typename> class Func> void iter(T *ptr, size_t length, Func f) {
// 	for (size_t i = 0; i < length; i++)
// 	{
// 		f(ptr[i]);
// 	}
// }