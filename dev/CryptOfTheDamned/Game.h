#pragma once

#include "Player.h"
#include "Enemy.h"

class Game
{
private:
    Player player;
    bool running;

    void DisplayTitle() const;
    void DisplayMainMenu() const;
    void StartGame();
    void StartCombat(Enemy& enemy);
    int GetMenuChoice(int minChoice, int maxChoice) const;

public:
    Game();

    void Run();
};