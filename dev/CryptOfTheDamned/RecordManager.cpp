#include "RecordManager.h"

#include <fstream>
#include <iostream>
#include <string>

void RecordManager::SaveSuccessfulRun(const Player& player) const
{
    std::ofstream outputFile(
        fileName,
        std::ios::app
    );

    if (!outputFile.is_open())
    {
        std::cout
            << "\nWarning: The Hall of Records could not be updated.\n";

        return;
    }

    outputFile
        << "Name: "
        << player.GetName()
        << " | Gold: "
        << player.GetGold()
        << " | Attack: "
        << player.GetAttackPower()
        << " | Health: "
        << player.GetHealth()
        << "/"
        << player.GetMaxHealth()
        << "\n";

    outputFile.close();

    std::cout
        << "\nYour victory has been recorded in the Hall of Records.\n";
}

void RecordManager::DisplayRecords() const
{
    std::ifstream inputFile(fileName);

    std::cout
        << "\n============================================================\n";

    std::cout
        << "                     HALL OF RECORDS\n";

    std::cout
        << "============================================================\n";

    if (!inputFile.is_open())
    {
        std::cout
            << "\nNo successful runs have been recorded yet.\n";

        return;
    }

    std::string line;

    int recordNumber = 1;

    bool foundRecord = false;

    while (std::getline(inputFile, line))
    {
        if (!line.empty())
        {
            foundRecord = true;

            std::cout
                << "\n"
                << recordNumber
                << ". "
                << line
                << "\n";

            recordNumber++;
        }
    }

    if (!foundRecord)
    {
        std::cout
            << "\nNo successful runs have been recorded yet.\n";
    }

    inputFile.close();
}