#include <iostream>
#include <limits>
#include "GroceryListNode.h"
using namespace std;
using namespace N;

int main()
{
    GroceryListNode groceryListBrains;
    int userInput;

    groceryListBrains.printMenu(-1);
    while (true)
    {
        while (groceryListBrains.printMenu(0) && !(std::cin >> userInput))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please input 1, 2, 3, or 4.\n";
        }
        if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4)
        {
            break;
        }

        cout << "\nEnter 1, 2, 3, or 4 only please.\n\n";
    }
    if (userInput == 1)
    {
        groceryListBrains.menuOptionOne();
    }
    if (userInput == 2)
    {
        groceryListBrains.menuOptionTwo();
    }
    if (userInput == 3)
    {
        groceryListBrains.menuOptionThree();
    }

    return 0;
}