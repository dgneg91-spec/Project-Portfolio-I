#pragma once

#include "Player.h"

class RecordManager
{
private:
    const char* fileName = "crypt_records.txt";

public:
    void SaveSuccessfulRun(const Player& player) const;
    void DisplayRecords() const;
};