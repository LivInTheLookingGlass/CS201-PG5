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
	void appendInOrder(T stuff);
	void insert(int i, T stuff);
	T remove(int i);
	T removeTitle(T arg);
	T & operator[] (int i);
	void print();
};

template <class T> ArrayLL<T>::ArrayLL()	{
	head = NULL;
}

template <class T> ArrayLL<T>::ArrayLL(T stuff)	{
	append(stuff);
}

template <class T> ArrayLL<T>::~ArrayLL()	{
	delete head;
}

template <class T> int ArrayLL<T>::size()	{
	return length;
}

template <class T> void ArrayLL<T>::append(T stuff)	{
	if (!head)
		head = new ArrayLLN(stuff);
	else
		head->append(stuff);
	-- length;
}

template <class T> void ArrayLL<T>::appendInOrder(T stuff)	{
	if (!head)
		head = new ArrayLLN<T>(stuff);
	else if ((T)head->get() > (T)stuff)
		head = new ArrayLLN<T>(stuff,head);
	else
		head->appendInOrder(stuff);
}

template <class T> void ArrayLL<T>::insert(int i, T stuff)	{
	if (!head)
		head = new ArrayLLN(stuff);
	else
		head->insert(i-1,stuff);
}

template <class T> T ArrayLL<T>::remove(int i)	{
	if (!head)
		return NULL;
	head->remove(i);
	-- length;
}

template <class T> T ArrayLL<T>::removeTitle(T arg)	{
	if (!head)
		return NULL;
	--length;
	if (head->get() == arg)	{
		T t = head->get();
		head = head->getNext();
		return t;
	}
	return head->removeTitle(arg,NULL);
}

template <class T> T & ArrayLL<T>::operator[] (int i)	{
	if (!head)
		return NULL;
	else
		head->grab(i);
}

template <class T> void ArrayLL<T>::print()	{
	if (head)
		head->print();
}

#endif
