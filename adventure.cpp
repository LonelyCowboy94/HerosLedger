#include "adventure.h"
#include "player.h"
#include "utils.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>  

Monster monsters[] = {
    {"Goblin", 30, 5, 10, 10, 15, false},
    {"Wolf", 40, 8, 12, 12, 20, false},
    {"Bandit", 50, 10, 15, 15, 25, false},
    {"Orc", 60, 12, 18, 20, 35, false},
    {"Troll", 80, 15, 25, 30, 50, false},
    //BOSSES
    {"Orc Chieftain", 120, 20, 30, 50, 80, true},
    {"Dark Sorcerer", 150, 25, 35, 70, 100, true},
    {"Dragon", 300, 30, 50, 150, 200, true}
};

Crate crates[] = {
    {"Wooden Crate", 20, 30, 0},
    {"Iron Crate", 50, 50, 5},
    {"Golden Crate", 100, 60, 15},
    {"Ancient Crate", 100, 70, 33} 
};

  Drop drops[] = {
    {"Health Potion", 1, 1, 50},
    {"Mana Potion", 1, 1, 50},
    {"Rusty Dagger", 1, 1, 20},
    {"Iron Shield", 1, 1, 15},
    {"Thunder Mace", 1, 1, 10},
    {"Leather Armor", 1, 1, 25},
    {"Chainmail", 1, 1, 20},
    {"Steel Armor", 1, 1, 10},
    {"Dagger", 1, 1, 20},
    {"Spear", 1, 1, 15},
    {"Short Bow", 1, 1, 15},
    {"Battle Axe", 1, 1, 10},
    {"Crossbow", 1, 1, 10},
    {"Flaming Sword", 1, 1, 5}
};

 

int monsterCount = sizeof(monsters) / sizeof(monsters[0]);
int crateCount = sizeof(crates) / sizeof(crates[0]);
int dropCount = sizeof(drops) / sizeof(drops[0]);

void adventureMenu(Player &player) {
    srand(time(0)); // random seed

    int choice = -1;
    while(choice != 0) {
        std::cout << "\n\t--> Adventure Menu <--\n";
        std::cout << "\n1. Explore Forest (random monster)\n";
        std::cout << "2. Search a Crate\n";
        std::cout << "\n0. Back\n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        clearScreen();

        switch(choice) {
            case 1: {
    Monster &m = monsters[rand() % monsterCount];
    bool alive = fightMonster(player, m, dropCount, drops);
    if(!alive) {
        std::cout << "\nReturning to main menu...\n";
        return;
    }
    break;
}

            case 2: {
                Crate &c = crates[rand() % crateCount];
                openCrate(player, c);
                break;
            }
            case 0: break;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

// ----FUNCTIONS----

// MONSTER ATTACK DAMAGE
int monsterAttack(Monster &m) {
    return m.damageMin + rand() % (m.damageMax - m.damageMin + 1);
}

// KILL MONSTER AND HANDLE DROP
void handleMonsterDrop(Player &player, Monster &m, int dropCount, Drop drops[]) {
    // Gold i XP reward
    std::cout << "\n> You defeated " << m.name << "! <\n";
    player.gold += m.goldReward;
    player.xp += m.xpReward;
    std::cout << "> Gained " << m.goldReward << " gold and " << m.xpReward << " XP.\n";

    // Item drops
    std::cout << "> Loot:\n";
    bool anyDrop = false; // da znamo da li je nesto palo
    for(int i = 0; i < dropCount; i++) {
        if(rand() % 100 < drops[i].chance) {
            int qty = drops[i].minQty;
            if(drops[i].maxQty > drops[i].minQty) {
                qty += rand() % (drops[i].maxQty - drops[i].minQty + 1);
            }
            player.inventory[drops[i].name] += qty;
            std::cout << "  - " << qty << " x " << drops[i].name << "\n";
            anyDrop = true;
        }
    }

    if(!anyDrop) {
        std::cout << "  Nothing dropped...\n";
    }
}



// OPEN CRATE AND HANDLE REWARDS
void openCrate(Player &player, Crate &crate) {
    std::cout << "\n> You opened " << crate.name << "!\n";
    player.gold += crate.gold;
    std::cout << "> Found " << crate.gold << " gold!\n";

    if(rand() % 100 < crate.itemChance) {
        std::string item = "Mana Potion"; // random item
        player.inventory[item]++;
        std::cout << "> Found item: " << item << "\n";
    }

    if(crate.diamondChance > 0 && rand() % 100 < crate.diamondChance) {
        int diamondsFound = 1 + rand() % 3; // 1-3 diamonds
        player.diamonds += diamondsFound;
        std::cout << "> Found " << diamondsFound << " diamonds!\n";
    }
}

// FIGHT MONSTER
bool fightMonster(Player &player, Monster &m, int dropCount, Drop drops[]) {
    std::cout << "\nEncountered: " << m.name << " (HP: " << m.hp << ")\n";

    while(player.hp > 0 && m.hp > 0) {
        // Player attacks
        int playerDmg = player.weapon.damage + (rand() % 2) * player.xp / 10;
        m.hp -= playerDmg;
        std::cout << "You hit " << m.name << " for " << playerDmg
                  << " damage. (HP left: " << (m.hp > 0 ? m.hp : 0) << ")\n";

        if(m.hp <= 0) break;

        // Monster attacks
        int dmg = monsterAttack(m);
        player.hp -= dmg;
        std::cout << m.name << " hits you for " << dmg
                  << " damage! (Your HP: " << (player.hp > 0 ? player.hp : 0) << ")\n";

        if(player.hp <= 0) {
            std::cout << "\n> You have been defeated! <\n";
            std::cout << "\n> Respawning in the village... HP restored, gold reset, inventory lost.\n";
            player.respawn();
            return false; 
        }
    }

    handleMonsterDrop(player, m, dropCount, drops);
    return true; // igrač je preživeo
}