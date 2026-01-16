#include "game.h"
#include "utils.h"
#include <iostream>

using namespace std;

int gameMenu(Player &player, Weapon weapons[], int weaponSize,
             Armor armors[], int armorSize, Potion potions[], int potionSize)
{
    int choice2 = -1;

    while (choice2 != 0) {
        cout << "\n\t--> Where doth your journey lead, noble warrior? <--" << endl;
        cout << "\n1. Market Square \n2. Treasury Hall \n3. Adventure \n4. Village \n5. Inventory \n\n0. Exit game\n" << endl;
        showPlayerStatus(player);
        cout << "Your choice: ";
        cin >> choice2;
        clearScreen();

        switch(choice2){
            case 1:
                shop(player, weapons, weaponSize, armors, armorSize, potions, potionSize);
                break;

            case 2:
                bankMenu(player);
                break;

            case 3:
                adventureMenu(player);
                break;

            case 4:
                villageMenu(player);
                break;

            case 5:
            {
                inventoryMenu(player, weapons, weaponSize, armors, armorSize);
                break;
            }

            case 0:
                break;

            default:
                cout << "\n\t# Incorrect option. Choose one from the menu. #" << endl;
                break;
        }
    }

    return 0;
}

void instructions()
{
    int choice = -1;
    while (choice != 0)
    {
        clearScreen();
        textCenter("==============================================");
        textCenter("                 INSTRUCTIONS                  ");
        textCenter("==============================================");
        std::cout << std::endl;

        std::cout << "Welcome to HERO'S LEDGER, brave adventurer!" << std::endl << std::endl;

        std::cout << "1. Your goal:" << std::endl;
        std::cout << "   Explore the realm, complete quests, and grow stronger." << std::endl;
        std::cout << "   Equip weapons and armor, gather items, gold and diamonds, and survive adventures." << std::endl << std::endl;

        std::cout << "2. Stats & Health:" << std::endl;
        std::cout << "   - HP       : Your health points. Keep an eye on it!" << std::endl;
        std::cout << "   - XP       : Gain experience to become stronger." << std::endl;
        std::cout << "   - Gold     : Can be used to buy items and gear." << std::endl;
        std::cout << "   - Bank     : Safely store extra gold." << std::endl;
        std::cout << "   - Diamonds : Rare currency. Can be sold in bank or used for special enchantments later." << std::endl;
        std::cout << "   Tip: You can use potions from your inventory to heal during adventures." << std::endl << std::endl;

        std::cout << "3. Inventory & Equipment:" << std::endl;
        std::cout << "   - Weapons and armor can be equipped from your inventory." << std::endl;
        std::cout << "   - Potions restore HP or mana. Use wisely before or during fights." << std::endl;
        std::cout << "   - You can buy items in the Market Square and sell excess gear or potions in the bank." << std::endl << std::endl;

        std::cout << "4. Shops & Village:" << std::endl;
        std::cout << "   - Market Square: Buy weapons, armor, and potions." << std::endl;
        std::cout << "   - Treasury Hall: Deposit or withdraw gold. You can also sell diamonds here to afford gear early on." << std::endl;
        std::cout << "   - Village: Interact with NPCs, accept quests, or try risky actions like stealing." << std::endl;
        std::cout << "     > Warning: If you steal, villagers may attack you!" << std::endl;
        std::cout << "     > You can confess in the church to reset your wanted status." << std::endl << std::endl;

        std::cout << "5. Adventure:" << std::endl;
        std::cout << "   - Go on quests, fight monsters, and explore dungeons." << std::endl;
        std::cout << "   - Always monitor your HP and use potions to survive." << std::endl << std::endl;

        std::cout << "0. Back" << std::endl;
        std::cout << "\nYour choice: ";
        std::cin >> choice;
    }

    clearScreen(); 
}