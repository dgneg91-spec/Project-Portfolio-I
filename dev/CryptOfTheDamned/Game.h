#pragma once

#include <string>

#include "Player.h"
#include "Enemy.h"

class Game
{
private:
    Player player;
    bool running;

    Enemy* currentEnemy;

    void DisplayTitle() const;
    void DisplayMainMenu() const;
    void DisplayEnemyArt(const std::string& enemyName) const;
    void DisplayVictoryArt() const;
    void DisplayDeathArt() const;

    void DisplayCombatStatus() const;
    void DisplayCombatMenu() const;

    void StartGame();
    void StartCombat();
    void StartDungeon();

    bool HandlePlayerAction(int choice);
    bool HandleDefend();
    bool HandleItemUse();

    void ProcessEnemyTurn();
    void ProcessCombatResult();

    int GetMenuChoice(int minChoice, int maxChoice) const;

public:
    Game();

    void Run();
};