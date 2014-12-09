#include <cstdlib>
#include <string>
#include <iostream>
#include "Header.h"
#include "LL.h"

using namespace std;
ArrayLL<string> l;


int main()	{
	cout << "Commands: add, remove, print, exit" << endl;
	for (string i = ""; i != "EXIT"; i = getInput());
	cout << "On it, boss!" << endl;
	system("pause");
	return 0;
}

string getInput() {
	cout << "command:" << endl;
	string s;
	getline(cin, s);
	s = getCaps(s);
	if (s == "EXIT")
		return "EXIT";
	else if ((string)s.substr(0, 3) == "ADD" && s != "ADD") //This is wrong
		return addTitle((string)s.substr(5, (int)s.length() - 6));
	else if ((string)s.substr(0, 6) == "REMOVE" && s != "REMOVE")
		return removeTitle(atoi(s.substr(7, (int)s.length() - 7).c_str()));
	else if (s == "PRINT")	{
		print();
		return "PRINT";
	}
	else {
		cout << endl << "Unknown command or not enough arguments" << endl;
		return "UNKNOWN";
	}
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
