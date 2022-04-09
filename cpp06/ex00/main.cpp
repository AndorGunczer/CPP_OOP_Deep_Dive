/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:10:53 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/09 19:00:09 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2 || argv == NULL)
		return (1);

	Data test = Data(argv[1]);
	test.converter();
	test.printAll();

	return (0);
}

/*	char: -Non displayable -impossible
	int: -0 -impossible
	float: -0.0f, nanf
	double: 0.0, nan
 */