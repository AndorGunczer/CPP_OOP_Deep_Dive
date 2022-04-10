/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:26 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/10 02:29:33 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

template <typename T, typename Func> void iter(T *ptr, size_t length, Func f) {
	for (size_t i = 0; i < length; i++)
	{
		f(ptr[i]);
	}
}