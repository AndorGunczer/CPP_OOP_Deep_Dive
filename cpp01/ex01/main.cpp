#include "Zombie.hpp"

int	main( void ) {
	int hordeSize = 10;
	Zombie *horde = NULL;
	horde = zombieHorde(hordeSize, "Andor");

	for(int i = 0; i < hordeSize; i++){
		horde[i].announce();
	}
	delete [] horde;
	system("leaks a.out");
}