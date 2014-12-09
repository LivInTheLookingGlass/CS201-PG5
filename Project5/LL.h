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
	ArrayLL();
	ArrayLL(T stuff);
	~ArrayLL();
	int size();
	void append(T stuff);
	T appendInOrder(T stuff);
	void insert(int i, T stuff);
	T remove(int i);
	T & operator[] (int i);
	void print();
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
	if (head && i == 0)
		head = head->getNext();
	if (head && i > 0)
		stuff = head->remove(i, NULL);
	--length;
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
