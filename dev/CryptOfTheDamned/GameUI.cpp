#include "GameUI.h"

#include <iostream>
#include <stdexcept>
#include <string>

void GameUI::DisplayTitle() const
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

void GameUI::DisplayMainMenu() const
{
    std::cout
        << "\n================ MAIN MENU ================\n";

    std::cout
        << "1. Start Game\n";

    std::cout
        << "2. View Player Stats\n";

    std::cout
        << "3. View Inventory\n";

    std::cout
        << "4. Hall of Records\n";

    std::cout
        << "5. Exit\n";

    std::cout
        << "===========================================\n";

    std::cout
        << "\nEnter choice: ";
}

void GameUI::DisplayEnemyArt(
    const std::string& enemyName
) const
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
    else if (enemyName == "Grave Wraith")
    {
        std::cout << R"(

             .-""""-.
           .'        '.
          /    .--.    \
         |    /    \    |
         |   |  ()  |   |
          \   \    /   /
           '.  '--'  .'
             '-.__.-'
              / || \
             /  ||  \
                ||
                ||
               /  \

           GRAVE WRAITH
)";
    }
    else if (enemyName == "Crypt Lord")
    {
        std::cout << R"(

                _________
               /         \
              /  /\   /\  \
             |  /  \ /  \  |
             | |    V    | |
             | |  X   X  | |
             | |    ^    | |
              \ \  ___  / /
               \ '-----' /
                \_______/
               ___|   |___
              /           \
             /             \
            |               |
            |    CRYPT      |
            |     LORD      |
             \             /
              \___________/

              CRYPT LORD
)";
    }
}

void GameUI::DisplayVictoryArt() const
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

void GameUI::DisplayDeathArt() const
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

void GameUI::DisplayCombatStatus(
    const Player& player,
    const Enemy& enemy
) const
{
    std::cout
        << "\n----------------------------\n";

    std::cout
        << player.GetName()
        << " HP: "
        << player.GetHealth()
        << "/"
        << player.GetMaxHealth()
        << "\n";

    std::cout
        << enemy.GetName()
        << " HP: "
        << enemy.GetHealth()
        << "\n";
}

void GameUI::DisplayCombatMenu() const
{
    std::cout
        << "\n1. Attack\n";

    std::cout
        << "2. Defend\n";

    std::cout
        << "3. View Stats\n";

    std::cout
        << "4. View Inventory\n";

    std::cout
        << "5. Use Item\n";

    std::cout
        << "\nEnter choice: ";
}

int GameUI::GetMenuChoice(
    int minChoice,
    int maxChoice
) const
{
    std::string input;

    while (true)
    {
        std::getline(
            std::cin,
            input
        );

        try
        {
            size_t charactersUsed = 0;

            int choice = std::stoi(
                input,
                &charactersUsed
            );

            if (
                charactersUsed !=
                input.length()
                )
            {
                throw std::invalid_argument(
                    "Extra characters entered."
                );
            }

            if (
                choice < minChoice ||
                choice > maxChoice
                )
            {
                throw std::out_of_range(
                    "Choice outside valid range."
                );
            }

            return choice;
        }
        catch (
            const std::invalid_argument&
            )
        {
            std::cout
                << "Invalid input. Please enter a whole number between "
                << minChoice
                << " and "
                << maxChoice
                << ": ";
        }
        catch (
            const std::out_of_range&
            )
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