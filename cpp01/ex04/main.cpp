# include "replace.hpp"
# include <string>
# include <iostream>
# include <fstream>

int main( int argc, char *argv[]) {
    std::fstream fs;
    std::string buffer;
    std::string container;

    // Error checks
    if (argc != 4)
        return 1;
    fs.open(argv[1]);
    if (fs.fail()) {
        std::cout << "file doesn't exist" << std::endl;
        return 1;
    }
    if (strcmp(argv[2], "") == 0) {
        std::cout << "parameter definition lead to infinite runtime (empty string is part of every string => everything being infinitely replaced)." << std::endl;
        fs.close();
        return 1;
    }

    // reading contents of source file into a container string
    while (std::getline(fs, buffer))
    {
        container += buffer;
        if (fs.good())
            container += "\n";
        continue;
    }
    fs.close();

    // replacing every instance of s1 with s2 in container string
    int posn = container.find(argv[2]);
    while (posn != -1){
        container.erase(posn, strlen(argv[2]));
        container.insert(posn, argv[3]);
        posn = container.find(argv[2]);
    }

    // write container string into output.txt
    fs.open("output.txt", std::fstream::out);
    fs << container;
    fs.close();
    std::cout << container;
    // system("leaks a.out");
}