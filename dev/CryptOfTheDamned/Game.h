#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include "GameUI.h"
#include "RecordManager.h"

class Game
{
private:
    Player player;
    Shop shop;
    GameUI ui;
    RecordManager records;

    bool running;

    Enemy* currentEnemy;

    bool perfectBlockActive;

    void StartGame();
    void StartCombat();
    void StartDungeon();

    bool HandlePlayerAction(int choice);
    bool HandleDefend();
    bool HandleItemUse();

    void ProcessEnemyTurn();
    void ProcessCombatResult();

public:
    Game();

    void Run();
};