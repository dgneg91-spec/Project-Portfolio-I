#include "Game.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <random>

Game::Game()
{
    running = true;
    currentEnemy = nullptr;
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

void Game::DisplayCombatStatus() const
{
    std::cout << "\n----------------------------\n";

    std::cout << player.GetName() << " HP: "
        << player.GetHealth() << "/"
        << player.GetMaxHealth() << "\n";

    std::cout << currentEnemy->GetName() << " HP: "
        << currentEnemy->GetHealth() << "\n";
}

void Game::DisplayCombatMenu() const
{
    std::cout << "\n1. Attack\n";
    std::cout << "2. Defend\n";
    std::cout << "3. View Stats\n";
    std::cout << "4. View Inventory\n";
    std::cout << "5. Use Item\n";
    std::cout << "\nEnter choice: ";
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

            int choice = std::stoi(
                input,
                &charactersUsed
            );

            if (charactersUsed != input.length())
            {
                throw std::invalid_argument(
                    "Extra characters entered."
                );
            }

            if (choice < minChoice || choice > maxChoice)
            {
                throw std::out_of_range(
                    "Choice outside valid range."
                );
            }

            return choice;
        }
        catch (const std::invalid_argument&)
        {
            std::cout
                << "Invalid input. Please enter a whole number between "
                << minChoice
                << " and "
                << maxChoice
                << ": ";
        }
        catch (const std::out_of_range&)
        {
            std::cout
                << "That choice is out of range. Please enter a number between "
                << minChoice
                << " and "
                << maxChoice
                << ": ";
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
            std::cout
                << "\nLeaving the Crypt of the Damned...\n";

            running = false;
            break;
        }
    }
}

void Game::StartGame()
{
    player.Reset();

    currentEnemy = nullptr;

    std::string playerName;

    std::cout
        << "\nEnter your character's name: ";

    std::getline(
        std::cin,
        playerName
    );

    if (playerName.empty())
    {
        playerName = "Nameless";
    }

    player.SetName(playerName);

    Item healingPotion(
        "Healing Potion",
        "Healing",
        30
    );

    player.AddItem(healingPotion);

    std::cout
        << "\nWelcome, "
        << player.GetName()
        << ".\n";

    std::cout
        << "You descend into the Crypt of the Damned...\n";

    std::cout
        << "A Healing Potion has been added to your inventory.\n";

    StartDungeon();
}

void Game::StartDungeon()
{
    std::vector<Enemy> enemies;

    enemies.push_back(
        Enemy(
            "Skeleton Warrior",
            40,
            8,
            10
        )
    );

    enemies.push_back(
        Enemy(
            "Crypt Ghoul",
            55,
            10,
            15
        )
    );

    enemies.push_back(
        Enemy(
            "Bone Knight",
            70,
            12,
            25
        )
    );

    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (!player.IsAlive())
        {
            break;
        }

        currentEnemy = &enemies[i];

        std::cout
            << "\n============================================================\n";

        std::cout
            << "                         FLOOR "
            << i + 1
            << "\n";

        std::cout
            << "============================================================\n";

        if (i == 0)
        {
            std::cout
                << "\nCold air crawls across your skin.\n";

            std::cout
                << "Bones scrape against the stone ahead...\n";
        }
        else if (i == 1)
        {
            std::cout
                << "\nA rotten stench fills the corridor.\n";

            std::cout
                << "Something hungry moves in the darkness...\n";
        }
        else if (i == 2)
        {
            std::cout
                << "\nHeavy footsteps shake the crypt floor.\n";

            std::cout
                << "An armored figure blocks your path...\n";
        }

        StartCombat();

        if (
            player.IsAlive() &&
            i < enemies.size() - 1
            )
        {
            std::cout
                << "\nYou survived Floor "
                << i + 1
                << ".\n";

            std::cout
                << "You continue deeper into the crypt...\n";

            Item healingPotion(
                "Healing Potion",
                "Healing",
                30
            );

            player.AddItem(healingPotion);

            std::cout
                << "You found another Healing Potion.\n";
        }
    }

    currentEnemy = nullptr;

    if (player.IsAlive())
    {
        DisplayVictoryArt();

        std::cout
            << "\nYou survived every encounter in the crypt!\n";

        std::cout
            << "Final Gold: "
            << player.GetGold()
            << "\n";
    }
}

bool Game::HandleItemUse()
{
    if (player.GetInventorySize() == 0)
    {
        std::cout
            << "\nYour inventory is empty.\n";

        return false;
    }

    player.DisplayInventory();

    std::cout
        << "\nChoose an item to use: ";

    int itemChoice = GetMenuChoice(
        1,
        player.GetInventorySize()
    );

    bool itemUsed =
        player.UseItem(itemChoice - 1);

    if (itemUsed)
    {
        std::cout
            << "Current Health: "
            << player.GetHealth()
            << "/"
            << player.GetMaxHealth()
            << "\n";
    }

    return itemUsed;
}

bool Game::HandleDefend()
{
    static std::random_device randomDevice;

    static std::mt19937 randomEngine(
        randomDevice()
    );

    std::uniform_int_distribution<int>
        blockRoll(1, 100);

    int roll =
        blockRoll(randomEngine);

    const int perfectBlockChance = 25;

    std::cout
        << "\nYou raise your guard and prepare for the attack...\n";

    if (roll <= perfectBlockChance)
    {
        int counterDamage =
            player.GetAttackPower() * 2;

        std::cout
            << "\n*** PERFECT BLOCK! ***\n";

        std::cout
            << "You completely block the "
            << currentEnemy->GetName()
            << "'s attack!\n";

        std::cout
            << "You seize the opening and counterattack for "
            << counterDamage
            << " damage!\n";

        currentEnemy->TakeDamage(
            counterDamage
        );

        return false;
    }

    std::cout
        << "\nYou fail to perfectly block the attack,\n";

    std::cout
        << "but your guard reduces the incoming damage.\n";

    player.SetDefending(true);

    return true;
}

bool Game::HandlePlayerAction(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout
            << "\nYou attack the "
            << currentEnemy->GetName()
            << " for "
            << player.GetAttackPower()
            << " damage!\n";

        currentEnemy->TakeDamage(
            player.GetAttackPower()
        );

        return true;

    case 2:
        return HandleDefend();

    case 3:
        player.DisplayStats();
        return false;

    case 4:
        player.DisplayInventory();
        return false;

    case 5:
        return HandleItemUse();
    }

    return false;
}

void Game::ProcessEnemyTurn()
{
    if (!currentEnemy->IsAlive())
    {
        return;
    }

    std::string attackName;

    int enemyDamage =
        currentEnemy->GetAttackDamage(
            attackName
        );

    bool playerWasDefending =
        player.IsDefending();

    int healthBefore =
        player.GetHealth();

    if (attackName == "Normal Attack")
    {
        std::cout
            << "\nThe "
            << currentEnemy->GetName()
            << " attacks for "
            << enemyDamage
            << " damage!\n";
    }
    else
    {
        std::cout
            << "\n*** "
            << currentEnemy->GetName()
            << " uses "
            << attackName
            << "! ***\n";

        std::cout
            << "The attack can deal "
            << enemyDamage
            << " damage!\n";
    }

    player.TakeDamage(enemyDamage);

    int actualDamageTaken =
        healthBefore - player.GetHealth();

    if (playerWasDefending)
    {
        int damageBlocked =
            enemyDamage - actualDamageTaken;

        std::cout
            << "You block "
            << damageBlocked
            << " damage and take "
            << actualDamageTaken
            << " damage.\n";
    }
    else
    {
        std::cout
            << "You take "
            << actualDamageTaken
            << " damage.\n";
    }
}

void Game::ProcessCombatResult()
{
    if (player.IsAlive())
    {
        std::cout
            << "\nYou defeated the "
            << currentEnemy->GetName()
            << "!\n";

        player.AddGold(
            currentEnemy->GetGoldReward()
        );

        std::cout
            << "You earned "
            << currentEnemy->GetGoldReward()
            << " gold.\n";
    }
    else
    {
        DisplayDeathArt();

        std::cout
            << "\nYou have fallen in the Crypt of the Damned...\n";

        running = false;
    }
}

void Game::StartCombat()
{
    if (currentEnemy == nullptr)
    {
        std::cout
            << "\nError: No enemy is available for combat.\n";

        return;
    }

    DisplayEnemyArt(
        currentEnemy->GetName()
    );

    std::cout
        << "\nA "
        << currentEnemy->GetName()
        << " appears!\n";

    while (
        player.IsAlive() &&
        currentEnemy->IsAlive()
        )
    {
        DisplayCombatStatus();

        DisplayCombatMenu();

        int choice =
            GetMenuChoice(1, 5);

        bool enemyGetsTurn =
            HandlePlayerAction(choice);

        if (enemyGetsTurn)
        {
            ProcessEnemyTurn();
        }
    }

    ProcessCombatResult();
}