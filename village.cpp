#include "village.h"
#include "utils.h"
#include <iostream>
#include <cstdlib> 
#include <vector>

int villageMenu(Player &player)
{
    int choice = -1;

  
    if(player.isWantedInVillage && !player.villageBlessed) {
        if(rand() % 10 < 6) { 
            int dmg = 30 + rand() % 21; 
            player.hp -= dmg;
            std::cout << "\n\t> Villagers attack you as you enter! You lose " << dmg << " HP! <\n";
        }
    }

    while(choice != 0) {
        std::cout << "\n\t--> Village Square <--\n"<< std::endl;
        std::cout <<
        "1. Go Home (Stash)\n"
        "2. Village Cooperative\n"
        "3. Steal from Houses\n"
        "4. Church\n\n"
        "0. Back\n\n";

        std::cout << "Your choice: ";
        std::cin >> choice;
        clearScreen();

        switch(choice) {
            case 1: homeStash(player); break;
            case 2: cooperative(player); break;
            case 3: stealFromVillage(player); break;
            case 4: church(player); break;
            case 0: break;
            default: std::cout << "Incorrect option.\n"; break;
        }
    }

    return 0;
}

// --------------------- FUNCTIONS ---------------------

void homeStash(Player &player) {
    int choice = -1;
    while(choice != 0) {
        std::cout << "\n\t--> Your Home / Stash <--\n" << std::endl;
        std::cout << "1. Deposit item\n2. Withdraw item\n3. View stash\n\n0. Back\n";
        std::cout << "\nYour choice: ";
        std::cin >> choice;
        std::cout << "\n____________________\n";

        switch(choice) {
            case 1: {
                if(player.inventory.empty()) {
                    std::cout << "\n\t> You have nothing to deposit! <\n";
                    break;
                }
                std::cout << "Your inventory:\n" << std::endl;
                int idx = 1;
                std::vector<std::string> keys;
                for(auto &it : player.inventory) {
                    if(it.second > 0) { 
                        std::cout << idx << ". " << it.first << " x" << it.second << "\n";
                        keys.push_back(it.first);
                        idx++;
                    }
                }
                std::cout << "\n0. Back\n";
                int sel;
                std::cout << "\nSelect item number to place in your stash: ";
                std::cin >> sel;
                if(sel < 0 || sel > (int)keys.size()) { std::cout << "Invalid!\n"; break; }
                if(sel == 0) break;
                std::string item = keys[sel-1];
                int qty;
                std::cout << "Quantity to place into stash: "; std::cin >> qty;
                if(player.inventory[item] >= qty) {
                    player.inventory[item] -= qty;
                    player.stash[item] += qty;
                    std::cout << "\n\t> You placed " << qty << " " << item << " into stash. <\n";
                } else std::cout << "\n\t> You don't have that many! <\n";
                break;
            }

            case 2: { 
                if(player.stash.empty()) {
                    std::cout << "\n\t> Stash is empty! <\n";
                    break;
                }
                std::cout << "Your stash:\n" << std::endl;
                int idx = 1;
                std::vector<std::string> keys;
                for(auto &it : player.stash) {
                    if(it.second > 0) {
                        std::cout << idx << ". " << it.first << " x" << it.second << "\n";
                        keys.push_back(it.first);
                        idx++;
                    }
                }
                std::cout << "\n0. Back\n";
                int sel;
                std::cout << "\nSelect item number to take: ";
                std::cin >> sel;
                if(sel < 0 || sel > (int)keys.size()) { std::cout << "Invalid!\n"; break; }
                if(sel == 0) break;

                std::string item = keys[sel-1];
                int qty;
                std::cout << "Quantity to take: "; std::cin >> qty;
                if(player.stash[item] >= qty) {
                    player.stash[item] -= qty;
                    player.inventory[item] += qty;
                    std::cout << "\n\t> Picked up " << qty << " " << item << " from your stash. <\n";

                } else std::cout << "\n\t> Not enough in stash! <\n";
                break;
            }

            case 3: { 
                if(player.stash.empty()) {
                    std::cout << "---- Stash is empty! ----\n";
                    std::cout << "-----------------------\n";
                    break;
                }
                std::cout << "---- Stash Contents ----\n";
                int idx = 1;
                for(auto &it : player.stash) {
                    if(it.second > 0)
                        std::cout << idx++ << ". " << it.first << " x" << it.second << "\n";
                }
                std::cout << "-----------------------\n";
                break;
            }

            case 0: break;

            default: std::cout << "\n\t> Invalid option! <\n"; break;
        }
    }
}
void cooperative(Player &player) {
    int gold = 50 + rand() % 51; 
    player.gold += gold;
    std::cout << "> You helped villagers and earned " << gold << " gold. <\n";
}

void stealFromVillage(Player &player) {
    std::cout << "\t> You sneak into a house... <"<<std::endl;

    if(rand() % 2 == 0) {
        int loot = 40 + rand() % 21;
        player.gold += loot;
        player.isWantedInVillage = true;
        std::cout << "\t> You stole " << loot << " gold! Beware, villagers are suspicious. <\n";
    } else {
        int dmg = 20 + rand() % 21;
        player.hp -= dmg;
        player.isWantedInVillage = true;
        std::cout << "\t> You were caught! Lost " << dmg << " HP! <\n";
    }
}

void church(Player &player) {
    int donate;
    std::cout << "How much gold do you donate: ";
    std::cin >> donate;

    if(player.gold < donate) {
        std::cout << "\t> You don't have that much gold! <\n";
        return;
    }

    player.gold -= donate;

    if(donate >= 50) {
        player.isWantedInVillage ? std::cout << "\n\t> The villagers forgive you! You are now safe from attacks. <\n" : std::cout << "\n\t> May the blessings keep you safe. <\n";
        player.villageBlessed = true;
        player.isWantedInVillage = false;
    } else {
        std::cout << "\n\t> The villagers are not impressed. Donate at least 50 gold. <\n";
    }
}
