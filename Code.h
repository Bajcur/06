#include <iostream>
#include <vector>
#include "Parser.h"

class Code
{
protected:
    std::vector<std::string> translatedData;   
public:
    std::string aInstruction(int address);
    std::string cInstruction(std::string line);
    std::string dest(std::string destination);
    std::string jump(std::string jump);
    std::string comp(std::string computation);
    std::vector<std::string> getTranslatedVector() {return translatedData;}
private:
    Parser Pars;

};

