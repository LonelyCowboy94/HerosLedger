#include <iostream>
#include <string>
#include "utils.h"
#include "game.h"
#include "save_load.h"

using std::string;

int main()
{
    clearScreen();
    int choice = -1;
    bool gameStarted = false;

    // --- Player setup
    Player player;
    player.hp = 100;
    player.mana = 100;
    player.xp = 0;
    player.gold = 2000;
    player.bankGold = 0;
    player.diamonds = 0;

    Weapon weapons[] = {
        {"Dagger", 15, 60},
        {"Spear", 25, 150},
        {"Short Bow", 25, 230},
        {"Battle Axe", 35, 250},
        {"Crossbow", 35, 350},
        {"Flaming Sword", 60, 600}};

    Armor armors[] = {
        {"Leather Armor", 5, 75},
        {"Chainmail", 15, 225},
        {"Plate Armor", 25, 375}};

    Potion potions[] = {
        {"Health Potion", 50, 20},
        {"Mana Potion", 30, 20}};

    player.equipWeapon(weapons[0]);
    player.equipArmor(armors[0]);

    string items[] = {
        "Health Potion", "Mana Potion", "Rusty Dagger", "Iron Shield", "Thunder Mace",
        "Leather Armor", "Chainmail", "Steel Armor", "Dagger", "Spear", "Short Bow",
        "Battle Axe", "Crossbow", "Flaming Sword", "Wooden Sword", "Cloth"};

    for (auto &item : items)
        player.inventory[item] = 0;

    int weaponSize = sizeof(weapons) / sizeof(weapons[0]);
    int armorSize = sizeof(armors) / sizeof(armors[0]);
    int potionSize = sizeof(potions) / sizeof(potions[0]);

    // --- MAIN MENU ---
    while (choice != 0)
    {
        clearScreen();
        std::cout << std::endl;
        textCenter("==============================================");
        textCenter("               HERO'S LEDGER                  ");
        textCenter("==============================================");
        std::cout << std::endl;

        if (!gameStarted)
            std::cout << "1. Start new game" << std::endl;
        else
            std::cout << "1. Resume game" << std::endl;

        std::cout << "2. Save game" << std::endl;
        std::cout << "3. Load game" << std::endl;
        std::cout << "4. Instructions" << std::endl;
        std::cout << "0. Quit\n" << std::endl;

        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice)
        {
        case 1:
            gameMenu(player, weapons, weaponSize, armors, armorSize, potions, potionSize);
            gameStarted = true;
            break;

        case 2:
            saveGameMenu(player);
            break;

        case 3:
            loadGameMenu(player);
            gameStarted = true;
            break;

        case 4:
            instructions();
            break;

        case 0:
            std::cout << "Exiting game...\n";
            break;

        default:
            textCenter("Invalid option, try again.", 50);
            std::cin.get();
            break;
        }
    }

    return 0;
}
