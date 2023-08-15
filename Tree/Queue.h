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
	bool IsFull() { return (front == (rear + 1) % (max + 1) ? 1 : 0); };			//����������СΪ��ſռ��С+1��max+1���������1������front
	bool GetFront(QueueType& result);
	bool GetRear(QueueType& result);
	bool EnQueue(QueueType& newvalue);		//ѭ������
	bool DeQueue(QueueType& result);		//ѭ������
	//void DisplayQueue();
	//void DisplayElementQueue(int i);					//�����������ò���
};
Queue::Queue(int maxsize)
{
	max = maxsize;
	element = new QueueType[max + 1];			//�ǵ�+1
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