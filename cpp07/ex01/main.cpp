/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:28 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/11 12:52:15 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void shiftForward(char const &a) {
// 	std::cout << (char)(a + 1) << std::endl;
// }

// int	main(void) {
// 	char array[5] = {'a', 'b', 'c', 'd', '\0'};
// 	size_t length = 4;

// 	std::cout << array[0] << std::endl;
// 	::iter(array, length, shiftForward);
// 	std::cout << array[0] << std::endl;
// }

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

	std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
	template< typename T >
		void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] 
	// tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
}
