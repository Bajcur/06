#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "FilesManipulation.h"

FilesManipulation::FilesManipulation(std::string filename){
    newfile = filename;
    std::ofstream MyFile(newfile);
    MyFile.close();
}

void FilesManipulation::readfile(std::string filename){
    std::string line{};
    std::ifstream MyReadFile(filename);
    while (getline(MyReadFile,line))                                    // loops through every line of file put into function argument
    {
        if (line[0] == '/' || line == "")                               // skips every comment and empty line
        {
            continue;
        }
        else
        {
            // remove moves character which are not ' ' to the next available position which is not ' '. Then it leaves back of the string with garbage data.
            // remove doesn't changes length of the string. std::remove returns iterator that points to the character right after string without unwanted character ' '.
            auto ne = std::remove(line.begin(), line.end(), ' ');       
            line.erase(ne, line.end());                                 // erases characters from iterator to the end of the string
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '/')                                     // erases characters from '/' to the end of the string
                {
                    line.erase(i);
                }
            }
            destination.push_back(line);                                // pushes changed line to the end of the destination vector
        }
        
    }

}

void FilesManipulation::overridefile(std::vector<std::string> toWrite){
    std::cout << newfile << std::endl;
    std::ofstream MyFile(newfile);
    for (auto line : toWrite)                                           // writes every element of vector into new line of text file
    {
        MyFile << line << std::endl;                                    
    }
    MyFile.close();
}