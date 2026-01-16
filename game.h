#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "shop.h"
#include "bank.h"
#include "village.h"
#include "adventure.h"

int gameMenu(Player &player, Weapon weapons[], int weaponSize,
             Armor armors[], int armorSize, Potion potions[], int potionSize);
void instructions();
void inventoryMenu(Player &player, Weapon weapons[], int weaponSize, Armor armors[], int armorSize);

#endif
