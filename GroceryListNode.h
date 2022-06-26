#ifndef TABLE_NODE_H
#define TABLE_NODE_H
#include <string>

namespace N
{
    class GroceryListNode
    {
    public:
        int printMenu(int x);
        int callIntFunc(std::string proc, std::string param);
        void CallProcedure(std::string pName);
        int len(std::string str);
        void split(std::string str, char seperator);
        std::string nCharString(int n, std::string c);
        void menuOptionThree();
        void menuOptionTwo();
        void menuOptionOne();
    };
};

#endif