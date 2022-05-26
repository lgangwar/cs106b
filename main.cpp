#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include "assignment1.h"

typedef void (Assignment1::StringSensor::*byrefremoval)(std::string&, std::string);

void testAssignment1();

int main()
{
    testAssignment1();
    return 0;
}

void testAssignment1()
{
    //assignment 1.
    Assignment1::StringSensor censor;
    std::cout << censor.censorString("Stanford University", "ut") << std::endl;

    std::string uni = "stanford university";
    std::string ut = "ut";
    
    byrefremoval p = &Assignment1::StringSensor::censorString;
    (censor.*p)(uni,ut);
    std::cout << uni << std::endl;

    std::string file_name;
    std::cout << "enter the file name" << std::endl;
    std::cin >> file_name;

    Assignment1::ScoreFileStats mystats(file_name);
    auto is_parsed = mystats.parseFile();
    std::cout << std::boolalpha;

    std::cout << "is file is parsed: " << is_parsed << std::endl;

    if(is_parsed)
    {
        std::cout << "max score is: " << mystats.max() << std::endl;
        std::cout << "avg score is: " << mystats.avg() << std::endl;
    }

    Assignment1::countLetters(std::string("kancha.txt"));
}