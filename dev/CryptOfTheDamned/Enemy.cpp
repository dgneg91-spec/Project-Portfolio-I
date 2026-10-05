#include "Enemy.h"

#include <iostream>

Enemy::Enemy()
{
    name = "Unknown Enemy";
    health = 50;
    attackPower = 10;
    goldReward = 5;
}

Enemy::Enemy(const std::string& enemyName, int enemyHealth, int enemyAttackPower, int reward)
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