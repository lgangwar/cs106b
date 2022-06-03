#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <functional>
#include "assignment1.h"
#include "assignment2.h"
#include "lectures.h"

typedef void (Assignment1::StringSensor::*byrefremoval)(std::string&, std::string);

void testAssignment1();
void testAssignment2();
void testLecture8();
void testLecture9();
void testLecture10();

int main()
{
    //testLecture8();
    //testAssignment1();
    //testAssignment2();
    //testLecture9();
    testLecture10();

    return 0;
}

void testLecture10()
{
    std::string str = "abcd";
    lecture::listSubsets(str);
}

void testLecture9()
{
    std::string test = "abcd";
    lecture::ListPermutations(test);
}

void testLecture8()
{
    std::cout << std::boolalpha;
    std::cout << lecture::power(2,3) << std::endl;
    std::cout << lecture::isPalindrome("nan") << std::endl;

    std::vector<int> vec {1,4,23,34,67,78,90};
    std::cout << lecture::BinarySearch(vec, 0, int(vec.size())-1, 76) <<std::endl;
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

void testAssignment2()
{
    std::vector<Assignment2::EmailMsg> email_msgs;

    for(int i = 0; i < 10; i++)
    {
        Assignment2::EmailMsg msg;
        if(i%2==0)
            msg.m_Subject = "SPAM";
        else
            msg.m_Subject = "yolo";

        email_msgs.push_back(msg);
    }

    Assignment2::removeSpam(email_msgs);

    std::queue<int> myqueue;
    myqueue.push(23);
    myqueue.push(56);
    myqueue.push(78);
    Assignment2::reverseQueue(myqueue);
}