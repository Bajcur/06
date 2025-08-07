#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
//#include "FilesManipulation.h"
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

Parser Pars;
Code toCode;
SymbolTable Symbols;

void createFile(std::string filename){
    std::ofstream MyFile(filename);
    MyFile.close();
}

void overridefile(std::string filename, std::vector<std::string> toWrite){
    std::ofstream MyFile(filename);
    for (auto line : toWrite)                                           // writes every element of vector into new line of text file
    {
        MyFile << line << std::endl;                                    
    }
    MyFile.close();
}

void removeSpace(std::string& line){
    // remove moves character which are not ' ' to the next available position which is not ' '. Then it leaves back of the string with garbage data.
    // remove doesn't changes length of the string. std::remove returns iterator that points to the character right after string without unwanted character ' '.
    auto ne = std::remove(line.begin(), line.end(), ' ');       
    line.erase(ne, line.end());                                     // erases characters from iterator to the end of the string
}

void firstPass(std::string assemblyFile){
    std::ifstream MyReadFile(assemblyFile);
    std::string line{};
    int rn = 0;
    
    while (getline(MyReadFile,line))                                    // loops through every line of file put into function argument
    {
        removeSpace(line);
        if (line[0] == '/' || line == "")                               // skips every comment and empty line
        {
            continue;
        }
        else
        {
            std::string key{};
            if (line[0] == '(')                                         // adds to the symbol table key:value pairs of the loop labels
            {                                                           // where rn is running index of the translated file COMMANDS
                int it = line.find(')');
                key = line.substr(1,it-1);
                Symbols.addEntry(key, rn); 
            }
            else
            {
                rn++;
            }
              
        }

    }
}

void secondPass(std::string filename, std::vector<std::string>& destination){
    std::string line{};
    std::ifstream MyReadFile(filename);
    int ramAddress = 16;
    while (getline(MyReadFile,line))                                    // loops through every line of file put into function argument
    {
        removeSpace(line);                                              // erases characters from iterator to the end of the string
        if (line[0] == '/' || line == "")                               // skips every comment and empty line
        {
            continue;
        }
        else
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '/')                                     // erases characters from '/' to the end of the string
                {
                    line.erase(i);
                }
            }

            // decides command type
            std::string command = Pars.commandType(line[0]);

            //depending on command type one of three options executes
            if (command == "L_COMMAND")
            {
               continue;
            }
            else if (command == "A_COMMAND")
            {
                line = line.substr(1);
                int c = line[0];
                if ( c <= 57 && c >= 48)                                // checks if address is integer or variable
                {                                                       // if int then instantly changes line to binary 16-bit address
                    int address = std::stoi(line);
                    line = toCode.aInstruction(address);
                }
                else                                                    // if variable, then checks if it is in symbol table
                {
                    int value{};
                    if (Symbols.contains(line))                         // if yes, then it gets value(address) of the current variable
                    {
                        value = Symbols.getAddress(line);
                    }
                    else                                                // if not, then it adds key(variable):value(address) pair into the symbol table
                    {                                                   // address of added A_COMMANDS starts from 16
                        Symbols.addEntry(line, ramAddress);
                        ramAddress++;
                        value = Symbols.getAddress(line);
                    }
                    line = toCode.aInstruction(value);
                }
            }
            else    //C_COMMAND
            {
                line = toCode.cInstruction(line);
            }
            destination.push_back(line);                                // pushes changed line to the end of the destination vector
        }
        
    }
}

int main()
{
    //global variables 
    std::vector<std::string> workingVector{};

    //file with machine code
    std::string hackFile = "file.hack"; 

    //assembly file
    std::string assemblyFile {};
    std::cout << "Enter asembly file name:" << std::endl;
    std::cin >> assemblyFile;

    createFile(hackFile);

    //adds loop labels into symbol table
    firstPass(assemblyFile);

    //translates file and save it values in the vector
    secondPass(assemblyFile, workingVector);

    //override file with new translated lines
    overridefile(hackFile, workingVector);
    return 0;
}