#include <numeric>
#include <map>
#include <algorithm>
#include "assignment1.h"

namespace Assignment1
{
    ScoreFileStats::ScoreFileStats(const std::string& a_FileName) : m_FileName(a_FileName)
    {}

    bool ScoreFileStats::parseFile()
    {
        std::ifstream in;

        in.open(m_FileName.c_str());
        if(in.fail())
            return false;
        
        std::string str;
        
        while(true)
        {            
            std::getline(in,str);
            if(in.fail())
                break;
            auto score = atoi(str.c_str());

            if(score < 0 || score>100)
                continue;

            if(score > m_Max)
                m_Max = score;
            m_Scores.push_back(score);
        }

        return true;
    }

    double ScoreFileStats::avg()
    {
        if(m_Scores.empty())
            return INT_MIN;
        auto sum = std::accumulate(m_Scores.begin(), m_Scores.end(), 0);

        return (double(sum)/m_Scores.size());
    }

    std::string StringSensor::censorString(std::string a_Text, std::string remove)
    {
        for (int i = 0; i < remove.size(); i++)
        {
            char remove_char = remove[i];
            size_t npos = 0;
            while ((npos = a_Text.find(remove_char, npos)) != std::string::npos)
            {
                a_Text.erase(npos, 1);
            }
        }

        return a_Text;
    }

    void StringSensor::censorString(std::string &a_Text, std::string remove)
    {
        for (int i = 0; i < remove.size(); i++)
        {
            char remove_char = remove[i];
            size_t npos = 0;
            while ((npos = a_Text.find(remove_char, npos)) != std::string::npos)
            {
                a_Text.erase(npos, 1);
            }
        }
    }

    void countLetters(const std::string& a_FileName)
    {
        std::map<char, int> mymap;
        for(int i = 97; i <= 122 ; i++)
            mymap[char(i)] = 0;

        std::ifstream in;
        in.open(a_FileName.c_str());
        if(in.fail())
            return;

        std::string line;
        while(true)
        {
            std::getline(in, line);
            if(in.fail()) break;

            std::transform(line.begin(), line.end(),line.begin(), ::tolower);

            for(auto& ch : line)
            {
                if( int(ch) >= 97 && int(ch) <= 122)
                    mymap[ch] +=1;
            }
        }

        for(const auto element : mymap)
        {
            std::cout << element.first <<":" << element.second << std::endl;
        }
    }
}