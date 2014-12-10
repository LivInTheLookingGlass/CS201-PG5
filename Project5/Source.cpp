//Gabe Appleton
// This is the main file
//This program keeps record of a "library" (or concievably any data) in an
//ordered template, which simulates an array, as a linked list

#include <cstdlib>
#include <string>
#include <iostream>
#include "Header.h"
#include "LL.h"

using namespace std;
ArrayLL<string> l;


int main()	{
	cout << "Commands: add, remove, print, exit" << endl;
	for (string i = ""; i != "EXIT"; i = getInput(), print());
	cout << "On it, boss!" << endl;
	system("pause");
	return 0;
}

string getInput() {
	cout << "command:" << endl;
	string s;
	getline(cin, s);
	s = getCaps(s);
	cout << s << endl;
	if (s == "EXIT")
		return "EXIT";
	else if ((string)s.substr(0, 3) == "ADD" && s != "ADD") //This is wrong
		return addTitle((string)s.substr(5, (int)s.length() - 6));
	else if ((string)s.substr(0, 6) == "REMOVE" && s != "REMOVE")
		return removeTitleRecursion((string)s.substr(8, (int)s.length() - 9));
	else if (s == "PRINT")	{
		print();
		return "PRINT";
	}
	else {
		cout << endl << "Unknown command or not enough arguments" << endl;
		return "UNKNOWN";
	}
}

string removeTitleRecursion(string s)	{
	bool a = false;
	for (int i = 0; i < l.size(); i++)
		if (checkForSub(l[i], s, 0))	{
			l.remove(i);
			i--;
			a = true;
		}
	if (a)
		return s;
	else
		return "None Removed";
}

bool checkForSub(string s, string q, long long c)	{
	bool a = false;
	if (s == q)
		return true;
	if (c + q.length() < s.length() && !a)
		a = (s.substr(c, q.length()) == q);
	if (c + q.length() < s.length() && !a)
		a = checkForSub(s, q, c + 1);
	return a;
}

int findlocation(string s)	{
	int i = 0;
	for (; l[i] < s; i++);
	return i;
}

string addTitle(string s) {
	bool a = false;
	if (l.size() > 0 && l[0] > s)
		l.insert(0, s);
	else if (l.size() > 0)	{
		for (int i = 0; i < l.size() && !a; i++) {
			if (l[i] > s)	{
				l.insert(i, s);
				a = true;
			}
			else if (l[i] == s)
				return s;
		}
		if (!a)	{
			l.insert(l.size(), s);
			a = true;
		}
	}
	else
		l.insert(0, s);
	return s;
}

string removeTitle(int i) {
	return l.remove(i);
}

string print() {
	l.print();
	return "PRINT";
}

string getCaps(string s) {
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
	}
	return s;
}
