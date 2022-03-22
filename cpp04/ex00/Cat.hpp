# ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        ~Cat();
        Cat( const Cat& obj );
        Cat& operator=( const Cat& obj );

        virtual void makeSound() const;
};

# endif