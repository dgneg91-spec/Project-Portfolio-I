#include "Enemy.h"

#include <iostream>
#include <random>

Enemy::Enemy()
{
    name = "Unknown Enemy";
    health = 50;
    attackPower = 10;
    goldReward = 5;
}

Enemy::Enemy(
    const std::string& enemyName,
    int enemyHealth,
    int enemyAttackPower,
    int reward)
{
    name = enemyName;
    health = enemyHealth;
    attackPower = enemyAttackPower;
    goldReward = reward;
}

std::string Enemy::GetName() const
{
    return name;
}

int Enemy::GetHealth() const
{
    return health;
}

int Enemy::GetAttackPower() const
{
    return attackPower;
}

int Enemy::GetGoldReward() const
{
    return goldReward;
}

int Enemy::GetAttackDamage(std::string& attackName) const
{
    static std::random_device randomDevice;
    static std::mt19937 randomEngine(randomDevice());

    std::uniform_int_distribution<int> attackRoll(1, 100);

    int roll = attackRoll(randomEngine);

    if (name == "Crypt Ghoul")
    {
        if (roll <= 25)
        {
            attackName = "Savage Claw";
            return 13;
        }
    }
    else if (name == "Bone Knight")
    {
        if (roll <= 20)
        {
            attackName = "Crushing Blow";
            return 17;
        }
    }
    else if (name == "Grave Wraith")
    {
        if (roll <= 25)
        {
            attackName = "Soul Drain";
            return 18;
        }
    }
    else if (name == "Crypt Lord")
    {
        if (roll <= 20)
        {
            attackName = "Dark Execution";
            return 22;
        }
    }

    attackName = "Normal Attack";

    return attackPower;
}

void Enemy::TakeDamage(int damage)
{
    health -= damage;

    if (health < 0)
    {
        health = 0;
    }
}

bool Enemy::IsAlive() const
{
    return health > 0;
}

void Enemy::DisplayStats() const
{
    std::cout << "\n--- Enemy Stats ---\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
}