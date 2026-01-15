#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
#include "player.h"

int shop(Player &player, Weapon[], int weaponSize, Armor[], int armorSize, Potion[], int potionSize);
int buyWeapon(Player &player, Weapon[], int weaponSize);
int buyArmor(Player &player, Armor[], int armorSize);
int buyPotions(Player &player, Potion[], int potionSize);
void sellMenu(Player &player, 
              Weapon weapons[], int weaponSize, 
              Armor armors[], int armorSize, 
              Potion potions[], int potionSize);
void sellItem(Player &player, const std::string& itemName,
              Weapon weapons[], int weaponSize,
              Armor armors[], int armorSize,
              Potion potions[], int potionSize);

#endif // SHOP_H_INCLUDED
