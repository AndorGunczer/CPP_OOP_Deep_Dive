// #include "ScavTrap.hpp"
#include "FragTrap.hpp"

void printValues (FragTrap &x)
{
	std::cout << "The "<< x.getName() << " has " << x.getHitpoints() << " Hitpoints "
	<< x.getEnergypoints() << " Energy points and " << x.getAttackdamagepoints() << " Attack damage received !" << std::endl;
}

int main(void)
{
	FragTrap A ("A");
	FragTrap B ("B");
	FragTrap D = B;

	printValues(D);

	A.attack(B.getName());
	B.takeDamage(A.getAttackdamagepoints());
	A.beRepaired(100 - A.getHitpoints());

	printValues(A);
	printValues(B);

	// A.highFivesGuys();
	return 1;
}