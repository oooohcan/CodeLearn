#pragma once
#include"Data.h"

class Queue
{
private:
	QueueType* element;
	int front;
	int rear;
	int max;
public:
	Queue(int maxsize = 20);
	~Queue() { delete[]element; };
	bool IsEmpty() { return front == rear; };
	bool IsFull() { return (front == (rear + 1) % (max + 1) ? 1 : 0); };			//定义的数组大小为存放空间大小+1即max+1，多出来的1用来放front
	bool GetFront(QueueType& result);
	bool GetRear(QueueType& result);
	bool EnQueue(QueueType& newvalue);		//循环进队
	bool DeQueue(QueueType& result);		//循环出队
	//void DisplayQueue();
	//void DisplayElementQueue(int i);					//这两个现在用不到
};
Queue::Queue(int maxsize)
{
	max = maxsize;
	element = new QueueType[max + 1];			//记得+1
	front = 0;
	rear = 0;
}
bool Queue::GetFront(QueueType& result)
{
	if (IsEmpty()) return false;
	result = element[(front + 1) % (max + 1)];
	return true;
}
bool Queue::GetRear(QueueType& result)
{
	if (IsEmpty()) return false;
	result = element[rear];
	return true;
}
bool Queue::EnQueue(QueueType& newvalue)
{
	if (IsFull()) return false;
	rear = (rear + 1) % (max + 1);
	element[rear] = newvalue;
	return true;
}
bool Queue::DeQueue(QueueType& result)
{
	if (IsEmpty()) return false;
	front = (front + 1) % (max + 1);
	result = element[front];
	return true;
}