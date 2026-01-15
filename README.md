# Hero's Ledger

**Hero's Ledger** is a text-based RPG written in **C++**, focused on classic role-playing mechanics: weapons, armor, potions, inventory management, shops, banking, villages, and adventures.  
Every action you take is recorded in the hero’s ledger — your progress, your choices, and your legacy.

---

## Getting the Project

You can get the project in two ways:

### Option 1: Clone with Git

```bash
git clone https://github.com/your-username/Heros-Ledger.git
cd Heros-Ledger
```

### Option 2: Download ZIP

On the GitHub repository page:
- Click the green **Code** button
- Select **Download ZIP**
- Extract the archive to a folder of your choice

---

## Compilation & Running

The game uses **standard C++** and does not depend on external libraries.

### Windows (MinGW / g++)

1. Open **Command Prompt** in the project folder.
2. Compile the project:

```bash
g++ *.cpp -o HeroLedger
```

3. Run the game:

```bash
HeroLedger.exe
```

---

### Linux

1. Open **Terminal** in the project folder.
2. Compile the project:

```bash
g++ *.cpp -o HeroLedger
```

3. Run the game:

```bash
./HeroLedger
```

---

### macOS / iOS (Command Line Tools)

1. Open **Terminal** in the project folder.
2. Compile the project:

```bash
g++ *.cpp -o HeroLedger
```

3. Run the game:

```bash
./HeroLedger
```

> Note: Running on a physical iOS device requires porting through Xcode. The current version is designed as a terminal-based game.

---

## Project Structure

```
Hero's-Ledger/
│
├── *.cpp          # Source files
├── *.h            # Header files
├── .gitignore     # Ignored build artifacts
└── README.md      # Project documentation
```

---

## Features

- Weapon, armor, and potion systems
- Inventory management
- Buy & sell mechanics
- Bank, diamonds and gold storage
- Village and adventure menus
- Fully menu-driven gameplay
- Clean modular C++ structure

---

## Notes

- Ensure **g++** is installed and available in your PATH
- Build files (`.exe`, `.o`, binaries) are intentionally excluded via `.gitignore`
- This project is actively developed and designed for learning and expansion

---

**Write your story. Balance your gold. Forge your legacy.**
