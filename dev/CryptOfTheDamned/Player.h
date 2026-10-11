#pragma once

#include <string>
#include <vector>

#include "Item.h"

class Player
{
private:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int gold;
    bool defending;
    std::vector<Item> inventory;

public:
    Player();

    void SetName(const std::string& newName);

    std::string GetName() const;
    int GetHealth() const;
    int GetMaxHealth() const;
    int GetAttackPower() const;
    int GetGold() const;
    bool IsDefending() const;

    void TakeDamage(int damage);
    void Heal(int amount);

    void AddGold(int amount);
    void AddItem(const Item& item);

    void SetDefending(bool value);

    bool IsAlive() const;

    void DisplayStats() const;
    void DisplayInventory() const;

    bool UseItem(int index);
    int GetInventorySize() const;
};