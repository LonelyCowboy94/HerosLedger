#include "game.h"
#include <iostream>

int instructions() {
    int choice3 = -1;
    while (choice3 != 0) {
    std::cout << "\nInstructions are written here" << std::endl;
    std::cout << "\n0. Back\n" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice3;
    std::cout << "____________________\n";
    }

    return 0;
}
