# ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
    public:
        Cat();
        virtual ~Cat();
        Cat( const Cat& obj );
        Cat& operator=( const Cat& obj );

        virtual void makeSound() const;
        void    addIdea( std::string idea );
        void    displayIdea();

    private:
        Brain *_brain;
};

# endif