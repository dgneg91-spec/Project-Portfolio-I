#pragma once

#include <string>

#include "Player.h"
#include "Enemy.h"

class Game
{
private:
    Player player;
    bool running;

    void DisplayTitle() const;
    void DisplayMainMenu() const;
    void DisplayEnemyArt(const std::string& enemyName) const;
    void DisplayVictoryArt() const;
    void DisplayDeathArt() const;

    void StartGame();
    void StartCombat(Enemy& enemy);
    void StartDungeon();

    int GetMenuChoice(int minChoice, int maxChoice) const;

public:
    Game();

    void Run();
};