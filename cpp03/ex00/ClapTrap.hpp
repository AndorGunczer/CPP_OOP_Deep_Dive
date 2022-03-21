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
        ClapTrap( std::string name );
        ~ClapTrap( void );
        ClapTrap( ClapTrap const & obj );
        ClapTrap& operator=( ClapTrap const & obj );

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void);
		int getHitpoints(void);
		int getEnergypoints(void);
		int getAttackdamagepoints(void);
};

# endif