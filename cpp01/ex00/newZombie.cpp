#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie *newZombie = new Zombie(name);
	return newZombie;
}