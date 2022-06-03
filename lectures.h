#include <fstream>
#include <iostream>
#include <string>

namespace lecture
{
    void countLines(std::ifstream &in)
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

    void count()
    {
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
        }
    }

    int power(int base, int exp)
    {
        if (exp == 0)
            return 1;

        return base * power(base, exp - 1);
    }

    bool isPalindrome(std::string a_Str)
    {
        if(a_Str.size() <= 1)
            return true;

        return a_Str[0] == a_Str[a_Str.size() - 1] && isPalindrome(a_Str.substr(1, a_Str.length() - 2));
    }
    
    const int notFound = -1;

    int BinarySearch(std::vector<int> &v, int start, int end, int key)
    {
        if(start > end)
            return notFound;
        int mid = (start + end)/2;

        if(key == v[mid])
            return mid;
        else if (key > v[mid])
            return BinarySearch(v, mid+1, end, key);
        else
            return BinarySearch(v, start, mid -1, key);
    }

    void recPermute(std::string soFar, std::string a_Rest)
    {
        if (a_Rest == "")
            std::cout << soFar << std::endl;
        else
        {
            for (int i = 0; i < a_Rest.size(); i++)
            {
                std::string next = soFar + a_Rest[i];
                std::string remaining = a_Rest.substr(0, i) + a_Rest.substr(i + 1);
                recPermute(next, remaining);
            }
        }
    }

    void ListPermutations(std::string& a_Str)
    {
        recPermute("", a_Str);
    }

    void recSubsets(std::string a_SoFar, std::string a_Remaining)
    {
        if(a_Remaining == "")
            std::cout << a_SoFar << std::endl;
        else
        {
            recSubsets(a_SoFar + a_Remaining[0], a_Remaining.substr(1));
            recSubsets(a_SoFar, a_Remaining.substr(1));
        }
    }
    void listSubsets(std::string& a_Str)
    {
        recSubsets("", a_Str);
    }
}
