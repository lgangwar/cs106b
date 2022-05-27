#include <string>

class Scanner {
    public:
        Scanner(){};
        ~Scanner(){};

        void setInput(const std::string& str){m_Input = str;};

        std::string nextToken(std::string a_Token){
            m_Token = a_Token;
            
        };
        bool hasMoreToken(){};

        enum spaceOptionT {PreserverToken, IgnoreToken};

        void setSpaceOption(spaceOptionT option){ m_SpaceOption = option;};
        spaceOptionT getSpaceoption() {return m_SpaceOption;};
    private:
        std::string m_Input;
        spaceOptionT m_SpaceOption;
        std::string m_Token;
};