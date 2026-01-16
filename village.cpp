#include "village.h"
#include "utils.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <vector>

int villageMenu(Player &player)
{
    int choice = -1;

    if (player.isWantedInVillage && !player.villageBlessed)
    {
        if (rand() % 10 < 6)
        {
            int dmg = 30 + rand() % 21;
            player.hp -= dmg;
            std::cout << "\n\t> Villagers attack you as you enter! You lose " << dmg << " HP! <\n";
        }
    }

    while (choice != 0)
    {
        std::cout << std::endl;
        textCenter("--> Welcome to the Village Square <--");
        std::cout << std::endl;
        std::cout << std::endl;
        
        std::cout << "1. Go Home (Stash)\n"
                     "2. Village Cooperative\n"
                     "3. Steal from Houses\n"
                     "4. Church\n\n"
                     "0. Back\n\n";

                     showPlayerStatus(player);
        std::cout << "Your choice: ";
        std::cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            homeStash(player);
            break;
        case 2:
            cooperative(player);
            break;
        case 3:
            stealFromVillage(player);
            break;
        case 4:
            church(player);
            break;
        case 0:
            break;
        default:
            std::cout << "Incorrect option.\n";
            break;
        }
    }

    return 0;
}

// --------------------- FUNCTIONS ---------------------

void homeStash(Player &player)
{
    int choice = -1;

    while (choice != 0)
    {
        clearScreen();
        textCenter("--> Your Home / Stash <--");
        std::cout << std::endl;

        std::cout << "1. Deposit item\n2. Withdraw item\n3. View stash\n\n0. Back\n";
        showPlayerStatus(player);
        std::cout << "\nYour choice: ";
        std::cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1: 
        {
            textCenter("---- Deposit Item ----", 50);

            std::vector<std::string> keys;
            int idx = 1;
            for (auto &it : player.inventory)
            {
                if (it.second > 0)
                {
                    std::cout << idx << ". " << it.first << " x" << it.second << "\n";
                    keys.push_back(it.first);
                    idx++;
                }
            }

            if (keys.empty())
            {
                textCenter("You have nothing to deposit!", 50);
                textCenter("Press Enter to continue...", 50);
                std::cin.get(); std::cin.get();
                break;
            }

            std::cout << "\n0. Back\n";
            int sel = -1;
            while (sel != 0)
            {
                std::cout << "\nSelect item number to deposit: ";
                std::cin >> sel;
                if (sel < 0 || sel > (int)keys.size())
                {
                    textCenter("Invalid selection! Try again.", 50);
                    continue;
                }
                if (sel == 0) break;

                std::string item = keys[sel - 1];
                int qty;
                std::cout << "Quantity to deposit: ";
                std::cin >> qty;

                if (qty <= 0)
                {
                    textCenter("Cancelled deposit.", 50);
                    std::cin.get(); std::cin.get();
                    break;
                }

                if (qty > player.inventory[item])
                {
                    qty = player.inventory[item];
                    player.inventory[item] = 0;
                    player.stash[item] += qty;
                    textCenter("You deposited all available " + item + " (" + std::to_string(qty) + ").", 50);
                }
                else
                {
                    player.inventory[item] -= qty;
                    player.stash[item] += qty;
                    textCenter("You placed " + std::to_string(qty) + " " + item + " into stash.", 50);
                }

                textCenter("Press Enter to continue...", 50);
                std::cin.get(); std::cin.get();
                break;
            }

            break;
        }

        case 2: 
        {
            textCenter("---- Withdraw Item ----", 50);

            std::vector<std::string> keys;
            int idx = 1;
            for (auto &it : player.stash)
            {
                if (it.second > 0)
                {
                    std::cout << idx << ". " << it.first << " x" << it.second << "\n";
                    keys.push_back(it.first);
                    idx++;
                }
            }

            if (keys.empty())
            {
                textCenter("Stash is empty!", 50);
                textCenter("Press Enter to continue...", 50);
                std::cin.get(); std::cin.get();
                break;
            }

            std::cout << "\n0. Back\n";
            int sel = -1;
            while (sel != 0)
            {
                std::cout << "\nSelect item number to withdraw: ";
                std::cin >> sel;
                if (sel < 0 || sel > (int)keys.size())
                {
                    textCenter("Invalid selection! Try again.", 50);
                    continue;
                }
                if (sel == 0) break;

                std::string item = keys[sel - 1];
                int qty;
                std::cout << "Quantity to withdraw: ";
                std::cin >> qty;

                if (qty <= 0)
                {
                    textCenter("Cancelled withdrawal.", 50);
                    textCenter("Press Enter to continue...", 50);
                    std::cin.get(); std::cin.get();
                    break;
                }

                if (qty > player.stash[item])
                {
                    qty = player.stash[item];
                    player.stash[item] = 0;
                    player.inventory[item] += qty;
                    textCenter("You withdrew all available " + item + " (" + std::to_string(qty) + ").", 50);
                }
                else
                {
                    player.stash[item] -= qty;
                    player.inventory[item] += qty;
                    textCenter("You picked up " + std::to_string(qty) + " " + item + " from stash.", 50);
                }

                textCenter("Press Enter to continue...", 50);
                std::cin.get(); std::cin.get();
                break;
            }

            break;
        }

        case 3: 
        {
            textCenter("---- Stash Contents ----", 50);
            std::cout << std::endl;
            bool empty = true;
            int idx = 1;
            for (auto &it : player.stash)
            {
                if (it.second > 0)
                {
                    std::cout << idx++ << ". " << it.first << " x" << it.second << "\n";
                    empty = false;
                }
            }
            if (empty)
            {
                textCenter("Stash is empty!");
            }

            std::cout << "\n0. Back\n";
            textCenter("Press Enter to continue...", 50);
            std::cin.get(); std::cin.get();
            break;
        }

        case 0: 
            break;

        default:
            textCenter("Invalid option!", 50);
            textCenter("Press Enter to continue...", 50);
            std::cin.get(); std::cin.get();
            break;
        }
    }
}
void cooperative(Player &player)
{
    int gold = 50 + rand() % 51;
    player.gold += gold;
    std::cout << "> You helped villagers and earned " << gold << " gold. <\n";
    std::cout << "Gold at belt: " << player.gold << "\n";
}

void stealFromVillage(Player &player)
{
    textCenter("> You sneak into a house... <", 50);
    std::cout << std::endl;

    if (rand() % 2 == 0)
    {
        int loot = 40 + rand() % 21;
        player.gold += loot;
        player.isWantedInVillage = true;
        textCenter("> You stole " + std::to_string(loot) + " gold! Beware, villagers are suspicious. <", 50);
        std::cout << "Gold at belt: " << player.gold << "\n";
    }
    else
    {
        int dmg = 20 + rand() % 21;
        player.hp -= dmg;
        player.isWantedInVillage = true;
        textCenter("> You were caught! Lost " + std::to_string(dmg) + " HP! <", 50);

        if (player.hp <= 0)
        {
            textCenter("> You have died! Respawning in village... <", 50);
            player.respawn();
        }
        else
        {
            std::cout << "\n   Gold at belt: " << player.gold << "\n\n";
            showPlayerStatus(player);
        }
    }

    std::cout << std::endl;
    textCenter("Press Enter to continue...", 50);
    std::cin.get(); std::cin.get();
}


void church(Player &player)
{
    int donate;
    std::cout << "How much gold do you donate: ";
    std::cin >> donate;

    if (player.gold < donate)
    {
        std::cout << std::endl;
        textCenter("You don't have that much gold!", 50);
        std::cout << std::endl;
        return;
    }

    player.gold -= donate;

    if (donate >= 50)
    {
        if (player.isWantedInVillage)
{
    std::cout << std::endl;
    textCenter("> The villagers forgive you! <", 50);
    textCenter("You are now safe from attacks.", 50);
    std::cout << std::endl;
}
else
{
    std::cout << std::endl;
    textCenter("> May the blessings keep you safe. <", 50);
    std::cout << std::endl;
}
        player.villageBlessed = true;
        player.isWantedInVillage = false;
    }
    else
    {
        std::cout << "\n\t> The villagers are not impressed. Donate at least 50 gold. <\n";
    }
}
