#include "shop.h"
#include "utils.h"
#include "player.h"
#include <iostream>

int shop(Player &player, Weapon weapons[], int weaponSize, Armor armors[], int armorSize, Potion potions[], int potionSize)
{
    int choice4 = -1;
    while (choice4 != 0)
    {
        std::cout << std::endl;
        textCenter("--> Welcome to the Bazaar <--");
        std::cout << std::endl;
        std::cout << "\n1. Weapons \n2. Potions \n3. Armor \n4. Sell Items \n\n0. Back\n"
                  << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice4;
        clearScreen();
        switch (choice4)
        {
        case 1:
        {
            buyWeapon(player, weapons, weaponSize);
            break;
        }
        case 2:
        {
            buyPotions(player, potions, potionSize);
            break;
        }
        case 3:
        {
            buyArmor(player, armors, armorSize);
            break;
        }
        case 4:
        {
            sellMenu(player, weapons, weaponSize, armors, armorSize, potions, potionSize);
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            std::cout << "Incorect option. Choose one from the menu." << std::endl;
            break;
        }
        }
    }

    return 0;
}

int buyArmor(Player &player, Armor armors[], int armorSize)
{
    int choice8 = -1;
    while (choice8 != 0)
    {
        std::cout << std::endl;
        textCenter("--> Guardian's Armory <--");
        std::cout << std::endl;
        std::cout << std::endl;

        for (int i = 1; i <= armorSize; i++)
        {
            std::cout << i << ". " << armors[i - 1].name << " - Defense: " << armors[i - 1].defense << " - Price: $" << (armors[i - 1].defense * 15) << std::endl;
        }
        std::cout << "\n0. Back" << std::endl;

        std::cout << "\nYour choice: ";
        std::cin >> choice8;
        clearScreen();

        for (int i = 1; i <= armorSize; i++)
        {
            if (choice8 == i)
            {
                if (player.armor.defense >= armors[i - 1].defense)
                {
                    std::cout << "\n\t> You already have a " << player.armor.name << " <" << std::endl;
                    choice8 = 0;
                    break;
                }
                else if (player.gold >= armors[i - 1].price)
                {
                    player.unequipArmor();
                    player.equipArmor(armors[i - 1]);
                    player.gold -= armors[i - 1].price;
                    std::cout << "\n\t> Equipped: " << player.armor.name << " (Def: " << player.armor.defense << ") <" << std::endl;
                    choice8 = 0;
                }
                else
                {
                    std::cout << ">> Not enough gold! <<\n____________________\n";
                }
            }
        }
    }

    return 0;
}

int buyPotions(Player &player, Potion potions[], int potionSize)
{
    int choice7 = -1;
    while (choice7 != 0)
    {
        std::cout << std::endl;
        textCenter("--> Alchemist's Shoppe <--");
        std::cout << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < potionSize; i++)
        {
            std::cout << i + 1 << ". " << potions[i].name << " - Effect Amount: " << potions[i].effectAmount << " - Price: $" << potions[i].price << std::endl;
        }
        std::cout << "\n0. Back" << std::endl;
        std::cout << "\nYour choice: ";
        std::cin >> choice7;
        clearScreen();

        for (int i = 1; i <= potionSize; i++)
        {
            if (choice7 == i)
            {
                if (player.gold >= potions[i - 1].price)
                {
                    player.inventory[potions[i - 1].name]++;
                    player.gold -= potions[i - 1].price;
                    std::cout << "\n\t> Purchased: " << potions[i - 1].name << " x1 <" << std::endl;
                    choice7 = 0;
                }
                else
                {
                    std::cout << ">> Not enough gold! <<\n____________________\n";
                }
            }
        }
    }

    return 0;
}

int buyWeapon(Player &player, Weapon weapons[], int weaponSize)
{
    int choice5 = -1;
    while (choice5 != 0)
    {
        std::cout << std::endl;
        textCenter("--> Armory <--");
        std::cout << std::endl;
        std::cout << std::endl;
       
        for (int i = 1; i <= weaponSize; i++)
        {
            std::cout << i << ". " << weapons[i - 1].name << " - Damage: " << weapons[i - 1].damage << " - Price: $" << weapons[i - 1].price << std::endl;
        }

        std::cout << "\n0. Back" << std::endl;

        std::cout << "\nYour choice: ";
        std::cin >> choice5;
        clearScreen();

        for (int i = 1; i <= weaponSize; i++)
        {
            if (choice5 == i)
            {
                if (player.weapon.damage >= weapons[i - 1].damage)
                {
                    std::cout << "\n\t> You already have a " << player.weapon.name << " <" << std::endl;
                    choice5 = 0;
                    break;
                }
                else if (player.gold >= weapons[i - 1].price)
                {
                    player.unequipWeapon();
                    player.equipWeapon(weapons[i - 1]);
                    player.gold -= weapons[i - 1].price;
                    std::cout << "\n\t> Equipped: " << player.weapon.name << " (Dmg: " << player.weapon.damage << ") <" << std::endl;
                    choice5 = 0;
                }
                else
                {
                    std::cout << ">> Not enough gold! <<\n____________________\n";
                }
            }
        }
    }
    return 0;
}

void sellMenu(Player &player, 
              Weapon weapons[], int weaponSize, 
              Armor armors[], int armorSize, 
              Potion potions[], int potionSize) {

                std::cout << std::endl;
                textCenter("--> Sell Items <--");
                std::cout << std::endl;
  
    std::cout << "\nYour Inventory:\n";
    for(auto &item : player.inventory) {
        if(item.second > 0)
            std::cout << "- " << item.first << " x" << item.second << "\n";
    }

    if(!player.weapon.name.empty())
        std::cout << "- " << player.weapon.name << " (equipped weapon)\n";
    if(!player.armor.name.empty())
        std::cout << "- " << player.armor.name << " (equipped armor)\n";

        std::cout << "\n0. Back\n";

    std::string itemToSell;
    std::cout << "\nEnter the name of the item you want to sell: ";
    std::cin.ignore(); 
    std::getline(std::cin, itemToSell); 

    if(itemToSell == "0" || itemToSell.empty()) {
        clearScreen();
        return; 
    }
    sellItem(player, itemToSell, weapons, weaponSize, armors, armorSize, potions, potionSize);
    player.inventory.erase(itemToSell);
}


void sellItem(Player &player, const std::string& itemName,
              Weapon weapons[], int weaponSize,
              Armor armors[], int armorSize,
              Potion potions[], int potionSize) {

    int price = 0;

    for(int i = 0; i < weaponSize; i++) {
        if(weapons[i].name == itemName) {
            price = weapons[i].price;
            break;
        }
    }

    if(price == 0) {
        for(int i = 0; i < armorSize; i++) {
            if(armors[i].name == itemName) {
                price = armors[i].price;
                break;
            }
        }
    }

    if(price == 0) {
        for(int i = 0; i < potionSize; i++) {
            if(potions[i].name == itemName) {
                price = potions[i].price;
                break;
            }
        }
    }

    if(price == 0) {
        std::cout << "\n\t> " << itemName << " does not exist! <\n";
        return;
    }

    if(player.inventory[itemName] > 0) {
        player.inventory[itemName]--; 
        player.gold += static_cast<int>(price * 0.7);
        std::cout << std::endl;
        textCenter("> Sold one " + itemName + " for " + std::to_string(static_cast<int>(price*0.7)) + " gold <", 50);
        textCenter("=== gold at belt: " + std::to_string(player.gold) + " ===", 50);

        if(player.inventory[itemName] == 0)
            player.inventory.erase(itemName);

        return;
    }

    if(player.weapon.name == itemName) {
        player.unequipWeapon();
        player.gold += static_cast<int>(price * 0.7);
        std::cout << std::endl;
        textCenter("> Sold equipped " + itemName + " for " + std::to_string(static_cast<int>(price*0.7)) + " gold <", 50);
        textCenter("=== gold at belt: " + std::to_string(player.gold) + " ===", 50);
        return;
    }

    if(player.armor.name == itemName) {
        player.unequipArmor();
        player.gold += static_cast<int>(price * 0.7);
        std::cout << std::endl;
        textCenter("> Sold equipped " + itemName + " for " + std::to_string(static_cast<int>(price*0.7)) + " gold <", 50);
        textCenter("=== gold at belt: " + std::to_string(player.gold) + " ===", 50);
       
        return;
    }

    std::cout << "\n\t> You do not have " << itemName << " to sell! <\n";
}

