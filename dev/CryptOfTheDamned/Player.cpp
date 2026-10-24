#include "Player.h"

#include <iostream>

Player::Player()
{
    name = "Unknown";
    health = 100;
    maxHealth = 100;
    attackPower = 15;
    gold = 0;
    defending = false;
}

void Player::SetName(const std::string& newName)
{
    name = newName;
}

std::string Player::GetName() const
{
    return name;
}

int Player::GetHealth() const
{
    return health;
}

int Player::GetMaxHealth() const
{
    return maxHealth;
}

int Player::GetAttackPower() const
{
    return attackPower;
}

int Player::GetGold() const
{
    return gold;
}

bool Player::IsDefending() const
{
    return defending;
}

void Player::TakeDamage(int damage)
{
    if (defending)
    {
        damage /= 2;
    }

    health -= damage;

    if (health < 0)
    {
        health = 0;
    }

    defending = false;
}

void Player::Heal(int amount)
{
    health += amount;

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Player::AddGold(int amount)
{
    gold += amount;
}

bool Player::SpendGold(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (gold < amount)
    {
        return false;
    }

    gold -= amount;

    return true;
}

void Player::IncreaseAttackPower(int amount)
{
    attackPower += amount;
}

void Player::IncreaseMaxHealth(int amount)
{
    maxHealth += amount;
    health += amount;

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Player::AddItem(const Item& item)
{
    inventory.push_back(item);
}

void Player::SetDefending(bool value)
{
    defending = value;
}

bool Player::IsAlive() const
{
    return health > 0;
}

void Player::DisplayStats() const
{
    std::cout << "\n--- Player Stats ---\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "Gold: " << gold << "\n";
}

void Player::DisplayInventory() const
{
    std::cout << "\n--- Inventory ---\n";

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); i++)
    {
        std::cout << i + 1 << ". "
            << inventory[i].GetName()
            << " - "
            << inventory[i].GetType()
            << " ("
            << inventory[i].GetEffectValue()
            << ")\n";
    }
}

bool Player::UseItem(int index)
{
    if (index < 0 || index >= static_cast<int>(inventory.size()))
    {
        return false;
    }

    Item item = inventory[index];

    if (item.GetType() == "Healing")
    {
        if (health >= maxHealth)
        {
            std::cout << "Your health is already full.\n";
            return false;
        }

        int healthBefore = health;

        Heal(item.GetEffectValue());

        int amountHealed = health - healthBefore;

        std::cout << "You used "
            << item.GetName()
            << " and restored "
            << amountHealed
            << " health.\n";

        inventory.erase(inventory.begin() + index);

        return true;
    }

    std::cout << "That item cannot be used right now.\n";

    return false;
}

int Player::GetInventorySize() const
{
    return static_cast<int>(inventory.size());
}

void Player::Reset()
{
    name = "Unknown";
    health = 100;
    maxHealth = 100;
    attackPower = 15;
    gold = 0;
    defending = false;

    inventory.clear();
}