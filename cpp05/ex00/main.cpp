# include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat andor("Andor", 1);
    Bureaucrat nandor("Nandor", 160);

    std::cout << "name: " << andor.name << " grade: " << andor.grade << std::endl;
    std::cout << "name: " << nandor.name << " grade: " << nandor.grade << std::endl;
    return (0);
}