# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ~ClapTrap( void );
        ClapTrap( ClapTrap const & obj );
        ClapTrap& operator=( ClapTrap const & obj );

        void setName( std::string name );
        void setHitPoints( int hitpoints );
        void setEnergyPoints( int energy );
        void setAttackDamage( int damage );

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
		int getHitpoints(void) const;
		int getEnergypoints(void) const;
		int getAttackdamagepoints(void) const;
};

# endif