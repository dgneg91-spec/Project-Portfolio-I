#include "Shop.h"

#include <iostream>
#include <stdexcept>
#include <string>

void Shop::DisplayMenu(const Player& player) const
{
    std::cout << "\n============================================================\n";
    std::cout << "                    THE GRAVE MERCHANT\n";
    std::cout << "============================================================\n";

    std::cout << "\nGold: " << player.GetGold() << "\n";

    std::cout << "\n1. Healing Potion - 10 Gold\n";
    std::cout << "   Restores 30 Health\n";

    std::cout << "\n2. Sharpen Weapon - 15 Gold\n";
    std::cout << "   Permanently increases Attack Power by 5\n";

    std::cout << "\n3. Vitality Blessing - 20 Gold\n";
    std::cout << "   Permanently increases Max Health by 20\n";
    std::cout << "   and immediately restores 20 Health\n";

    std::cout << "\n4. Leave Shop\n";

    std::cout << "\nEnter choice: ";
}

int Shop::GetMenuChoice(int minChoice, int maxChoice) const
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

void Shop::BuyHealingPotion(Player& player) const
{
    const int price = 10;

    if (!player.SpendGold(price))
    {
        std::cout << "\nYou do not have enough gold.\n";
        return;
    }

    Item healingPotion(
        "Healing Potion",
        "Healing",
        30
    );

    player.AddItem(healingPotion);

    std::cout << "\nYou purchased a Healing Potion.\n";
    std::cout << "Gold remaining: "
        << player.GetGold()
        << "\n";
}

void Shop::BuyAttackUpgrade(Player& player) const
{
    const int price = 15;

    if (!player.SpendGold(price))
    {
        std::cout << "\nYou do not have enough gold.\n";
        return;
    }

    player.IncreaseAttackPower(5);

    std::cout << "\nThe merchant sharpens your weapon.\n";
    std::cout << "Attack Power increased to "
        << player.GetAttackPower()
        << ".\n";

    std::cout << "Gold remaining: "
        << player.GetGold()
        << "\n";
}

void Shop::BuyHealthUpgrade(Player& player) const
{
    const int price = 20;

    if (!player.SpendGold(price))
    {
        std::cout << "\nYou do not have enough gold.\n";
        return;
    }

    player.IncreaseMaxHealth(20);

    std::cout << "\nA cold energy enters your body.\n";
    std::cout << "Maximum Health increased to "
        << player.GetMaxHealth()
        << ".\n";

    std::cout << "Current Health: "
        << player.GetHealth()
        << "/"
        << player.GetMaxHealth()
        << "\n";

    std::cout << "Gold remaining: "
        << player.GetGold()
        << "\n";
}

void Shop::Open(Player& player) const
{
    std::cout << "\nA hooded merchant waits beside a dying lantern.\n";
    std::cout << "\"Gold still has value among the dead...\"\n";

    bool shopping = true;

    while (shopping)
    {
        DisplayMenu(player);

        int choice = GetMenuChoice(1, 4);

        switch (choice)
        {
        case 1:
            BuyHealingPotion(player);
            break;

        case 2:
            BuyAttackUpgrade(player);
            break;

        case 3:
            BuyHealthUpgrade(player);
            break;

        case 4:
            std::cout
                << "\nYou leave the Grave Merchant behind.\n";

            shopping = false;
            break;
        }
    }
}