#pragma once
#include"Binarytree.h"
#include"HeapTree.h"

student newvalue,result;
void input(student& newvalue)
{
	cout << "����Ľ������:";
	cout << endl << "���䣺";	cin >> newvalue.age;
	cout << endl << "������";	cin >> newvalue.name;
	cout << endl << "�Ա�";	cin >> newvalue.sex;
	cout << endl << "ѧ�ţ�";	cin >> newvalue.number;
	cout << endl << "��ַ��";	cin >> newvalue.place;
}
void side_menu1(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------�������ı����ݹ����-----------------" << endl;
	cout << "---1----ǰ������ݹ����" << endl;
	cout << "---2----��������ݹ����" << endl;
	cout << "---3----��������ݹ����" << endl;
	cout << "---0----�����ϼ��˵�" << endl;
	cout << "------------��ѡ����:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     ������ǰ������ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.PreOrderRecursive(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     ��������������ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.InOrderRecursive(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     ��������������ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
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
	cout << "---------------�������ķǵݹ�������-----------------" << endl;
	cout << "---1----ǰ������ǵݹ����" << endl;
	cout << "---2----��������ǵݹ����" << endl;
	cout << "---3----��������ǵݹ����" << endl;
	cout << "---0----�����ϼ��˵�" << endl;
	cout << "------------��ѡ����:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     ������ǰ��Ǳ����ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.PreOrderNoRecursive(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     ����������Ǳ����ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.InOrderNoRecursive(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     ����������Ǳ����ݹ���:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
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
	cout << "---------------�������Ĳ�α������-----------------" << endl;
	cout << "---1----���϶��� ��������" << endl;
	cout << "---2----���϶��� ��������" << endl;
	cout << "---3----���¶��� ��������" << endl;
	cout << "---4----���¶��� ��������" << endl;
	cout << "---0----�����ϼ��˵�" << endl;
	cout << "------------��ѡ����:";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "     ���������϶��� �������ұ������:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.LevelOrder_LtoR_UtoD(BTroot);
		cout << endl;
		break;
	case 2:
		cout << "     ���������϶��� ��������������:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.LevelOrder_RtoL_UtoD(BTroot);
		cout << endl;
		break;
	case 3:
		cout << "     ���������¶��� �������ұ������:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
		AppBT.LevelOrder_LtoR_DtoU(BTroot);
		cout << endl;
		break;

	case 4:
		cout << "     ���������¶��� ��������������:" << endl;
		cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
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
	cout << "!!!!!!!ע��˲��������棬��ֻ��������һ��!!!!!!" << endl;
	cout << "---------------��������������-----------------" << endl;
	cout << "---1----����������" << endl;
	cout << "---2----����������" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		AppBT.PreOrderThreading(BTroot);
		cout << "ǰ���������ɹ�������" << endl;
		flag = false;
		break;
	case 2:
		AppBT.InOrderThreading(BTroot);
		cout << "�����������ɹ�������" << endl;
		flag = true;
		break;
	}
}
void side_menu5(BinaryTree& AppBT, BinaryTreeNode* BTroot)
{
	int choice;
	cout << "---------------������������������-----------------" << endl;
	cout << "---1----�������" << endl;
	cout << "---0----�������˵�" << endl;
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
	cout << "---------------������������������-----------------" << endl;
	cout << "---1----�������" << endl;
	cout << "---2----�ڸ��ڵ��������" << endl;
	cout << "---3----�ڸ��ڵ�����Һ���" << endl;
	cout << "---0----�������˵�" << endl;
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
	cout << "---------------�������������-----------------" << endl;
	cout << "---1----���ҽ��" << endl;
	cout << "---2----������" << endl;
	cout << "---3----ɾ�����" << endl;
	cout << "---0----�������˵�" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		cout << "���������ҵ�ѧ�������䣺" << endl;
		cin >> SearchKey;
		if (AppBT.SearchElementSortBinaryTree(BTroot, result, SearchKey))
		{
			cout << "���ҳɹ�" << endl;
			cout << "    ѧ��     ����    �Ա�    ����     סַ     " << endl;
			cout << "     " << result.number << "     " << result.name << "     " << result.sex
				<< "      " << result.age << "     " << result.place << endl;
		}
		else
			cout << "��ѯʧ�ܣ�û�����������" << endl;
		break;
	case 2:
		input(newvalue);
		if (AppBT.InsertElementSortBinaryTree(BTroot, newvalue))
			cout << "����ɹ�������" << endl;
		else
			cout << "����ʧ�ܣ�����" << endl;
		break;
	case 3:
		cout << "��������ɾ�����Ĺؼ��֣��ؼ���Ϊ���䣩��" << endl;
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
	cout << "---------------��������-----------------" << endl;
	cout << "---1----��ʼ������" << endl;
	cout << "---2----������" << endl;
	cout << "---3----ɾ�����" << endl;
	cout << "---4----������" << endl;
	cout << "---0----�������˵�" << endl;
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