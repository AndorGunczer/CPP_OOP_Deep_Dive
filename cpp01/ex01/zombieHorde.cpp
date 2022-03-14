#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *ptr = new Zombie[N];

	for(int i = 0; i <= N; i++){
		ptr[i].setName("Andor");
	}
	return ptr;
}