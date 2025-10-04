#include <fstream>
#include <iostream>
#include <string>

#include "LinkedList.h"

std::string const IN_FILE = "input.txt";
std::string const OUT_FILE = "output.txt";

void populateNames(std::string const& fileName, LinkedList& names)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) { // Check if the file opened successfully
        throw std::runtime_error("'" + fileName + "' could not be found. Aborting.");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        names.insert(line);
    }
}

void writeNames(std::string const& fileName, LinkedList const& names)
{
    std::ofstream outputFile(fileName);

    if (outputFile.is_open()) {
        outputFile << names.ascendingAsString() << "=============\n"
                   << names.descendingAsString() << std::endl;
    } else {
        throw std::runtime_error("Unable to create file.");
    }

    std::cout << "Data written to: " << fileName << std::endl;
}

int main()
{
    LinkedList names = LinkedList();

    populateNames(IN_FILE, names);
    writeNames(OUT_FILE, names);
}
