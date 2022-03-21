#include "ScavTrap.hpp"

void printValues (ScavTrap &x)
{
	std::cout << "The "<< x.getName() << " has " << x.getHitpoints() << " Hitpoints "
	<< x.getEnergypoints() << " Energy points and " << x.getAttackdamagepoints() << " Attack damage received !" << std::endl;
}

int main(void)
{
	ScavTrap A ("A");
	ScavTrap B ("B");
	ScavTrap C = A;
	ScavTrap D = B;

	A.beRepaired(100 - A.getHitpoints());
	printValues(C);
	printValues(D);

	A.attack(B.getName());
	B.takeDamage(A.getAttackdamagepoints());
	B.attack(C.getName());
	C.takeDamage(B.getAttackdamagepoints());
	B.attack(C.getName());
	C.takeDamage(B.getAttackdamagepoints());


	printValues(A);
	printValues(B);
	printValues(C);
	printValues(D);

	A.guardGate();
	return 1;
}