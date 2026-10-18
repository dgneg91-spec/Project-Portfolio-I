#include "Game.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

Game::Game()
{
    running = true;
}

void Game::DisplayTitle() const
{
    std::cout << R"(
============================================================
                   CRYPT OF THE DAMNED
============================================================

                         ______
                      .-"      "-.
                     /            \
                    |              |
                    |,  .-.  .-.  ,|
                    | )(_o/  \o_)( |
                    |/     /\     \|
                    (_     ^^     _)
                     \__|IIIIII|__/
                      \ IIIIIIII /
                       `--------`

                   ENTER IF YOU DARE

============================================================
)";
}

void Game::DisplayMainMenu() const
{
    std::cout << "\n================ MAIN MENU ================\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. View Player Stats\n";
    std::cout << "3. View Inventory\n";
    std::cout << "4. Exit\n";
    std::cout << "===========================================\n";
    std::cout << "\nEnter choice: ";
}

void Game::DisplayEnemyArt(const std::string& enemyName) const
{
    if (enemyName == "Skeleton Warrior")
    {
        std::cout << R"(

             .-.
            (o.o)
             |=|
            __|__
           //.=|=.\\
          // .=|=. \\
          \\ .=|=. //
           \\(_=_)//
            (:| |:)
             || ||
             () ()
             || ||
             || ||
             ==' '==

        SKELETON WARRIOR
)";
    }
    else if (enemyName == "Crypt Ghoul")
    {
        std::cout << R"(

              .------.
             /        \
            /  _    _  \
           |  / \  / \  |
           |  \_/  \_/  |
           |     /\     |
           |   .____.   |
            \  \____/  /
             \        /
              \______/
              /|    |\
             / |    | \
            /  |    |  \
               |    |
              /      \

           CRYPT GHOUL
)";
    }
    else if (enemyName == "Bone Knight")
    {
        std::cout << R"(

                /\
               /  \
              /____\
             |      |
             |  /\  |
             | |  | |
             | |  | |
           __|_|__|_|__
          /            \
         /   ________   \
        |   /        \   |
        |  |          |  |
        |  |          |  |
        |  |__________|  |
         \              /
          \____________/

             BONE KNIGHT
)";
    }
}

void Game::DisplayVictoryArt() const
{
    std::cout << R"(

============================================================

                     VICTORY

                  \       /
                   \     /
                    \   /
                     \ /
                      V

                 ______________
                |              |
                |   SURVIVOR   |
                |______________|

          THE CRYPT COULD NOT CLAIM YOU

============================================================
)";
}

void Game::DisplayDeathArt() const
{
    std::cout << R"(

============================================================

                    YOU HAVE FALLEN

                        _____
                       /       \
                      |  x   x  |
                      |    ^    |
                      |  \___/  |
                       \_______/

                   REST AMONG THE DEAD

============================================================
)";
}

int Game::GetMenuChoice(int minChoice, int maxChoice) const
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        try
        {
            size_t charactersUsed = 0;
            int choice = std::stoi(input, &charactersUsed);

            if (charactersUsed != input.length())
            {
                throw std::invalid_argument("Extra characters entered.");
            }

            if (choice < minChoice || choice > maxChoice)
            {
                throw std::out_of_range("Choice outside valid range.");
            }

            return choice;
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Invalid input. Please enter a whole number between "
                << minChoice << " and " << maxChoice << ": ";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "That choice is out of range. Please enter a number between "
                << minChoice << " and " << maxChoice << ": ";
        }
    }
}

void Game::Run()
{
    DisplayTitle();

    while (running)
    {
        DisplayMainMenu();

        int choice = GetMenuChoice(1, 4);

        switch (choice)
        {
        case 1:
            StartGame();
            break;

        case 2:
            player.DisplayStats();
            break;

        case 3:
            player.DisplayInventory();
            break;

        case 4:
            std::cout << "\nLeaving the Crypt of the Damned...\n";
            running = false;
            break;
        }
    }
}

void Game::StartGame()
{
    player.Reset();

    std::string playerName;

    std::cout << "\nEnter your character's name: ";
    std::getline(std::cin, playerName);

    if (playerName.empty())
    {
        playerName = "Nameless";
    }

    player.SetName(playerName);

    Item healingPotion("Healing Potion", "Healing", 30);
    player.AddItem(healingPotion);

    std::cout << "\nWelcome, " << player.GetName() << ".\n";
    std::cout << "You descend into the Crypt of the Damned...\n";
    std::cout << "A Healing Potion has been added to your inventory.\n";

    StartDungeon();
}

void Game::StartDungeon()
{
    std::vector<Enemy> enemies;

    enemies.push_back(Enemy("Skeleton Warrior", 40, 8, 10));
    enemies.push_back(Enemy("Crypt Ghoul", 55, 10, 15));
    enemies.push_back(Enemy("Bone Knight", 70, 12, 25));

    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (!player.IsAlive())
        {
            break;
        }

        std::cout << "\n============================================================\n";
        std::cout << "                         FLOOR " << i + 1 << "\n";
        std::cout << "============================================================\n";

        if (i == 0)
        {
            std::cout << "\nCold air crawls across your skin.\n";
            std::cout << "Bones scrape against the stone ahead...\n";
        }
        else if (i == 1)
        {
            std::cout << "\nA rotten stench fills the corridor.\n";
            std::cout << "Something hungry moves in the darkness...\n";
        }
        else if (i == 2)
        {
            std::cout << "\nHeavy footsteps shake the crypt floor.\n";
            std::cout << "An armored figure blocks your path...\n";
        }

        StartCombat(enemies[i]);

        if (player.IsAlive() && i < enemies.size() - 1)
        {
            std::cout << "\nYou survived Floor " << i + 1 << ".\n";
            std::cout << "You continue deeper into the crypt...\n";

            Item healingPotion("Healing Potion", "Healing", 30);
            player.AddItem(healingPotion);

            std::cout << "You found another Healing Potion.\n";
        }
    }

    if (player.IsAlive())
    {
        DisplayVictoryArt();

        std::cout << "\nYou survived every encounter in the crypt!\n";
        std::cout << "Final Gold: " << player.GetGold() << "\n";
    }
}

void Game::StartCombat(Enemy& enemy)
{
    DisplayEnemyArt(enemy.GetName());

    std::cout << "\nA " << enemy.GetName() << " appears!\n";

    while (player.IsAlive() && enemy.IsAlive())
    {
        std::cout << "\n----------------------------\n";
        std::cout << player.GetName() << " HP: "
            << player.GetHealth() << "/"
            << player.GetMaxHealth() << "\n";

        std::cout << enemy.GetName() << " HP: "
            << enemy.GetHealth() << "\n";

        std::cout << "\n1. Attack\n";
        std::cout << "2. Defend\n";
        std::cout << "3. View Stats\n";
        std::cout << "4. View Inventory\n";
        std::cout << "5. Use Item\n";
        std::cout << "\nEnter choice: ";

        int choice = GetMenuChoice(1, 5);

        switch (choice)
        {
        case 1:
            std::cout << "\nYou attack the "
                << enemy.GetName()
                << " for "
                << player.GetAttackPower()
                << " damage!\n";

            enemy.TakeDamage(player.GetAttackPower());
            break;

        case 2:
            std::cout << "\nYou prepare to defend yourself.\n";
            player.SetDefending(true);
            break;

        case 3:
            player.DisplayStats();
            continue;

        case 4:
            player.DisplayInventory();
            continue;

        case 5:
        {
            if (player.GetInventorySize() == 0)
            {
                std::cout << "\nYour inventory is empty.\n";
                continue;
            }

            player.DisplayInventory();

            std::cout << "\nChoose an item to use: ";

            int itemChoice = GetMenuChoice(1, player.GetInventorySize());

            bool itemUsed = player.UseItem(itemChoice - 1);

            if (!itemUsed)
            {
                continue;
            }

            std::cout << "Current Health: "
                << player.GetHealth()
                << "/"
                << player.GetMaxHealth()
                << "\n";

            continue;
        }
        }

        if (enemy.IsAlive())
        {
            std::cout << "\nThe "
                << enemy.GetName()
                << " attacks you for "
                << enemy.GetAttackPower()
                << " damage!\n";

            player.TakeDamage(enemy.GetAttackPower());
        }
    }

    if (player.IsAlive())
    {
        std::cout << "\nYou defeated the "
            << enemy.GetName()
            << "!\n";

        player.AddGold(enemy.GetGoldReward());

        std::cout << "You earned "
            << enemy.GetGoldReward()
            << " gold.\n";
    }
    else
    {
        DisplayDeathArt();

        std::cout << "\nYou have fallen in the Crypt of the Damned...\n";
        running = false;
    }
}