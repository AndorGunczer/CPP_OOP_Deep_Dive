# include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->_name <<  " ClapTrap Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->_name <<  " ClapTrap Default constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << this->_name << " ClapTrap Destructor has been called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & obj ) {
    std::cout << this->_name << " ClapTrap Copy constructor has been called" << std::endl;
    this->_name = obj._name;
}

ClapTrap &ClapTrap::operator=( ClapTrap const & obj ) {
    std::cout << this->_name << " ClapTrap Assignment Operator has been called" << std::endl;
    this->_name = obj._name;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	// this->_attackDamage += amount; 
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << this->_name << " has repaired itself by " << amount << " hitpoints!" << std::endl;
    this->_energyPoints--;
    this->_hitPoints += amount;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitpoints(void) const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergypoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackdamagepoints(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setName( std::string name ) {
    this->_name = name;
}

void ClapTrap::setHitPoints( int hitpoints ) {
    this->_hitPoints = hitpoints;
}

void ClapTrap::setEnergyPoints( int energy ) {
    this->_energyPoints = energy;
}

void ClapTrap::setAttackDamage( int damage ) {
    this->_attackDamage = damage;
}
