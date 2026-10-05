#include "Game.h"

#include <iostream>
#include <limits>

Game::Game()
{
    running = true;
}

void Game::DisplayTitle() const
{
    std::cout << "====================================\n";
    std::cout << "        CRYPT OF THE DAMNED\n";
    std::cout << "====================================\n";
}

void Game::DisplayMainMenu() const
{
    std::cout << "\n1. Start Game\n";
    std::cout << "2. View Player Stats\n";
    std::cout << "3. View Inventory\n";
    std::cout << "4. Exit\n";
    std::cout << "\nEnter choice: ";
}

int Game::GetMenuChoice(int minChoice, int maxChoice) const
{
    int choice;

    while (true)
    {
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number: ";
        }
        else if (choice < minChoice || choice > maxChoice)
        {
            std::cout << "Please enter a number between "
                << minChoice << " and " << maxChoice << ": ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
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
    std::string playerName;

    std::cout << "\nEnter your character's name: ";
    std::getline(std::cin, playerName);

    if (playerName.empty())
    {
        playerName = "Nameless";
    }

    player.SetName(playerName);

    std::cout << "\nWelcome, " << player.GetName() << ".\n";
    std::cout << "You descend into the Crypt of the Damned...\n";

    Enemy enemy("Skeleton Warrior", 40, 8, 10);

    StartCombat(enemy);
}

void Game::StartCombat(Enemy& enemy)
{
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
        std::cout << "\nEnter choice: ";

        int choice = GetMenuChoice(1, 4);

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
        std::cout << "\nYou have fallen in the Crypt of the Damned...\n";
        running = false;
    }
}