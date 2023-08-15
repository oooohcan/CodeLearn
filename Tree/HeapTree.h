#pragma once
#include"Data.h"

#define HeapSize  8 
#define MaxSpaceSize  20
class Heap
{
public:
	void creatHeap(student heap[]);
	void DisplayHeap(student heap[], int heapsize);
	bool InitializeMaxHeap(student heap[], int heapSize);
	bool InsertElementMaxHeap(student heap[], int heapSize, student& newvalue);
	bool DeleteTopElementMaxHeap(student heap[], int heapSize, student& result);
	void HeapSort(student heap[], int heapsize);
};

void Heap::creatHeap(student heap[])
{
	char number[][8] = {"	","101","102","103","104","105","106","107","108" };
	char name[][8] = {"	","����","С��","Each","�ܸ�","��½","�ڹ�","��˯","����" };
	char sex[][8] = {"	","��","Ů","��","��","��","Ů","Ů","��" };
	char place[][8] = {"	","www1","www2","www3","www4","www5","www6","www7","www8" };
	int age[] = { 0,111,222,333,444,555,666,777,888 };
	for (int i = 1; i < 9; i++)
	{
		strcpy_s(heap[i].number, number[i]);
		strcpy_s(heap[i].name, name[i]);
		strcpy_s(heap[i].place, place[i]);
		strcpy_s(heap[i].sex, sex[i]);
		heap[i].age = age[i];
	}
}
void Heap::DisplayHeap(student heap[],int heapsize)
{
	for (int i = 0; i < heapsize; i++)
	{
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		cout << "     " << heap[i].number << "     " << heap[i].name << "     " << heap[i].sex
			<< "      " << heap[i].age << "     " << heap[i].place << endl;
	}
}
bool Heap::InitializeMaxHeap(student heap[], int heapSize)			//��ʼ������
{
	for (int i = HeapSize / 2; i >= 1; i--)
	{
		heap[0] = heap[i];										//λ��0��Ϊ�����ռ�
		int son = 2 * i;
		while (son <= HeapSize)
		{
			if (son < HeapSize && heap[son].age < heap[son + 1].age)	//�Ƚ����Һ��ӣ�Ҫ���	
				son++;
			if (heap[0].age >= heap[son].age)
				break;
			heap[son / 2] = heap[son];
			son *= 2;
		}
		heap[son / 2] = heap[0];
	}
	return true;
}
bool Heap::InsertElementMaxHeap(student heap[], int heapSize, student& newvalue)
{
	if (heapSize == MaxSpaceSize)
		return false;								//�������ռ��Ѿ�����
	int i = ++heapSize;								//û���Ļ��öѵĿռ��1
	while (i != 1 && newvalue.age > heap[i / 2].age)
	{
		heap[i] = heap[i / 2];
		i = i / 2;
	}
	heap[i] = newvalue;
	return true;
}
bool Heap::DeleteTopElementMaxHeap(student heap[], int heapSize, student& result)
{
	int parents, son;
	if (heapSize == 0)return false;
	result = heap[1];
	heap[0] = heap[heapSize--];
	parents = 1;
	son = 2 * parents;
	while (son <= heapSize)
	{
		if (son < heapSize && heap[son].age < heap[son + 1].age)
			son++;
		if (heap[0].age >= heap[son].age)
			break;
		heap[parents] = heap[son];
		parents = son;
		son = parents * 2;
	}
	heap[parents] = heap[0];
	return true;
}
void Heap::HeapSort(student heap[], int heapsize)
{
	student temp;
	InitializeMaxHeap(heap, heapsize);
	for (int i = heapsize - 1; i >= 1; i--)
	{
		DeleteTopElementMaxHeap(heap, i + 1, temp);
		heap[i + 1] = temp;
	}
}