#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) {
    std::cout << this->getName() <<  " Default FragTrap constructor has been called" << std::endl;
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap( void ) {
    std::cout << this->getName() << " FragTrap Destructor has been called" << std::endl;
}

FragTrap::FragTrap( const FragTrap & obj ) {
    std::cout << this->getName() << " FragTrap Copy constructor has been called" << std::endl;
    this->setName(obj.getName());
    this->setHitPoints(obj.getHitpoints());
    this->setEnergyPoints(obj.getEnergypoints());
    this->setAttackDamage(obj.getAttackdamagepoints());
}

FragTrap& FragTrap::operator=( const FragTrap & obj ) {
    std::cout << this->getName() << " FragTrap Assignment Operator has been called" << std::endl;
    this->setName(obj.getName());
    return *this;
}