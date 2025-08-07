#include <iostream>
#include <fstream>
#include <vector>

class FilesManipulation
{
protected:
    std::string newfile;
    std::vector<std::string> destination{};
public:
    FilesManipulation(std::string newfile);
    void readfile(std::string filetoread);
    void overridefile(std::vector<std::string> toWrite);
    std::vector<std::string> getDestination() {return destination;}     // destination vector getter
};