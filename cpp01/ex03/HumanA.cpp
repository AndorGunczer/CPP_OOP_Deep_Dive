# include "HumanA.hpp"

HumanA::HumanA( const std::string &name, Weapon &weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA( void ) { return; }

const std::string& HumanA::getWeapon( void ) const { return this->_weapon.getType(); }

void HumanA::setWeapon( const std::string &weapon ) {
    // this->_weapon.setType(weapon);
    this->_weapon = weapon;
}

void HumanA::attack() {
    std::cout << this->_name << " Attacking with: " << this->_weapon.getType() << std::endl;
}
