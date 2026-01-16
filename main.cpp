#include <iostream>
#include "utils.h"
#include "game.h"

using namespace std;

int main()
{
    clearScreen();
    int choice = 0;
    bool gameStarted = false;

    // --- Player setup (prebačeno ovde) ---
    Player player;
    player.hp = 100;
    player.xp = 0;
    player.gold = 2000;
    player.bankGold = 0;
    player.diamonds = 0;

    // Weapon i Armor mogu odmah da se opreme
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

    player.equipWeapon(weapons[0]);
    player.equipArmor(armors[0]);

    // Inventory inicijalizacija
    string items[] = {
        "Health Potion","Mana Potion","Rusty Dagger","Iron Shield","Thunder Mace",
        "Leather Armor","Chainmail","Steel Armor","Dagger","Spear","Short Bow",
        "Battle Axe","Crossbow","Flaming Sword","Wooden Sword","Cloth"
    };
    for (auto &item : items) player.inventory[item] = 0;

    // Velicine nizova
    int weaponSize = sizeof(weapons)/sizeof(weapons[0]);
    int armorSize = sizeof(armors)/sizeof(armors[0]);
    int potionSize = sizeof(potions)/sizeof(potions[0]);

    // --- Main menu loop ---
    while (choice != 3)
    {
        cout << endl;
        textCenter("==============================================");
        textCenter("               HERO'S LEDGER                  ");
        textCenter("==============================================");
        cout << endl;

        if (!gameStarted)
            cout << "\n1. Start the game" << endl;
        else
            cout << "\n1. Resume game" << endl;

        cout << "2. Instructions" << endl;
        cout << "3. Quit\n" << endl;

        cout << "Your choice: ";
        cin >> choice;
        clearScreen();

        switch (choice)
        {
            case 1:
                gameMenu(player, weapons, weaponSize, armors, armorSize, potions, potionSize);
                gameStarted = true;
                break;

            case 2:
                instructions();
                break;

            case 3:

                break;

            default:
                cout << "\n\t# Incorrect option. Choose one from the menu. #" << endl;
                break;
        }
    }

    return 0;
}
