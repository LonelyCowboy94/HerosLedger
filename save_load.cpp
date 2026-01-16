#include "save_load.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "utils.h"

bool saveGame(const Player &player, const std::string &filename) {
    std::ofstream out(filename);
    if(!out.is_open()) return false;

    out << player.hp << ' ' << player.mana << ' ' << player.xp << ' '
        << player.gold << ' ' << player.bankGold << ' ' << player.diamonds << '\n';

    out << player.weapon.name << '\t' << player.weapon.damage << '\t' << player.weapon.price << '\n';

    out << player.armor.name << '\t' << player.armor.defense << '\t' << player.armor.price << '\n';

    out << player.inventory.size() << '\n';
    for(auto &it : player.inventory)
        out << it.first << '\t' << it.second << '\n';

    out << player.stash.size() << '\n';
    for(auto &it : player.stash)
        out << it.first << '\t' << it.second << '\n';

    out << player.isWantedInVillage << ' ' << player.villageBlessed << '\n';

    out.close();
    return true;
}

bool loadGame(Player &player, const std::string &filename) {
    std::ifstream in(filename);
    if(!in.is_open()) return false;

    in >> player.hp >> player.mana >> player.xp >> player.gold >> player.bankGold >> player.diamonds;
    in.ignore();

    std::getline(in, player.weapon.name, '\t'); int dmg, price; in >> dmg >> price; in.ignore();
    player.weapon.damage = dmg; player.weapon.price = price;

    std::getline(in, player.armor.name, '\t'); int def, aPrice; in >> def >> aPrice; in.ignore();
    player.armor.defense = def; player.armor.price = aPrice;

    player.inventory.clear();
    int invCount; in >> invCount; in.ignore();
    for(int i=0;i<invCount;i++){
        std::string line; std::getline(in,line);
        size_t tab = line.find('\t');
        if(tab!=std::string::npos)
            player.inventory[line.substr(0,tab)] = std::stoi(line.substr(tab+1));
    }

    player.stash.clear();
    int stashCount; in >> stashCount; in.ignore();
    for(int i=0;i<stashCount;i++){
        std::string line; std::getline(in,line);
        size_t tab = line.find('\t');
        if(tab!=std::string::npos)
            player.stash[line.substr(0,tab)] = std::stoi(line.substr(tab+1));
    }

    in >> player.isWantedInVillage >> player.villageBlessed;
    in.close();
    return true;
}

// --- Save Menu ---
void saveGameMenu(Player &player){
    clearScreen();
    textCenter("--> Save Game <--");

    std::ifstream test("savefile.txt");
    if(test.good()) {
        textCenter("A save already exists. It will be overwritten!",50);
    }
    test.close();

    textCenter("Enter a name for this save (or leave empty for default):",50);
    std::cin.ignore();
    std::string name;
    std::getline(std::cin,name);

    if(name.empty()) name = "savefile.txt";
    else name += ".txt";

    if(saveGame(player,name))
        textCenter("Game saved successfully!",50);
    else
        textCenter("Failed to save game!",50);

    textCenter("Press Enter to continue...",50);
    std::cin.get();
}

// --- Load Menu ---
void loadGameMenu(Player &player){
    clearScreen();
    textCenter("--> Load Game <--");

    std::ifstream test("savefile.txt");
    if(!test.good()){
        textCenter("No save found.",50);
        textCenter("Press Enter to continue...",50);
        std::cin.ignore(); std::cin.get();
        return;
    }

    textCenter("Load the game from the existing save?",50);
    textCenter("Press Enter to continue...",50);
    std::cin.ignore(); std::cin.get();

    if(loadGame(player,"savefile.txt"))
        textCenter("Game loaded successfully!",50);
    else
        textCenter("Failed to load save!",50);

    textCenter("Press Enter to continue...",50);
    std::cin.get();
}
