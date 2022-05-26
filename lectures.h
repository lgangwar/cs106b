#include <fstream>
#include <iostream>

void countLines(std::ifstream& in)
{
    int count = 0;
    while (true)
    {
        std::string line;
        std::getline(in, line);

        if (in.fail())
            break; /* code */ 
        count++;
    } 
 
    std::cout << "number of lines in file is: " << count << std::endl;
}

void count(){
    std::ifstream in;
    in.open("CMakeLists.txt");

    if (in.fail())
    {
        std::cout << "file can't be opened" << std::endl;
        in.clear();
    }
    else
    {
        countLines(in);
        std::cout << "file opened successfully" << std::endl;
    }}