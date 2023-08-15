#include"menu.h"

int main()
{
	cout << "有一些地方有问题：1、层次遍历自下而上有bug	" << endl;
	cout << "2、用了线索的话是新类型二叉树结点，原来数据类型下的递归非递归用不了" << endl;
	cout << "3、堆树的堆排序第一项重复了" << endl;

	int choice;
	int Height, count=0;
	bool flag_0 = true,flag;
	BinaryTreeNode* BTroot, * tree[10];
	student newvalue;

	//初始数据
	char number[][8] = { "    ","101","102","103","104","105","106","107","108" };
	char name[][8] = { "    ","阿呆","小尚","Each","杰哥","大陆","乌龟","昏睡","哈哈" };
	char sex[][8] = { "    ","男","女","男","男","男","女","女","男" };
	char place[][8] = { "    ","www1","www2","www3","www4","www5","www6","www7","www8" };
	int age[] = { 0,111,222,333,444,555,666,777,888 };
	BinaryTree AppBT;
	for (int i = 1; i < 9; i++)
	{
		strcpy_s(newvalue.number, number[i]);
		strcpy_s(newvalue.name, name[i]);
		strcpy_s(newvalue.place, place[i]);
		strcpy_s(newvalue.sex, sex[i]);
		newvalue.age = age[i];
		tree[i] = AppBT.MakeNode(newvalue);
	}

	//连接树叶
	AppBT.MakeBinaryTree(tree[1], tree[2], tree[3]);	//				tree[1]
	AppBT.MakeBinaryTree(tree[2], tree[4], NULL);		//		tree[2]			tree[3]
	AppBT.MakeBinaryTree(tree[3], tree[5], tree[6]);	//  tree[4]			tree[5]	  tree[6]
	AppBT.MakeBinaryTree(tree[4], NULL, tree[7]);		//		tree[7]		
	AppBT.MakeBinaryTree(tree[7], NULL, tree[8]);		//			tree[8]
	BTroot = tree[1];
	while (true)
	{
		cout << endl;
		cout << "-----------二叉树链式存储运算--------------" << endl;
		cout << "---1----探测高度" << endl;
		cout << "---2----计算结点个数" << endl;
		cout << "---3----遍历递归" << endl;
		cout << "---4----遍历非递归" << endl;
		cout << "---5----层次遍历" << endl;
		cout << "---6----删除所有结点" << endl;
		cout << "---7----线索化二叉树" << endl;
		cout << "---8----分类二叉树" << endl;
		cout << "---9----堆树" << endl;
		cout << "---0----退出程序" << endl;
		cout << "----------请选择功能：";
		cin >> choice;
		cout << endl;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			Height = AppBT.Height(BTroot);
			cout << "此二叉树的高度为:" << Height << endl;
			break;
		}
		case 2:
		{
			count = 0;
			AppBT.NodeCount(BTroot, count);
			cout << "此二叉树的结点个数为:" << count << endl;
			break;
		}
		case 3:
		{
			side_menu1(AppBT, BTroot);
			break;
		}
		case 4:
		{
			side_menu2(AppBT, BTroot);
			break;
		}
		case 5:
		{
			side_menu3(AppBT, BTroot);
			break;
		}
		case 6:
		{
			BTroot = AppBT.DeleteBinaryTree(BTroot);
			cout << "清除成功" << endl;
			break;
		}
		case 7:
		{
			if (flag_0)
			{
				side_menu4(AppBT, BTroot, flag);
				flag_0 = false;
			}
			if (flag)
				side_menu6(AppBT, BTroot);
			else
				side_menu5(AppBT, BTroot);
			break;
		}
		case 8:
		{
			side_menu7(AppBT, BTroot);
			break;
		}
		case 9:
		{
			side_menu8();
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		}
		system("pause");
		system("cls");
	}
}