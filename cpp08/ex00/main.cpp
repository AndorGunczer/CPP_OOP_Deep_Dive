/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:34:04 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/05 12:23:53 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int main() {
    std::list<int> array;
    array.push_back(6);
    array.push_back(2);
    array.push_back(3);

    std::list<int>::iterator ptr = easyFind(&array, 12);

    std::cout << "Not Found: " << std::endl << "    Value we are looking for: 12" << std::endl << "    Value returned: " << *ptr << std::endl;

    ptr = easyFind(&array, 6);

    std::cout << "Found: " << std::endl << "    Value we are looking for: 6" << std::endl << "    Value returned: " << *ptr << std::endl;
}