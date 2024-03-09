/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:50:11 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/12 10:45:16 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.cpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return -1;

    try {
        BitcoinExchange test(argv[1]);
        test.run();
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    // print_map(stringStore);
}