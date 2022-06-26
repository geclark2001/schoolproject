#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include "GroceryListNode.h"
#define max2 2

using namespace N;
using namespace std;
string strings[max2];

void GroceryListNode::CallProcedure(string pName)
{
    char *procname = new char[pName.length() + 1];
    strcpy(procname, pName.c_str());

    Py_Initialize();
    PyObject *my_module = PyImport_ImportModule("PythonCode");
    PyErr_Print();
    PyObject *my_function = PyObject_GetAttrString(my_module, procname);
    PyObject *my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();

    delete[] procname;
}

int GroceryListNode::callIntFunc(string proc, string param)
{
    char *procname = new char[proc.length() + 1];
    strcpy(procname, proc.c_str());

    char *paramval = new char[param.length() + 1];
    strcpy(paramval, param.c_str());

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
    Py_Initialize();
    pName = PyUnicode_FromString((char *)"PythonCode");
    pModule = PyImport_Import(pName);
    pDict = PyModule_GetDict(pModule);
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(z)", paramval);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    Py_DECREF(pValue);

    Py_DECREF(pModule);
    Py_DECREF(pName);
    Py_Finalize();

    delete[] procname;
    delete[] paramval;
    return _PyLong_AsInt(presult);
}

int GroceryListNode::len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

void GroceryListNode::split(string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

string GroceryListNode::nCharString(int n, string c)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp = temp + c;
    }
    return temp;
}

void GroceryListNode::menuOptionThree()
{
    ifstream inFrequency;
    string rawString;
    int number;
    CallProcedure("EveryItemHistograph");
    cout << "Histograph\n";
    inFrequency.open("frequency.bat");
    while (getline(inFrequency, rawString))
    {
        split(rawString, ' ');
        stringstream intValue(strings[1]);
        number = 0;
        intValue >> number;
        cout << strings[0] << " " << nCharString(number, "*") << endl;
    }
    inFrequency.close();
}

void GroceryListNode::menuOptionTwo()
{
    string userInputS;
    cout << "\nPleast input which item you would like counted.\n";
    cin >> userInputS;
    cout << "Frequency of " << userInputS << " is " << callIntFunc("OneItemText", "Garlic");
}

int GroceryListNode::printMenu(int x)
{
    if (x == -1)
    {
        cout << "Grocery Tracking (TM pending)";
    }
    if (x == 0)
    {
        cout << "\n1. Frequency all items\n2. Frequence of an item\n3. Histogram of all items\n4. Exit\n\n";
    }
}

void GroceryListNode::menuOptionOne()
{
    cout << "\nFrequency of All Items\n+--------------------+\n";
    CallProcedure("EveryItemText");
}