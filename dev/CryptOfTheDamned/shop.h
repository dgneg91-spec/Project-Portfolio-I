#pragma once

#include "Player.h"

class Shop
{
private:
    void DisplayMenu(const Player& player) const;
    int GetMenuChoice(int minChoice, int maxChoice) const;

    void BuyHealingPotion(Player& player) const;
    void BuyAttackUpgrade(Player& player) const;
    void BuyHealthUpgrade(Player& player) const;

public:
    void Open(Player& player) const;
};