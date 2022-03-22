# ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
    public:
        Dog();
        virtual ~Dog();
        Dog( const Dog& obj );
        Dog& operator=( const Dog& obj );

        virtual void makeSound() const;

    private:
        Brain *_brain;
};

# endif