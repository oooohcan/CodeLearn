#include"menu.h"

int main()
{
	cout << "��һЩ�ط������⣺1����α������¶�����bug	" << endl;
	cout << "2�����������Ļ��������Ͷ�������㣬ԭ�����������µĵݹ�ǵݹ��ò���" << endl;
	cout << "3�������Ķ������һ���ظ���" << endl;

	int choice;
	int Height, count=0;
	bool flag_0 = true,flag;
	BinaryTreeNode* BTroot, * tree[10];
	student newvalue;

	//��ʼ����
	char number[][8] = { "    ","101","102","103","104","105","106","107","108" };
	char name[][8] = { "    ","����","С��","Each","�ܸ�","��½","�ڹ�","��˯","����" };
	char sex[][8] = { "    ","��","Ů","��","��","��","Ů","Ů","��" };
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

	//������Ҷ
	AppBT.MakeBinaryTree(tree[1], tree[2], tree[3]);	//				tree[1]
	AppBT.MakeBinaryTree(tree[2], tree[4], NULL);		//		tree[2]			tree[3]
	AppBT.MakeBinaryTree(tree[3], tree[5], tree[6]);	//  tree[4]			tree[5]	  tree[6]
	AppBT.MakeBinaryTree(tree[4], NULL, tree[7]);		//		tree[7]		
	AppBT.MakeBinaryTree(tree[7], NULL, tree[8]);		//			tree[8]
	BTroot = tree[1];
	while (true)
	{
		cout << endl;
		cout << "-----------��������ʽ�洢����--------------" << endl;
		cout << "---1----̽��߶�" << endl;
		cout << "---2----���������" << endl;
		cout << "---3----�����ݹ�" << endl;
		cout << "---4----�����ǵݹ�" << endl;
		cout << "---5----��α���" << endl;
		cout << "---6----ɾ�����н��" << endl;
		cout << "---7----������������" << endl;
		cout << "---8----���������" << endl;
		cout << "---9----����" << endl;
		cout << "---0----�˳�����" << endl;
		cout << "----------��ѡ���ܣ�";
		cin >> choice;
		cout << endl;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			Height = AppBT.Height(BTroot);
			cout << "�˶������ĸ߶�Ϊ:" << Height << endl;
			break;
		}
		case 2:
		{
			count = 0;
			AppBT.NodeCount(BTroot, count);
			cout << "�˶������Ľ�����Ϊ:" << count << endl;
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
			cout << "����ɹ�" << endl;
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