# include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) {
    std::cout << this->getName() <<  " Default ScavTrap constructor has been called" << std::endl;
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap( void ) {
    std::cout << this->getName() << " ScavTrap Destructor has been called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & obj ) {
    std::cout << this->getName() << " ScavTrap Copy constructor has been called" << std::endl;
    this->setName(obj.getName());
    this->setHitPoints(obj.getHitpoints());
    this->setEnergyPoints(obj.getEnergypoints());
    this->setAttackDamage(obj.getAttackdamagepoints());
}

ScavTrap& ScavTrap::operator=( const ScavTrap & obj ) {
    std::cout << this->getName() << " ScavTrap Assignment Operator has been called" << std::endl;
    this->setName(obj.getName());
    return *this;
}


void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl;
}