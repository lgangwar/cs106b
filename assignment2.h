#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <map>
#include <locale>

namespace Assignment2
{
    class EmailMsg {
        public:
            std::string m_To; //modify the to field to vector or stack so that last element accessed
            std::string m_From;
            std::string m_Message;
            std::string m_Subject;
            int m_Date;
            int m_Time;
    };
    
    void removeSpam(std::vector<EmailMsg>& a_Emails)
    {
        std::vector<EmailMsg> filtered_msgs;
        for(auto& email : a_Emails)
        {
            if(email.m_Subject.find("SPAM"))
                continue;

            filtered_msgs.push_back(email);
        }

        a_Emails = filtered_msgs;
    }

    void reverseQueue(std::queue<int>& a_Queue)
    {
        std::stack<int> stack;

        while (!a_Queue.empty())
        {
            int value = a_Queue.front();
            a_Queue.pop();
            stack.push(value);
        }

        while(!stack.empty())
        {
            int value = stack.top();
            stack.pop();

            a_Queue.push(value);
        }        
    }
    
    bool IsCorrectlyNested(const std::string& htmlStr)
    {
        std::string br1 = "<html>", br2 = "<b>", br3 = "<i>";
        std::string b4 = "</i>", b5 = "</b>", b6 = "</html>";
        int n1,n2,n3,n4,n5,n6;
        std::stack<std::string> brakets;
        int npos = 0;
        
        while(htmlStr.find(br1))
        return true;
    }

    char mostFrequentChar(std::ifstream &mystream, int &numOccurance)
    {
        std::map<char, int> counter;
        for (int i = 97; i <= 122; i++)
            counter[char(i)] = 0;

        while (true)
        {
            std::string str;
            std::getline(mystream, str);

            if (mystream.fail())
                break;

            // std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            for (const auto &mycha : str)
            {
                if (((int)mycha >= 97 && (int)mycha <= 122) || ((int)mycha >= 65 && (int)mycha <= 90))
                    counter[::tolower(mycha)]++;
            }
        }

        // find max repeating char
        int max = INT_MIN;
        char max_repeat = '?';
        for (const auto &val : counter)
        {
            if (val.second > max)
            {
                max = val.second;
                max_repeat = val.first;
            }
        }

        numOccurance = max;
        return max_repeat;
    }
} // namespace name
