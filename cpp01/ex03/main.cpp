# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

// int main( void ) {
//     // Weapon *newWeapon = new Weapon("Bicska");
//     // const std::string &modify = newWeapon->getType();

//     // newWeapon->setType("Kes");

//     // std::cout << newWeapon->getType() << std::endl;
//     // std::cout << modify << std::endl;

//     HumanA *newHuman = new HumanA("Andor", "baszogep");

//     newHuman->attack();
// }

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}