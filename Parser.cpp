#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "FilesManipulation.h"
#include "Parser.h"

// decides command type
std::string Parser::commandType(char firstChar){
    std::string command{};
    if (firstChar == '@'){
        command = "A_COMMAND";
    }else if (firstChar == '('){
        command = "L_COMMAND";
    }else
        command = "C_COMMAND";
    
    return command;
}

// creates destination substring, from start to equal sign
std::string Parser::dest(std::string currentLine){
    int ifEquals = currentLine.find('=');
    if (ifEquals == std::string::npos)
    {
        return std::string("null");
    }else
    {
        return currentLine.substr(0, ifEquals);
    }
}

//creates computation substring, from equal sign to semicolon sign
std::string Parser::comp(std::string currentLine){
    int ifEquals = currentLine.find('=');
    int ifJump = currentLine.find(';');
    if (ifEquals == std::string::npos)
    {
        return currentLine.substr(0,ifJump);
    }
    else if (ifJump == std::string::npos)
    {
        return currentLine.substr(ifEquals+1);
    }
    else
    {
        return currentLine.substr(ifEquals+1, ifJump-1);
    }
}

//creates jump substring from semicolon to the end of the string. In case of no semicolon it returns "null" string
std::string Parser::jump(std::string currentLine){
    int ifJump = currentLine.find(';');
    if (ifJump == std::string::npos)
    {
        return std::string("null");
    }else
    {
        return currentLine.substr(ifJump+1);
    }
}