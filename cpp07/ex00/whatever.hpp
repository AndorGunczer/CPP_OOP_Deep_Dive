/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:23:53 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/10 01:34:27 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

template <typename T> void swap(T& a, T& b) {
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b) {
	return a < b ? a : b;
}

template <typename T> T max(T a, T b) {
	return a > b ? a : b;
}