#pragma once

#include <string>

class Item
{
private:
    std::string name;
    std::string type;
    int effectValue;

public:
    Item();
    Item(const std::string& itemName, const std::string& itemType, int value);

    std::string GetName() const;
    std::string GetType() const;
    int GetEffectValue() const;

    void DisplayInfo() const;
};