# ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        ~Dog();
        Dog( const Dog& obj );
        Dog& operator=( const Dog& obj );

        virtual void makeSound() const;
};

# endif