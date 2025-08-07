#include <unordered_map>
#include <iostream>
#include "SymbolTable.h"

//constructor which populates map with additional key:value pairs
SymbolTable::SymbolTable()
{
    for (int i = 0; i < 16; i++)
    {
        std::string key = "R" + std::to_string(i);
        symbolMap.insert({key, i});
    }
    
}

//checks if symbol is already in the map
bool SymbolTable::contains(std::string str)
{
    auto symbol = symbolMap.find(str);
    if (symbol != symbolMap.end())
    {
        return true;
    }
    else
        return false;
    
}

// gets address(value) from passed symbol string argument
int SymbolTable::getAddress(std::string str)
{
    auto address = symbolMap.find(str);
    if (address != symbolMap.end())
    {
        return  address->second;;
    }
    else
        return -1;
    
}

//adds new entry to the map
void SymbolTable::addEntry(std::string key, int value)
{
    symbolMap.insert({key, value});
}