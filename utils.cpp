#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

void showPlayerStatus(const Player &player)
{
    std::cout << "   HP: " << player.hp
              << "        Mana: " << player.mana
              << std::endl;
}

void textCenter(const std::string& text, int width)
{
    if (text.length() >= static_cast<size_t>(width)) {
        std::cout << text << std::endl;
        return;
    }

    int padding = (width - text.length()) / 2;
    std::cout << std::string(padding, ' ') << text << std::endl;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");   
#else
    system("clear");  
#endif
}

