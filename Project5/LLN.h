#ifndef _LLN_
#define _LLN_

#include <iostream>
#include <string>
#include <cstdlib>

template <class T> class ArrayLLN	{
private:
	T content;
	ArrayLLN<T> * next;
public:
	ArrayLLN(ArrayLLN<T> *pointer);
	ArrayLLN(T stuff, ArrayLLN<T> *n);
	ArrayLLN(T stuff, T *n);
	ArrayLLN(T stuff);
	~ArrayLLN();
	ArrayLLN<T> * getNext();
	void setNext(ArrayLLN<T> *n);
	T get();
	void insert(int i, T stuff);
	void append(T stuff);
	void appendInOrder(T stuff);
	T remove(int i, ArrayLLN<T> *prev);
	T &grab(int i);
	void print();
};

template <class T> ArrayLLN<T>::ArrayLLN(ArrayLLN<T> *pointer)	{
	content = pointer->get();
	next = pointer->getNext();
}

template <class T> ArrayLLN<T>::ArrayLLN(T stuff, ArrayLLN<T> *n)	{
	content = stuff;
	next = n;
}

template <class T> ArrayLLN<T>::ArrayLLN(T stuff, T *n)	{
	content = stuff;
	next = new ArrayLLN(n);
}

template <class T> ArrayLLN<T>::ArrayLLN(T stuff)	{
	content = stuff;
	next = NULL;
}

template <class T> ArrayLLN<T>::~ArrayLLN()	{
	delete next;
}

template <class T> ArrayLLN<T> *ArrayLLN<T>::getNext()	{
	return next;
}

template <class T> void ArrayLLN<T>::setNext(ArrayLLN<T> * n)	{
	next = n;
}

template <class T> T ArrayLLN<T>::get()	{
	return content;
}

template <class T> void ArrayLLN<T>::append(T stuff)	{
	if (next)
		next->append(stuff);
	else
		next = new ArrayLLN(stuff);
}

template <class T> void ArrayLLN<T>::appendInOrder(T stuff)	{
	if ((T)content != (T)stuff)
		if (!next)
			next = new ArrayLLN(stuff);
		else if ((T)next->get() > (T)stuff)
			next = new ArrayLLN<T>(stuff, next);
		else if ((T)next->get() == (T)stuff)
			return;
		else
			next->appendInOrder(stuff);
}

template <class T> void ArrayLLN<T>::insert(int i, T stuff)	{
	if (!next)
		next = new ArrayLLN(stuff);
	else if (i == 0)
		next = new ArrayLLN(stuff, next);
	else
		next->insert(i-1,stuff);
}

template <class T> T ArrayLLN<T>::remove(int i, ArrayLLN<T> *prev)	{
	if (i == 0)	{
		T t = content;
		prev->setNext(next);
		next = NULL;
		delete this;
		return t;
	}
	else if (i > 0 && !next)	{
		return content;
	}
	else	{
		return next->remove(i-1,this);
	}
}

template <class T> T &ArrayLLN<T>::grab(int i)	{
	if (i > 0 && next)
		return next->grab(i-1);
	else
		return content;
}

template <class T> void ArrayLLN<T>::print()	{
	cout << content << endl;
	if (next)
		next->print();
}

#endif
