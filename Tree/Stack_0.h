#pragma once
#include"Data.h"

class Stack_0
{
private:
	int top;
	int max;
	student* element;
public:
	Stack_0(int maxsize = 20);
	~Stack_0() { delete[]element; };
	bool IsEmpty() { return top == -1; };
	bool IsFull() { return top >= max - 1; };
	bool GetTop(student& result);
	bool Push(student& newvalue);
	bool Pop(student& result);
	int GetTopAdress() { return top; };
	void DisplayStack();
	//void DisplayElementStack(int i);				这个暂时不用
};
Stack_0::Stack_0(int maxsize)
{
	max = maxsize;
	element = new student[max];
	top = -1;
}
bool Stack_0::GetTop(student& result)
{
	if (IsEmpty()) return false;
	result = element[top];
	return true;
}
bool Stack_0::Push(student& newvalue)
{
	if (IsFull()) return false;
	element[++top] = newvalue;
	return true;
}
bool Stack_0::Pop(student& result)
{
	if (IsEmpty()) return false;
	result = element[top--];
	return true;
}
void Stack_0::DisplayStack()
{
	for (int i = top; i > -1; i--)
	{
		cout << "     " << element[i].number << "     " << element[i].name << "     " << element[i].sex
			<< "      " << element[i].age << "     " << element[i].place << endl;
	}
}