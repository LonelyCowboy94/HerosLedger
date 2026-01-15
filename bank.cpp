#include "bank.h"
#include "player.h"
#include <iostream>

int bankMenu(Player &player)
{
    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\n\t--> Welcome to the Treasury Hall <--\n"
                  << std::endl;
        std::cout << "1. Deposit Gold\n2. Withdraw Gold\n3. Buy Diamonds\n4. Sell Diamonds \n\n0. Back\n"
                  << std::endl;

        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cout << "____________________\n";

        switch (choice)
        {
        case 1:
        {
            int amount;
            std::cout << "\nEnter amount to deposit: ";
            std::cin >> amount;
            if (amount > player.gold)
            {
                std::cout << "\n>> You don't have enough gold to deposit that amount! <<\n"
                          << std::endl;
                break;
            }
            else
            {
                player.gold -= amount;
                player.bankGold += amount;
                std::cout << "\n\t> You have deposited " << amount << " gold safely in the bank. <\n"
                          << std::endl;
                          std::cout<<"  Bank: "<< player.bankGold << " gold"<< std::endl;
                          std::cout<<"  At Belt: "<< player.gold << " gold"<< std::endl;
                          std::cout<< "___________________"<< std::endl;

                choice = 0;
                break;
            }
        }
        case 2:
        {
            int amount;
            std::cout << "\nEnter amount to withdraw: ";
            std::cin >> amount;
            if (amount > player.bankGold)
            {
                std::cout << "\n>> You don't have enough gold in the bank to withdraw that amount! <<\n"
                          << std::endl;
                break;
            }
            else
            {
                player.bankGold -= amount;
                player.gold += amount;
                std::cout << "\n\t> You have withdrawn " << amount << " gold from the bank. <\n"
                          << std::endl;
                          std::cout<<"  Bank: "<< player.bankGold << " gold"<< std::endl;
                          std::cout<<"  At Belt: "<< player.gold << " gold"<< std::endl;
                          std::cout<< "___________________"<< std::endl;

                choice = 0;
                break;
            }
        }
        case 3:
        {
            int amount;
            std::cout << "\nPrice per diamond: 800 gold\n";
            std::cout << "\nEnter number of diamonds to buy: ";
            std::cin >> amount;
            int cost = amount * 800; 
            if (player.bankGold < cost)
            {
                std::cout << "\n>> You don't have enough gold in the bank to buy that many diamonds! <<\n"
                          << std::endl;
                break;
            }
            else
            {
                player.bankGold -= cost;
                player.diamonds += amount;
                std::cout << "\n\t> You have purchased " << amount << " diamonds. <\n"
                          << std::endl;
                          std::cout<<"  Bank: "<< player.bankGold << " gold"<< std::endl;
                          std::cout<<"  At Belt: "<< player.gold << " gold"<< std::endl;
                          std::cout<< "___________________"<< std::endl;

                choice = 0;
                break;
            }
        }
        case 4: {
            int amount;
            std::cout << "\nSell price per diamond: 500 gold\n";
            std::cout << "\nEnter number of diamonds to sell: ";
            std::cin >> amount;
            if (player.diamonds < amount)
            {
                std::cout << "\n>> You don't have that many diamonds to sell! <<\n"
                          << std::endl;
                break;
            }
            else
            {
                player.diamonds -= amount;
                int sellPrice = amount * 500; 
                player.bankGold += sellPrice;
                std::cout << "\n\t> You have sold " << amount << " diamonds for " << sellPrice << " gold. <\n"
                          << std::endl;
                          std::cout<<"  Bank: "<< player.bankGold << " gold"<< std::endl;
                          std::cout<<"  At Belt: "<< player.gold << " gold"<< std::endl;
                          std::cout<< "___________________"<< std::endl;

                choice = 0;
                break;
        }
    }
}
    }
    return 0;
}