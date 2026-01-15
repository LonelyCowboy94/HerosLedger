#include <iostream>
#include "game.h"
using namespace std;

int main() {
    int choice = 0;
    bool gameStarted = false;
    string next;

    while(choice != 3) {
        !gameStarted ? cout << "\n1. Start the game" << endl : cout << "\n1. Resume game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quit\n" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << "____________________\n";

        switch(choice) {
            case 1: {
            gameMenu();
            gameStarted = true;
            break;
            }
            {
            case 2: instructions();
            break;
            }
            case 3: {
                break;
            }
        default: {
            cout << "\n\t# Incorect option. Choose one from the menu. #" << endl;
            break;
            }
        }

    }

    return 0;
}
