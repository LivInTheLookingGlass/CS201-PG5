#include <cstdlib>
#include <string>
#include <iostream>
#include "Header.h"
#include "LL.h"

using namespace std;


int main()	{
	l = new ArrayLL<string>();
	int loopcontrol = 1;
	cout << "Commands: add, remove, print, exit" << endl;
	for (int i = 1; i != 0; i = getInput());
	cout << "On it, boss!" << endl;
	delete l;
	system("pause");
	return 0;
}

int getInput() {
	cout << "command:" << endl;
	string s;
	getline(cin,s);
	s = getCaps(s);
	if (s == "EXIT")
		return 0;
	else if (s == "ADD")
		return addTitle();
	else if (s == "REMOVE")
		return removeTitle();
	else if (s == "PRINT")
		return print();
	else {
		cout << endl << "Unknown command.  You suck." << endl;
		return 2;
	}
}

int addTitle() {
	cout << "title?" << endl;
	string s;
	getline(cin,s);
	s = getCaps(s);
	l->appendInOrder(s);
	return 1;
} 

int removeTitle() {
	cout << "substring?" << endl;
	string s;
	getline(cin,s);
	s = getCaps(s);
	l->removeTitle(s);
	return 1;
}

int print() {
	l->print();
	return 1;
} 

string getCaps(string s) {
	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
	}
	return s;
}
