import re
import string


def EveryItemText():
    groceryListList = []
    res = {}

    groceryList = open(
        "CS210_Project_Three_Input_File.txt", "r")
    for x in groceryList:
        if "\n" in x:
            x = x[:len(x)-1]
        groceryListList.append(x)

    for i in groceryListList:
        res[i] = groceryListList.count(i)

    for dicKey, dicValue in res.items():
        print(dicKey, dicValue)
    groceryList.close()


def OneItemText(userInput):
    groceryListList = []
    res = {}

    groceryList = open(
        "CS210_Project_Three_Input_File.txt", "r")
    for x in groceryList:
        if "\n" in x:
            x = x[:len(x)-1]
        groceryListList.append(x)

    for i in groceryListList:
        res[i] = groceryListList.count(i)

    print(res[userInput])
    groceryList.close()


def EveryItemHistograph():
    groceryListList = []
    res = {}

    groceryList = open(
        "CS210_Project_Three_Input_File.txt", "r")
    for x in groceryList:
        if "\n" in x:
            x = x[:len(x)-1]
        groceryListList.append(x)

    for i in groceryListList:
        res[i] = groceryListList.count(i)

    histo = open(
        "frequency.bat", "x")

    for dicKey, dicValue in res.items():
        histo.write(dicKey)
        histo.write(" ")
        histo.write(str(dicValue))
        histo.write("\n")
    groceryList.close()
    histo.close()
