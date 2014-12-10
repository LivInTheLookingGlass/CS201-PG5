//Gabe Appleton
// This is the prototype file

#ifndef _head_
#define _head_

#include <cstdlib>
#include <string>
#include <iostream>
#include "LL.h"
#include "LLN.h"

using namespace std;

template <class T> class ArrayLLN;
template <class T> class ArrayLL;

int main(); //It's main, it calls the other things
string getInput(); //Grabs your input and decids what to do
string getCaps(string s); //Converts strings into capitals
string addTitle(string s); //Adds title to the list
string removeTitle(int i); //Removes at a specific position
string print(); // prints the list
string removeTitleRecursion(string s); //Removes title *properly* according to the assignment
bool checkForSub(string s, string q, long long c); //checks for a matching substring within the larger string

#endif
