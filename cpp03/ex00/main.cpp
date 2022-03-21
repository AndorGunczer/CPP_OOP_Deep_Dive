#include "ClapTrap.hpp"

void printValues (ClapTrap &x)
{
	std::cout << "The "<< x.getName() << " has " << x.getHitpoints() << " Hitpoints "
	<< x.getEnergypoints() << " Energy points and " << x.getAttackdamagepoints() << " Attack damage received !" << std::endl;
}

int main(void)
{
	ClapTrap a ("a");
	ClapTrap b ("b");

	printValues(a);
	printValues(b);

	a.attack(b.getName());
	b.takeDamage(a.getAttackdamagepoints());
	a.beRepaired(10 - a.getHitpoints());

	printValues(a);
	printValues(b);
	return 1;
}