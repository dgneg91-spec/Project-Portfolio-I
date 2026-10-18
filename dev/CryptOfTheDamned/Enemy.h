#pragma once

#include <string>

class Enemy
{
private:
    std::string name;
    int health;
    int attackPower;
    int goldReward;

public:
    Enemy();
    Enemy(
        const std::string& enemyName,
        int enemyHealth,
        int enemyAttackPower,
        int reward
    );

    std::string GetName() const;

    int GetHealth() const;
    int GetAttackPower() const;
    int GetGoldReward() const;

    int GetAttackDamage(std::string& attackName) const;

    void TakeDamage(int damage);

    bool IsAlive() const;

    void DisplayStats() const;
};