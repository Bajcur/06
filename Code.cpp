#include <iostream>
#include <vector>
#include "Code.h"
#include <algorithm>
#include <bitset>

//translates dcimal number to binary 16 bit number
std::string Code::aInstruction(int i)
{
    int addressLength = 16;
    std::string machineCode = "";
    while (addressLength > 0)
    {
        if (i > 0)
        {
            int bit = i & 1;
            machineCode.push_back('0' + bit);               // sztuczka z '0' + bit, bez tego '0' integer wrzucany do stringa tworzy jakieś nieużyteczne rzeczy
            i = i >> 1;
        }
        else
        {
            machineCode.push_back('0');
        }
        addressLength--;
    }
    
    reverse(machineCode.begin(), machineCode.end());

    return machineCode;
}

// translates destination string into string of binary number as required by specification
std::string Code::dest(std::string destination)
{
    std::bitset<3> d {};
    for(char& l : destination)
    {
        switch(l) 
        {
            case 'M': d |= 0b1; break;
            case 'D': d |= 0b10; break;
            case 'A': d |= 0b100; break;
        }
    }
    return d.to_string();
}

// translates jump string into string of binary number as required by specification
std::string Code::jump(std::string destination)
{
    if (destination == "null")
    {
        return "000";
    }
    else if (destination == "JGT")
    {
        return "001";
    }
    else if (destination == "JEQ")
    {
        return "010";
    }
    else if (destination == "JGE")
    {
        return "011";
    }
    else if (destination == "JLT")
    {
        return "100";
    }
    else if (destination == "JNE")
    {
        return "101";
    }
    else if (destination == "JLE")
    {
        return "110";
    }
    else
        return "111";
}

// translates computation string into string of binary number as required by specification
std::string Code::comp(std::string c)
{
    char a = {};
    std::string restComp = {};
    int ifM = c.find('M');
    if (ifM != std::string::npos)
    {
        a = '1';
    }
    else{
        a = '0';
    }

    if (c == "0")
    {
        restComp = "101010";
    }
    else if (c == "1")
    {
        restComp = "111111";
    }
    else if (c == "-1")
    {
        restComp = "111010";
    }
    else if (c == "D")
    {
        restComp = "001100";
    }
    else if (c == "!D")
    {
        restComp = "001101";
    }
    else if (c == "-D")
    {
        restComp = "001111";
    }
    else if (c == "D+1")
    {
        restComp = "011111";
    }
    else if (c == "D-1")
    {
        restComp = "001110";
    }

    if (c == "A" || c == "M")
    {
        restComp = "110000";
    }
    else if (c == "!A" || c == "!M")
    {
        restComp = "110001";
    }
    else if (c == "-A" || c == "-M")
    {
        restComp = "110011";
    }
    else if (c == "A+1" || c == "M+1")
    {
        restComp = "110111";
    }
    else if (c == "A-1" || c == "M-1")
    {
        restComp = "110010";
    }
    else if (c == "D+A" || c == "D+M")
    {
        restComp = "000010";
    }
    else if (c == "D-A" || c == "D-M")
    {
        restComp = "010011";
    }
    else if (c == "A-D" || c == "M-D")
    {
        restComp = "000111";
    }
    else if (c == "D&A" || c == "D&M")
    {
        restComp = "000000";
    }
    else if (c == "D|A" || c == "D|M")
    {
        restComp = "010101";
    }

    return a + restComp;
}

std::string Code::cInstruction(std::string line){
    std::string d = Pars.dest(line);
    std::string dCode = dest(d);
    std::string j = Pars.jump(line);
    std::string jCode = jump(j);
    std::string c = Pars.comp(line);
    std::string cCode = comp(c);
    return "111" + cCode + dCode + jCode;
}