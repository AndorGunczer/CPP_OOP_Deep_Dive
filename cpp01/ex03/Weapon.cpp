# include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->_type = type;
}

Weapon::Weapon( void ) { return; }

Weapon::~Weapon( void ) {
    return;
}

const std::string& Weapon::getType( void ) const { return this->_type; }

void Weapon::setType( const std::string& newType ) { this->_type = newType; }