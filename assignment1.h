#include <string>
#include <fstream>
#include <vector>
#include <iostream>

namespace Assignment1
{
    class ScoreFileStats
    {
    public:
        ScoreFileStats(const std::string &a_File);
        bool parseFile();
        double avg();
        int max(){return m_Max;}
    private:
        double m_Avg;
        int m_Max = INT_MIN;
        std::string m_FileName;
        std::vector<int> m_Scores;
    };

    class StringSensor
    {
    public:
        std::string censorString(std::string a_Text, std::string remove);
        void censorString(std::string &a_Text, std::string remove);
    };

    void countLetters(const std::string& a_FileName);
}