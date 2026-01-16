#pragma once
#include <string>
#include "player.h"

bool saveGame(const Player &player, const std::string &slotName);
bool loadGame(Player &player, const std::string &slotName);
void saveGameMenu(Player &player);
void loadGameMenu(Player &player);
