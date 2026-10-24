#pragma once

#include <string>

#include "Player.h"
#include "Enemy.h"

class GameUI
{
public:
    void DisplayTitle() const;
    void DisplayMainMenu() const;

    void DisplayEnemyArt(const std::string& enemyName) const;

    void DisplayVictoryArt() const;
    void DisplayDeathArt() const;

    void DisplayCombatStatus(
        const Player& player,
        const Enemy& enemy
    ) const;

    void DisplayCombatMenu() const;

    int GetMenuChoice(
        int minChoice,
        int maxChoice
    ) const;
};