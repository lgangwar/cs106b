#include <string>
#include <set>
#include <locale>
#include <map>
#include <vector>

namespace Assignment3
{
    struct entryT
    {
        std::string m_FirstName;
        std::string m_LastName;
        std::string m_PhoneNumber;
    };

    int compareEntry(const entryT &entry1, const entryT &entry2)
    {
        if (entry1.m_LastName > entry2.m_LastName)
            return 1;
        else if (entry1.m_LastName < entry2.m_LastName)
            return -1;
        else if (entry1.m_LastName == entry2.m_LastName && entry1.m_FirstName > entry2.m_FirstName)
            return 1;
        else if (entry1.m_LastName == entry2.m_LastName && entry1.m_FirstName < entry2.m_FirstName)
            return -1;
        else if (entry1.m_LastName == entry2.m_FirstName && entry2.m_FirstName == entry2.m_LastName)
            return 0;
    }

    // if two friends having same first and last name then the set would delete one of them, the second one.
    int comareCaseIncensitiveStrs(std::string& str1, std::string& str2)
    {
        std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

        if(str1 == str2)
            return 0;
        else if (str1 < str2)
            return -1;
        else 
            return 1;
    }

    struct pointT {
        int x, y;
    };

    struct cityT {
        std::string m_Name;
        pointT m_Cordinate;
    };    
} // namespace name
