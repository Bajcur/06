#include <unordered_map>
#include <iostream>

class SymbolTable
{
private:
    
public:
    std::unordered_map<std::string, int> symbolMap = {
        {"SP", 0},
        {"LCL", 1},
        {"ARG", 2},
        {"THIS", 3},
        {"THAT", 4},
        {"SCREEN", 16384},
        {"KBD", 24576}
    };
    SymbolTable();
    void addEntry(std::string symbol, int address);
    bool contains(std::string symbol);
    int getAddress(std::string symbol);
    

};
