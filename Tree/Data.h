#pragma once
#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

//数据实例，可以根据需要替换
struct student
{
	char number[10];
	char name[10];
	char sex[10];
	int age;
	char place[10];
};

//二叉树
class BinaryTreeNode
{
public:
	student data;
	BinaryTreeNode* LChild;
	bool Lflag;
	BinaryTreeNode* RChild;
	bool Rflag;
};

//堆栈
class StackType
{
public:
	BinaryTreeNode* ptr;
	bool status;
};

//队列
class QueueType
{
public:
	BinaryTreeNode* ptr;
};