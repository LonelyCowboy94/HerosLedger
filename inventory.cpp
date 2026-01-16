#include "player.h"
#include "utils.h"
#include "game.h"
#include <iostream>
#include <vector>

void inventoryMenu(Player &player, Weapon weapons[], int weaponSize, Armor armors[], int armorSize)
{
    int choice = -1;
    while (choice != 0)
    {
        clearScreen(); 
        std::cout << std::endl;
        textCenter("--> Thy Inventory <--");
        std::cout << std::endl;
        
       
        std::cout << "\nWeapon: " << (player.weapon.name.empty() ? "None" : player.weapon.name) 
                  << " (Dmg: " << player.weapon.damage << ")";
        std::cout << "\nArmor : " << (player.armor.name.empty() ? "None" : player.armor.name) 
                  << " (Def: " << player.armor.defense << ")\n" << std::endl;

       
        int idx = 1;
        std::vector<std::string> keys;
        for (auto &item : player.inventory)
        {
            if (item.second > 0)
            {
                std::cout << idx << ". " << item.first << " x" << item.second << "\n";
                keys.push_back(item.first);
                idx++;
            }
        }

        std::cout << "\nPress 'e' to equip an item";
        std::cout << "\n0. Back\n\n";

        showPlayerStatus(player); 
        std::cout << "Your choice: ";
        std::string input;
        std::cin >> input;

        if (input == "0")
            break;
        else if (input == "e" || input == "E")
        {
            clearScreen();
            if (keys.empty())
            {
                textCenter("You have nothing to equip!", 50);
                textCenter("Press Enter to continue...", 50);
                std::cin.ignore();
                std::cin.get();
                continue;
            }

            textCenter("Select item number to equip:", 50);
            std::cout << std::endl;
            int idx = 1;
std::vector<std::string> keys; 
for (auto &item : player.inventory)
{
    if (item.second > 0)
    {
        std::cout << idx << ". " << item.first << " x" << item.second << "\n";
        keys.push_back(item.first);
        idx++;
    }
}
std::cout << std::endl;
std::cout << "Your choice: ";


if (keys.empty())
{
    std::cout << "Inventory is empty.\n";
}
            int equipIdx;
            std::cin >> equipIdx;

            clearScreen();
            if (equipIdx < 1 || equipIdx > (int)keys.size())
            {
                textCenter("Invalid selection!", 50);
                textCenter("Press Enter to continue...", 50);
                std::cin.ignore();
                std::cin.get();
                continue;
            }

            std::string selectedItem = keys[equipIdx - 1];

            bool equipped = false;
            for (int i = 0; i < weaponSize; i++)
            {
                if (weapons[i].name == selectedItem)
                {
                    player.equipWeapon(weapons[i]);
                    textCenter("Equipped weapon: " + selectedItem, 50);
                    equipped = true;
                    break;
                }
            }

          
            if (!equipped)
            {
                for (int i = 0; i < armorSize; i++)
                {
                    if (armors[i].name == selectedItem)
                    {
                        player.equipArmor(armors[i]);
                        textCenter("Equipped armor: " + selectedItem, 50);
                        equipped = true;
                        break;
                    }
                }
            }

            if (!equipped)
            {
                textCenter(selectedItem + " can't be equipped!", 50);
            }

            textCenter("Press Enter to continue...", 50);
            std::cin.ignore();
            std::cin.get();
        }
        else
        {
            clearScreen();
            
            int numChoice = std::stoi(input);
            if (numChoice < 1 || numChoice > (int)keys.size())
            {
                textCenter("Invalid selection!", 50);
                textCenter("Press Enter to continue...", 50);
                std::cin.ignore();
                std::cin.get();
            }
        }
    }
}
