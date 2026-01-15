#pragma once
#include "player.h"
#include <string>

struct Monster {
    std::string name;
    int hp;
    int damageMin;
    int damageMax;
    int xpReward;
    int goldReward;
    bool isBoss;
};

struct Crate {
    std::string name;
    int gold;
    int itemChance;    // % šanse za item
    int diamondChance; // % šanse za diamonds
};

struct Drop {
    std::string name;  
    int minQty;       
    int maxQty;      
    int chance;     
};

// Samo deklaracije, ne definicija!
extern int monsterCount;
extern int crateCount;
extern Monster monsters[];
extern Crate crates[];

// Funkcije koje ćeš kasnije definisati u adventure.cpp
int monsterAttack(Monster &m);
void handleMonsterDrop(Player &player, Monster &m, int dropCount, Drop drops[]);
void openCrate(Player &player, Crate &crate);
bool fightMonster(Player &player, Monster &m, int dropCount, Drop drops[]);
void adventureMenu(Player &player);
