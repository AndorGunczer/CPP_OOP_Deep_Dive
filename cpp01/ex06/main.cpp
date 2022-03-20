# include "Harl.hpp"

int main( int argc, char *argv[] ) {
    if (argc == 1) {
        std::cout << "I am not sure how tired I am today..." << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    Harl *karen = new Harl();
    karen->complain(argv[1]);
    delete karen;
    
    return 0;
}