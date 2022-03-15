# include "HumanA.hpp"

HumanA::HumanA( const std::string &name, const Weapon &weapon ) {
    this->_weapon.setType(weapon.getType());
    this->_name = name;
}

HumanA::~HumanA( void ) {
    return ;
}

const std::string& HumanA::getWeapon( void ) { return this->_weapon.getType(); }

void HumanA::setWeapon( const std::string &weapon ) {
    this->_weapon.setType(weapon);
}

void HumanA::attack() {
    std::cout << this->_name << " Attacking with: " << this->_weapon.getType() << std::endl;
}
