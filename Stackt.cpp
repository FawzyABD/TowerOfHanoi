#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

template<typename T>
ArrStack<T>::ArrStack(char x) : Top(-1)
{
	cout << "\nEnter size of stack\n" << endl;
	cin >> size;
	key = x;

}

template<typename T>
ArrStack<T>::ArrStack(int x, char y) : Top(-1)
{
	size = x;
	key = y;

}
template<typename T>
void ArrStack<T>::display(){
	int i = Top;
	cout << this->key <<": " << endl;
	if (isEmpty())
		cout << "Empty!" << endl;
	else 
	{
		for (int y = -1; y < i; i--)
		{
			cout << "Index: " << i << " Disk: " << arr[i] << endl;

		}
	}


}


template<typename T>
bool ArrStack<T>::isEmpty()
{
	if (Top == -1)
		return true;
	else
		return false;

}

template<typename T>
bool ArrStack<T>::isFull()
{
	if (Top == size - 1)
		return true;
	else
		return false;
}


template<typename T>
void ArrStack<T>::push(int x)
{
	if (isFull())
	{
		cout << "stack overflow in"<< key << endl;
	}
	else {
		Top++;
		arr[Top] = x;
	}
}


template<typename T>
T ArrStack<T>::pop()
{
	int x = -2;
	if (isEmpty())
	{
		cout << "stack underflow in"<< key << endl;
	}
	else
	{
		x = arr[Top];
		Top--;
	}

	return x;

}


template<typename T>
T ArrStack<T>::peek(int x)
{
	int y = Top - x + 1;
	T ret = -2;
	if (y < 0) { cout << "Invalid Position" << endl; }
	else {
		ret = arr[y];

	}

	return ret;


}

template<typename T>
T ArrStack<T>::stackTop()
{
	int x = -2;
	if (isEmpty())
		cout << "Stack is empty" << endl;
	else
	{
		x = arr[Top];

	}

	return x;

}
