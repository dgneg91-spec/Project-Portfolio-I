#include "Game.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>

Game::Game()
{
    running = true;
    currentEnemy = nullptr;
    perfectBlockActive = false;
}

void Game::Run()
{
    ui.DisplayTitle();

    while (running)
    {
        ui.DisplayMainMenu();

        int choice =
            ui.GetMenuChoice(
                1,
                5
            );

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
            records.DisplayRecords();
            break;

        case 5:
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
    perfectBlockActive = false;

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

    player.SetName(
        playerName
    );

    std::cout
        << "\nWelcome, "
        << player.GetName()
        << ".\n";

    std::cout
        << "You descend into the Crypt of the Damned...\n";

    std::cout
        << "You enter with no supplies and no gold.\n";

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

    enemies.push_back(
        Enemy(
            "Grave Wraith",
            85,
            14,
            35
        )
    );

    enemies.push_back(
        Enemy(
            "Crypt Lord",
            110,
            16,
            50
        )
    );

    for (
        size_t i = 0;
        i < enemies.size();
        i++
        )
    {
        if (!player.IsAlive())
        {
            break;
        }

        currentEnemy =
            &enemies[i];

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
        else if (i == 3)
        {
            std::cout
                << "\nThe torches suddenly die.\n";

            std::cout
                << "A pale shape floats through the stone wall...\n";
        }
        else if (i == 4)
        {
            std::cout
                << "\nA massive iron door opens by itself.\n";

            std::cout
                << "The ruler of the crypt rises from his throne...\n";

            std::cout
                << "\nThis is the final battle.\n";
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
                << "You find a quiet chamber before continuing deeper.\n";

            shop.Open(
                player
            );

            std::cout
                << "\nYou continue deeper into the crypt...\n";
        }
    }

    currentEnemy = nullptr;

    if (player.IsAlive())
    {
        ui.DisplayVictoryArt();

        std::cout
            << "\nYou defeated the Crypt Lord and survived the entire dungeon!\n";

        std::cout
            << "Final Gold Remaining: "
            << player.GetGold()
            << "\n";

        std::cout
            << "Final Attack Power: "
            << player.GetAttackPower()
            << "\n";

        std::cout
            << "Final Health: "
            << player.GetHealth()
            << "/"
            << player.GetMaxHealth()
            << "\n";

        records.SaveSuccessfulRun(
            player
        );
    }
}

bool Game::HandleItemUse()
{
    if (
        player.GetInventorySize() == 0
        )
    {
        std::cout
            << "\nYour inventory is empty.\n";

        return false;
    }

    player.DisplayInventory();

    std::cout
        << "\nChoose an item to use: ";

    int itemChoice =
        ui.GetMenuChoice(
            1,
            player.GetInventorySize()
        );

    bool itemUsed =
        player.UseItem(
            itemChoice - 1
        );

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
    static std::random_device
        randomDevice;

    static std::mt19937 randomEngine(
        randomDevice()
    );

    std::uniform_int_distribution<int>
        blockRoll(
            1,
            100
        );

    int roll =
        blockRoll(
            randomEngine
        );

    const int perfectBlockChance =
        25;

    std::cout
        << "\nYou raise your guard and prepare for the attack...\n";

    if (
        roll <=
        perfectBlockChance
        )
    {
        perfectBlockActive = true;

        std::cout
            << "\nYou find the perfect defensive opening...\n";

        return true;
    }

    perfectBlockActive = false;

    std::cout
        << "\nYou fail to find a perfect opening,\n";

    std::cout
        << "but your guard will reduce the incoming damage.\n";

    player.SetDefending(
        true
    );

    return true;
}

bool Game::HandlePlayerAction(
    int choice
)
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
        perfectBlockActive = false;

        return;
    }

    std::string attackName;

    int enemyDamage =
        currentEnemy->GetAttackDamage(
            attackName
        );

    if (
        attackName ==
        "Normal Attack"
        )
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

    if (perfectBlockActive)
    {
        int counterDamage =
            player.GetAttackPower();

        std::cout
            << "\n*** PERFECT BLOCK! ***\n";

        std::cout
            << "You completely block the attack and take 0 damage!\n";

        std::cout
            << "You counterattack for "
            << counterDamage
            << " damage!\n";

        currentEnemy->TakeDamage(
            counterDamage
        );

        perfectBlockActive = false;

        return;
    }

    bool playerWasDefending =
        player.IsDefending();

    int healthBefore =
        player.GetHealth();

    player.TakeDamage(
        enemyDamage
    );

    int actualDamageTaken =
        healthBefore -
        player.GetHealth();

    if (playerWasDefending)
    {
        int damageBlocked =
            enemyDamage -
            actualDamageTaken;

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
    perfectBlockActive = false;

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

        std::cout
            << "Current Gold: "
            << player.GetGold()
            << "\n";
    }
    else
    {
        ui.DisplayDeathArt();

        std::cout
            << "\nYou have fallen in the Crypt of the Damned...\n";

        running = false;
    }
}

void Game::StartCombat()
{
    if (
        currentEnemy == nullptr
        )
    {
        std::cout
            << "\nError: No enemy is available for combat.\n";

        return;
    }

    perfectBlockActive = false;

    ui.DisplayEnemyArt(
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
        ui.DisplayCombatStatus(
            player,
            *currentEnemy
        );

        ui.DisplayCombatMenu();

        int choice =
            ui.GetMenuChoice(
                1,
                5
            );

        bool enemyGetsTurn =
            HandlePlayerAction(
                choice
            );

        if (enemyGetsTurn)
        {
            ProcessEnemyTurn();
        }
    }

    ProcessCombatResult();
}