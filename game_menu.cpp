#include "game.h"
#include "player.h"
#include "shop.h"
#include "bank.h"
#include "village.h"
#include "adventure.h"
#include <iostream>

int gameMenu() {
    int choice2 = -1;

   Weapon weapons[] = {
        {"Dagger", 15, 60},
        {"Spear", 25, 150},
        {"Short Bow", 25, 230},
        {"Battle Axe", 35, 250},
        {"Crossbow", 35, 350},
        {"Flaming Sword", 60, 600}
    };

    Armor armors[] = {
        {"Leather Armor", 5, 75},
        {"Chainmail", 15, 225},
        {"Plate Armor", 25, 375}
    };

    Potion potions[] = {
        {"Health Potion", 50, 20},
        {"Mana Potion", 30, 20}
    };


    Player player;

    player.hp = 100;
    player.xp = 0;
    player.gold = 2000;
    player.bankGold = 0;
    player.diamonds = 0;

    player.equipWeapon(weapons[0]);
    player.equipArmor(armors[0]);

    player.inventory["Health Potion"] = 0;
    player.inventory["Mana Potion"] = 0;
    player.inventory["Rusty Dagger"] = 0;
    player.inventory["Iron Shield"] = 0;
    player.inventory["Thunder Mace"] = 0;
    player.inventory["Leather Armor"] = 0;
    player.inventory["Chainmail"] = 0;
    player.inventory["Steel Armor"] = 0;
    player.inventory["Dagger"] = 0;
    player.inventory["Spear"] = 0;
    player.inventory["Short Bow"] = 0;
    player.inventory["Battle Axe"] = 0;
    player.inventory["Crossbow"] = 0;
    player.inventory["Flaming Sword"] = 0;
    player.inventory["Wooden Sword"] = 0;
    player.inventory["Cloth"] = 0;
   

 
   

    int weaponSize = sizeof(weapons) / sizeof(weapons[0]);
    int armorSize = sizeof(armors) / sizeof(armors[0]);
    int potionSize = sizeof(potions) / sizeof(potions[0]);
    

    while (choice2 != 0) {
    std::cout << "\n\t--> Where doth your journey lead, noble warrior? <--" << std::endl;
    std::cout << "\n1. Market Square \n2. Treasury Hall \n3. Adventure \n4. Village \n5. Inventory \n\n0. Exit game\n" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice2;
    std::cout << "____________________\n";
    switch(choice2){
    case 1: {
    shop(player, weapons, weaponSize, armors, armorSize, potions, potionSize);
    break;
    }
    case 2: {
    bankMenu(player);
    break;
    }
    case 3: {
        adventureMenu(player);
        break;
}


    case 4: {
    villageMenu(player);
    break;
    }
    case 5: {
        int choice6 = -1;
        while(choice6 != 0){
            std::cout << "\n\t--> Thy Inventory <--" << std::endl;
    std::cout << "\nGold: " << player.gold << std::endl;
    std::cout << "Diamonds: " << player.diamonds << std::endl;
    std::cout << "\nWeapon: " << player.weapon.name << " (dmg: " << player.weapon.damage << ")" << std::endl;
    std::cout << "Armor: " << player.armor.name << " (def: " << player.armor.defense << ")\n" << std::endl;
    
for(auto &item : player.inventory) {
    if(item.second > 0)
        std::cout << item.first << " x" << item.second << "\n";
}
    std::cout << "\n0. Back\n" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice6;
    std::cout << "____________________\n";
        }
    break;

    }
    case 0: {
                break;
            }
        default: {
            std::cout << "\n\t# Incorect option. Choose one from the menu. #" << std::endl;
            break;
            }
    }
    }

    return 0;
}
