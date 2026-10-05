#include "Item.h"

#include <iostream>

Item::Item()
{
    name = "Unknown Item";
    type = "None";
    effectValue = 0;
}

Item::Item(const std::string& itemName, const std::string& itemType, int value)
{
    name = itemName;
    type = itemType;
    effectValue = value;
}

std::string Item::GetName() const
{
    return name;
}

std::string Item::GetType() const
{
    return type;
}

int Item::GetEffectValue() const
{
    return effectValue;
}

void Item::DisplayInfo() const
{
    std::cout << "Item: " << name << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Effect Value: " << effectValue << "\n";
}