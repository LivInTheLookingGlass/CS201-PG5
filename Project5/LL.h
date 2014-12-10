//Gabe Appleton
// This is the prototype file for the ArrayLL Template

#ifndef _LL_
#define _LL_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"

template <class T> class ArrayLLN;
template <class T> class ArrayLL	{
private:
	ArrayLLN<T> *head;
	int length;
public:
	ArrayLL(); //constructor with no data
	ArrayLL(T stuff); // constructor to start with head
	~ArrayLL(); //destructor
	int size(); //returns size
	void append(T stuff); // adds new node to end of file with content T
	T appendInOrder(T stuff); // appends in value order
	void insert(int i, T stuff); //inserts item at position i
	T remove(int i); //removes node at position i
	T & operator[] (int i); //returns the content of the node at position i
	void print(); //prints the list
};

template <class T> ArrayLL<T>::ArrayLL()	{
	head = NULL;
	length = 0;
}

template <class T> ArrayLL<T>::ArrayLL(T stuff)	{
	head = new ArrayLLN<T>(stuff);
	length = 1;
}

template <class T> ArrayLL<T>::~ArrayLL()	{
	delete head;
}

template <class T> int ArrayLL<T>::size()	{
	return length;
}

template <class T> void ArrayLL<T>::append(T stuff)	{
	if (head == NULL)
		head = new ArrayLLN(stuff);
	else
		head->append(stuff);
	++ length;
}

template <class T> T ArrayLL<T>::appendInOrder(T stuff)	{
	if (!head)
		head = new ArrayLLN<T>(stuff);
	else if ((T)head->get() > (T)stuff)
		head = new ArrayLLN<T>(stuff,head);
	else
		head->appendInOrder(stuff);
	++length;
	return stuff;
}

template <class T> void ArrayLL<T>::insert(int i, T stuff)	{
	if (!head)
		head = new ArrayLLN<T>(stuff);
	else if (i == 0)	{
		ArrayLLN<T> *t = new ArrayLLN<T>(stuff);
		t->setNext(head);
		head = t;
	}
	else
		head->insert(i-1,stuff);
	++length;
}

template <class T> T ArrayLL<T>::remove(int i)	{
	T stuff;
	if (i < length && i >= 0)	{
		if (head && i == 0)
			head = head->getNext();
		if (head && i > 0)
			stuff = head->remove(i, NULL);
		--length;
	}
	return stuff;
}

template <class T> T & ArrayLL<T>::operator[] (int i)	{
		return head->grab(i);
}

template <class T> void ArrayLL<T>::print()	{
	if (head)
		head->print();
}

#endif
