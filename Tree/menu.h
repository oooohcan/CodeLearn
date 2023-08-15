#pragma once
#include"Binarytree.h"
#include"HeapTree.h"

student newvalue,result;
void input(student& newvalue)
{
	cout << "插入的结点数据:";
	cout << endl << "年龄：";	cin >> newvalue.age;
	cout << endl << "姓名：";	cin >> newvalue.name;
	cout << endl << "性别：";	cin >> newvalue.sex;
	cout << endl << "学号：";	cin >> newvalue.number;
	cout << endl << "地址：";	cin >> newvalue.place;
}
void side_menu1(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------二叉树的遍历递归输出-----------------" << endl;
	cout << "---1----前序遍历递归输出" << endl;
	cout << "---2----中序遍历递归输出" << endl;
	cout << "---3----后序遍历递归输出" << endl;
	cout << "---0----返回上级菜单" << endl;
	cout << "------------请选择功能:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     二叉树前序遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.PreOrderRecursive(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     二叉树中序遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.InOrderRecursive(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     二叉树后序遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.PostOrderRecursive(BTroot);
		cout << endl;
		break;
	case 0:
		break;
	}
}

void side_menu2(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------二叉树的非递归遍历输出-----------------" << endl;
	cout << "---1----前序遍历非递归输出" << endl;
	cout << "---2----中序遍历非递归输出" << endl;
	cout << "---3----后序遍历非递归输出" << endl;
	cout << "---0----返回上级菜单" << endl;
	cout << "------------请选择功能:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     二叉树前序非遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.PreOrderNoRecursive(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     二叉树中序非遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.InOrderNoRecursive(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     二叉树后序非遍历递归结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.PostOrderNoRecursive(BTroot);
		cout << endl;
		break;
	case 0:
		break;
	}
}

void side_menu3(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------二叉树的层次遍历输出-----------------" << endl;
	cout << "---1----自上而下 自左向右" << endl;
	cout << "---2----自上而下 自右向左" << endl;
	cout << "---3----自下而上 自左向右" << endl;
	cout << "---4----自下而上 自右向左" << endl;
	cout << "---0----返回上级菜单" << endl;
	cout << "------------请选择功能:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     二叉树自上而下 自左向右遍历结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.LevelOrder_LtoR_UtoD(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     二叉树自上而下 自右向左遍历结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.LevelOrder_RtoL_UtoD(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     二叉树自下而上 自左向右遍历结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.LevelOrder_LtoR_DtoU(BTroot);
		cout << endl;
		break;

	case 4:
		cout << "     二叉树自下而上 自右向左遍历结果:" << endl;
		cout << "    学号     姓名    性别    年龄     住址     " << endl;
		AppBT.LeverOrder_RtoL_DtoU(BTroot);
		cout << endl;
		break;

	case 0:
		break;
	}
}
void side_menu4(BinaryTree& AppBT, BinaryTreeNode* BTroot,bool& flag)
{
	int choice;
	cout << "!!!!!!!注意此操作不可逆，且只能线索化一次!!!!!!" << endl;
	cout << "---------------二叉树的线索化-----------------" << endl;
	cout << "---1----先序线索化" << endl;
	cout << "---2----中序线索化" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		AppBT.PreOrderThreading(BTroot);
		cout << "前序线索化成功！！！" << endl;
		flag = false;
		break;
	case 2:
		AppBT.InOrderThreading(BTroot);
		cout << "中序线索化成功！！！" << endl;
		flag = true;
		break;
	}
}
void side_menu5(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------二叉先序线索树操作-----------------" << endl;
	cout << "---1----先序遍历" << endl;
	cout << "---0----返回主菜单" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		AppBT.PreOrderThreadTraversal(BTroot);
		break;
	case 0:
		break;
	}
}
void side_menu6(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	BinaryTreeNode* newptr;
	cout << "---------------二叉中序线索树操作-----------------" << endl;
	cout << "---1----中序遍历" << endl;
	cout << "---2----在根节点插入左孩子" << endl;
	cout << "---3----在根节点插入右孩子" << endl;
	cout << "---0----返回主菜单" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		AppBT.InOrderThreadTraversal(BTroot);
		break;
	case 2:
		input(newvalue);
		newptr=AppBT.MakeNode(newvalue);
		AppBT.InsertLeftInOrderRhread(BTroot, newptr);
		AppBT.InOrderThreadTraversal(BTroot);
		break;
	case 3:
		input(newvalue);
		newptr = AppBT.MakeNode(newvalue);
		AppBT.InsertRightInOrderRhread(BTroot, newptr);
		AppBT.InOrderThreadTraversal(BTroot);
		break;
	case 0:
		break;
	}
}
void side_menu7(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice,SearchKey;
	student result;
	cout << "---------------分类二叉树操作-----------------" << endl;
	cout << "---1----查找结点" << endl;
	cout << "---2----插入结点" << endl;
	cout << "---3----删除结点" << endl;
	cout << "---0----返回主菜单" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "输入你想找的学生的年龄：" << endl;
		cin >> SearchKey;
		if (AppBT.SearchElementSortBinaryTree(BTroot, result, SearchKey))
		{
			cout << "查找成功" << endl;
			cout << "    学号     姓名    性别    年龄     住址     " << endl;
			cout << "     " << result.number << "     " << result.name << "     " << result.sex
				<< "      " << result.age << "     " << result.place << endl;
		}
		else
			cout << "查询失败，没有这个！！！" << endl;
		break;
	case 2:
		input(newvalue);
		if (AppBT.InsertElementSortBinaryTree(BTroot, newvalue))
			cout << "插入成功！！！" << endl;
		else
			cout << "插入失败！！！" << endl;
		break;
	case 3:
		cout << "输入你想删除结点的关键字（关键字为年龄）：" << endl;
		cin >> SearchKey;
		BTroot=AppBT.DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode(BTroot, SearchKey);
		break;
	case 0:
		break;
	}
}
void side_menu8()
{
	int choice,heapsize = 8;
	Heap Appheap;
	student heap[MaxSpaceSize];
	Appheap.creatHeap(heap);
	cout << "---------------堆树操作-----------------" << endl;
	cout << "---1----初始化最大堆" << endl;
	cout << "---2----插入结点" << endl;
	cout << "---3----删除结点" << endl;
	cout << "---4----堆排序" << endl;
	cout << "---0----返回主菜单" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
	{
		Appheap.InitializeMaxHeap(heap, heapsize);
		Appheap.DisplayHeap(heap, heapsize);
		break;
	}
	case 2:
	{
		Appheap.InsertElementMaxHeap(heap, heapsize, newvalue);
		Appheap.DisplayHeap(heap, heapsize);
		break;
	}
	case 3:
	{
		Appheap.DeleteTopElementMaxHeap(heap, heapsize, result);
		Appheap.DisplayHeap(heap, heapsize);
		break;
	}
	case 4:
	{
		Appheap.HeapSort(heap, heapsize);
		Appheap.DisplayHeap(heap, heapsize);
		break;
	}
	case 0:
		break;
	}
}