#ifndef PARSER_H // if this name is not defined then we can include code below in main file
#define PARSER_H // defineing a symbol, needed for deining header file for the first time if multiple children classes use one parent
#include <iostream>
#include <vector>


class Parser
{
protected:
    std::vector<std::string> inputData;
public:
    std::string commandType(char firsChar);
    std::string symbol(std::string currentLine);
    std::string dest(std::string currentLine);
    std::string comp(std::string currentLine);
    std::string jump(std::string currentLine);
    std::vector<std::string> getParsedVector() {return inputData;}     // inputData vector getter
};

#endif