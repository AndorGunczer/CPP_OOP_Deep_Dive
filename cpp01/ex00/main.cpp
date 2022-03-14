#include "Zombie.hpp"

int	main( void ) {
	Zombie basicZombie("Andor");
	randomChump("randomChumpZombie");
	Zombie *nwZombi;

	nwZombi = newZombie("newZombie");

	basicZombie.announce();
	nwZombi->announce();
	delete nwZombi;
}