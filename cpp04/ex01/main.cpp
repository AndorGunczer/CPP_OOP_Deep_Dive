#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	delete dog;
	delete cat;


	Animal	 *animals[2];

	for (int i = 0; i < 2; i++) {

		if (i % 2 == 0) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < 2; i++) {

		delete animals[i];
	}

	Cat	cat1;
	Cat	cat2 = cat1;
	cat1.addIdea("nice");
	cat1.addIdea("gut");
	cat1.displayIdea();
	cat2.addIdea("bien");
	cat2.addIdea("bene");
	cat2.displayIdea();
	cat1.displayIdea();

    system("leaks Animal");
	return (0);
}