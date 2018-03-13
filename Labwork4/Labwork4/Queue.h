#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Queue{
private:
	T *queuePtr;
	int begin;
	int	end;
	int size;
	int elementsCounter;
public:
	Queue(T arr[], int);
	~Queue();

	inline void Push( T&);
	inline int GetSizeOfTheQueue();
	inline T Delete();
	inline void Print();
};

template<class T>
Queue<T>::Queue(T arr[], int numberOfElements)
	: begin(0), end(0), size(10), elementsCounter(numberOfElements) {

	queuePtr = new T[size + 1];
	for (int i = 0; i < numberOfElements; i++) {
		queuePtr[end++] = arr[i];
	}

}

template<class T>
inline void Queue<T>::Push( T &newElement) {
	assert(elementsCounter < size);
	queuePtr[end++] = newElement;
	elementsCounter++;
	if (end > size)
		end -= size + 1; 
}

template<class T>
inline T Queue<T>::Delete() {
	assert(elementsCounter > 0);
	T returnValue = queuePtr[begin++];
	elementsCounter--;
	if (begin > size)
		begin -= size + 1; 
	return returnValue;
}

template<class T>
Queue<T>::~Queue() {
	delete[] queuePtr;
}

template<typename T>
inline void Queue<T>::Print()
{
	cout << "Queue: \n";
	if (end == 0 && begin == 0)
		cout << " Empty\n";
	else
	{		
		for (int i = begin; i <end; i++)
			cout << queuePtr[i] << " ";
		cout << endl;
	}
}

template<typename T>
inline int Queue<T>::GetSizeOfTheQueue() {
	return elementsCounter;
}

