#pragma once
#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

//����ʵ�������Ը�����Ҫ�滻
struct student
{
	char number[10];
	char name[10];
	char sex[10];
	int age;
	char place[10];
};

//������
class BinaryTreeNode
{
public:
	student data;
	BinaryTreeNode* LChild;
	bool Lflag;
	BinaryTreeNode* RChild;
	bool Rflag;
};

//��ջ
class StackType
{
public:
	BinaryTreeNode* ptr;
	bool status;
};

//����
class QueueType
{
public:
	BinaryTreeNode* ptr;
};