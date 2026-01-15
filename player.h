#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <map>
#include <string>

struct Weapon {
    std::string name;
    int damage;
    int price;
};

struct Armor {
    std::string name;
    int defense;
    int price;
};

struct Potion {
    std::string name;
    int effectAmount;
    int price;
};

struct Player {
    int hp;
    int xp;
    int gold;
    int bankGold;
    int diamonds;

    Weapon weapon;
    Armor armor;

    std::map<std::string, int> inventory;
    std::map<std::string, int> stash;

    bool isWantedInVillage = false;  
    bool villageBlessed = false;

    void equipWeapon(const Weapon& newWeapon) {
        if(!weapon.name.empty()) {
            inventory[weapon.name]++;
        }
        weapon = newWeapon;
    }

    void equipArmor(const Armor& newArmor) {
        if(!armor.name.empty()) {
            inventory[armor.name]++;
        }
        armor = newArmor;
    }

    void unequipWeapon() {
        if (!weapon.name.empty()) {
            inventory[weapon.name]++;
            weapon = {"", 0, 0};
        }
    }

    void unequipArmor() {
        if (!armor.name.empty()) {
            inventory[armor.name]++;
            armor = {"", 0, 0};
        }
    }

    void respawn() {
        hp = 100;     
        gold = 0;         
        bankGold = 0;  
        diamonds = 0;   
        inventory.clear(); 
        
    }
};


#endif // PLAYER_H_INCLUDED
