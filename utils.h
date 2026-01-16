#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "player.h"

void textCenter(const std::string& text, int width = 66);
void clearScreen();
void showPlayerStatus(const Player &player);

#endif
