#pragma once
#include <string>
//each stack is a peg
template<typename T>
class ArrStack{

public:
	int Top;
	char key;
	T* arr = new T(size);
	int size;
	ArrStack(char x);
	ArrStack(int x, char y);
	bool isEmpty();

	bool isFull();

	void push(int x);

	void display();
	

//do not need to physically pop just decrement Top since when we push a new thing it will be overwritten 
	T pop();

	T peek(int x);

	T stackTop();
};
