#pragma once
#include"Data.h"

class Stack
{
private:
	int top;
	int max;
	StackType* element;
public:
	Stack(int maxsize = 20);
	~Stack() { delete[]element; };
	bool IsEmpty() { return top == -1; };
	bool IsFull() { return top >= max - 1; };
	bool GetTop(StackType& result);
	bool Push(StackType& newvalue);
	bool Pop(StackType& result);
	int GetTopAdress() { return top; };
	//void DisplayStack();
	//void DisplayElementStack(int i);				这两个暂时不用
};
Stack::Stack(int maxsize)
{
	max = maxsize;
	element = new StackType[max];
	top = -1;
}
bool Stack::GetTop(StackType& result)
{
	if (IsEmpty()) return false;
	result = element[top];
	return true;
}
bool Stack::Push(StackType& newvalue)
{
	if (IsFull()) return false;
	element[++top] = newvalue;
	return true;
}
bool Stack::Pop(StackType& result)
{
	if (IsEmpty()) return false;
	result = element[top--];
	return true;
}