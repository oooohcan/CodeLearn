#pragma once
#include"Data.h"
#include"Stack.h"
#include"Queue.h"
#include"Stack_0.h"

class BinaryTree
{
private:
	BinaryTreeNode* BTroot;
public:
	BinaryTree() { BTroot = NULL; };
	~BinaryTree() {};

				//������ɾ��
	BinaryTreeNode* MakeNode(student& newvalue);														//����������
	void MakeBinaryTree(BinaryTreeNode* root, BinaryTreeNode* left, BinaryTreeNode* right);				//���ӽ������
	BinaryTreeNode* DeleteBinaryTree(BinaryTreeNode* Btroot);											//ɾ��������

				//���������ȡ���ӡ
	void NodeCount(BinaryTreeNode* BTroot, int& count);
	int Height(BinaryTreeNode* BTroot);
	void DisplayNode(BinaryTreeNode* root);

				//�ݹ�����㷨
	void PreOrderRecursive(BinaryTreeNode* BTroot);
	void InOrderRecursive(BinaryTreeNode* BTroot);
	void PostOrderRecursive(BinaryTreeNode* Btroot);

				//�ǵݹ�����㷨
	void PreOrderNoRecursive(BinaryTreeNode* BTroot);
	void InOrderNoRecursive(BinaryTreeNode* BTroot);
	void PostOrderNoRecursive(BinaryTreeNode* BTroot);

				//����α����㷨
	void LevelOrder_LtoR_UtoD(BinaryTreeNode* BTroot);
	void LevelOrder_RtoL_UtoD(BinaryTreeNode* BTroot);
	void LevelOrder_LtoR_DtoU(BinaryTreeNode* BTroot);
	void LeverOrder_RtoL_DtoU(BinaryTreeNode* BTroot);

				//��������������
	void PreOrderThreadTraversal(BinaryTreeNode* BTroot);
	void InOrderThreadTraversal(BinaryTreeNode* BTroot);
			//void PostOrderThreadTraversal(BinaryTreeNode* BTroot);			����Ŀα�û�У���Ϊ���ӣ��Ժ�ɸ�

				//������ת��Ϊ������
	void PreOrderThreading(BinaryTreeNode* BTroot);
	void InOrderThreading(BinaryTreeNode* BTroot);
			//void PostOrderThreading(BinaryTreeNode* BTroot);					����Ŀα�û�У���Ϊ���ӣ��Ժ�ɸ�

				//�������������뺢��
	void InsertLeftInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T);			//T��Ϊ�����Ӳ���S
	void InsertRightInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T);	

				//���������
	bool SearchElementSortBinaryTree(BinaryTreeNode* BTroot, student& reult, int& SearchKey);
	bool InsertElementSortBinaryTree(BinaryTreeNode* BTroot, student& newvalue);
	BinaryTreeNode* DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode(BinaryTreeNode* BTroot, int& SearchKey);

};

BinaryTreeNode* BinaryTree::MakeNode(student& newvalue)
{
	BinaryTreeNode* ptr;					//����һ����������Ϊ�������ָ��
	ptr = new BinaryTreeNode;				//ptrָ��new�����Ķ��������ռ�
	if (!ptr) return NULL;					//��⹹��ɹ���û
	ptr->data = newvalue;
	ptr->LChild = NULL;
	ptr->Lflag = NULL;
	ptr->RChild = NULL;
	ptr->Rflag = NULL;
	return ptr;
}
void BinaryTree::MakeBinaryTree(BinaryTreeNode* root, BinaryTreeNode* left, BinaryTreeNode* right)
{
	root->LChild = left;					//��������������ҽ����ѣ�����Ļ�û����
	root->RChild = right;
}
BinaryTreeNode* BinaryTree::DeleteBinaryTree(BinaryTreeNode* BTroot)
{
	if (BTroot)
	{
		DeleteBinaryTree(BTroot->LChild);
		DeleteBinaryTree(BTroot->RChild);
		delete BTroot;						//�ú�������ķ�ʽɾ�����
	}
	BTroot = NULL;
	return BTroot;							//ɾ��󷵻ؿ�ָ��
}
void BinaryTree::NodeCount(BinaryTreeNode* BTroot, int& count)
{
	if (BTroot)
	{
		count++;							//��ǰ������ķ�ʽ����
		NodeCount(BTroot->LChild, count);
		NodeCount(BTroot->RChild, count);
	}
}
int BinaryTree::Height(BinaryTreeNode* BTroot)
{
	if (!BTroot)return 0;
	int Lheight = Height(BTroot->LChild);
	int Rheight = Height(BTroot->RChild);
	if (Lheight > Rheight)
		return ++Lheight;
	else
		return ++Rheight;
}
void BinaryTree::DisplayNode(BinaryTreeNode* root)
{
	cout << "     " << root->data.number << "     " << root->data.name << "     " << root->data.sex
		<< "      " << root->data.age << "     " << root->data.place << endl;
}

void BinaryTree::PreOrderRecursive(BinaryTreeNode* BTroot)
{
	if (BTroot)
	{
		DisplayNode(BTroot);
		PreOrderRecursive(BTroot->LChild);
		PreOrderRecursive(BTroot->RChild);
	}
}
void BinaryTree::InOrderRecursive(BinaryTreeNode* BTroot)
{
	if (BTroot)
	{
		InOrderRecursive(BTroot->LChild);
		DisplayNode(BTroot);
		InOrderRecursive(BTroot->RChild);
	}
}
void BinaryTree::PostOrderRecursive(BinaryTreeNode* BTroot)
{
	if (BTroot)
	{
		PostOrderRecursive(BTroot->LChild);
		PostOrderRecursive(BTroot->RChild);
		DisplayNode(BTroot);
	}
}

void BinaryTree::PreOrderNoRecursive(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	StackType temp;
	int maxsize = Height(BTroot);
	Stack S(maxsize);
	while (p || !S.IsEmpty())
	{
		if (p)
		{
			DisplayNode(p);
			temp.ptr = p;
			S.Push(temp);
			p = p->LChild;
		}
		else
			if (!S.IsEmpty())
			{
				S.Pop(temp);
				p = temp.ptr;
				p = p->RChild;
			}
	}
}
void BinaryTree::InOrderNoRecursive(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	StackType temp;
	int maxsize = Height(BTroot);
	Stack S(maxsize);
	while (p || !S.IsEmpty())
	{
		while (p)
		{
			temp.ptr = p;
			S.Push(temp);
			p = p->LChild;
		}
		if (!S.IsEmpty())
		{
			S.Pop(temp);
			p = temp.ptr;
			DisplayNode(p);
			p = p->RChild;
		}
	}
}
void BinaryTree::PostOrderNoRecursive(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	StackType temp;
	int maxsize = Height(BTroot);
	Stack S(maxsize);
	while (p || !S.IsEmpty())
	{
		if (p)
		{
			temp.ptr = p;
			temp.status = false;
			S.Push(temp);
			p = p->LChild;
		}
		else
			if (!S.IsEmpty())
			{
				S.Pop(temp);
				p = temp.ptr;
				if (!temp.status)
				{
					temp.status = true;
					S.Push(temp);
					p = p->RChild;
				}
				else
				{
					DisplayNode(p);
					p = NULL;
				}
			}

	}
}

void BinaryTree::LevelOrder_LtoR_UtoD(BinaryTreeNode* BTroot)
{
	int count = 0;
	NodeCount(BTroot, count);
	Queue Q(count);
	QueueType temp;
	BinaryTreeNode* p;
	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);
	while (p)
	{
		if (!Q.DeQueue(temp)) return;				//����ж�����˼���Գ����Ƿ�ɹ��ж��Ƿ�ӿգ����Ӻ��������ж϶ӿպ�����
		p = temp.ptr;
		DisplayNode(p);
		if (p->LChild)
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);
		}
		if (p->RChild)
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);
		}
	}
}
void BinaryTree::LevelOrder_RtoL_UtoD(BinaryTreeNode* BTroot)
{
	int count = 0;
	NodeCount(BTroot, count);
	Queue Q(count);
	QueueType temp;
	BinaryTreeNode* p;
	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);
	while (p)
	{
		if (!Q.DeQueue(temp)) return;					//return�󲻼Ӳ�������ֱ�ӽ�������
		p = temp.ptr;
		DisplayNode(p);
		if (p->RChild)
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);
		}
		if (p->LChild)
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);
		}
	}
}
void BinaryTree::LevelOrder_LtoR_DtoU(BinaryTreeNode* BTroot)
{
	int count;
	NodeCount(BTroot, count);
	Queue Q(count);
	Stack_0 S(count);
	BinaryTreeNode* p = BTroot;
	QueueType temp;
	temp.ptr = p;
	Q.EnQueue(temp);
	while (p)
	{
		if (!Q.DeQueue(temp)) break;
		p = temp.ptr;
		S.Push(temp.ptr->data);
		if (p->RChild)
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);
		}
		if (p->LChild)
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);
		}
	}
	S.DisplayStack();
}
void BinaryTree::LeverOrder_RtoL_DtoU(BinaryTreeNode* BTroot)
{
	int count;
	NodeCount(BTroot, count);
	Queue Q(count);
	Stack_0 S(count);
	QueueType temp;
	BinaryTreeNode* p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);
	while (p)
	{
		if (!Q.DeQueue(temp)) break;				//����return��break����Ϊ�ӿպ�ջ�ڿ��ܻ�û���꣬��ʱ��������ѭ�������滹�÷���
		p = temp.ptr;
		S.Push(temp.ptr->data);
		if (p->LChild)
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);
		}
		if (p->RChild)
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);
		}
	}
	S.DisplayStack();
}

void BinaryTree::PreOrderThreadTraversal(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	while (p)
	{
		DisplayNode(p);
		if (!p->Lflag)
			p = p->LChild;				//LflagΪflase�Ļ�������������������
		else
			p = p->RChild;				//����������LflagΪtrue����ʱ����RChild��������̽�㣨ĳ��������
	}
}
void BinaryTree::InOrderThreadTraversal(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	bool flag;
	while (p)
	{
		while (!p->Lflag)					//Ѱ����������
			p = p->LChild;
		flag = true;
		while (flag && p)
		{
			DisplayNode(p);
			if (!p->Rflag)					//���������Ļ�׼������Сѭ����û�еĻ��ͼ������
				flag = p->Rflag;
			p = p->RChild;					//ָ��ָ���̻�������
		}
	}
}

void BinaryTree::PreOrderThreading(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot, * q = NULL;
	StackType temp;
	int count = 0;
	NodeCount(BTroot, count);
	Stack S(count);
	while (p || !S.IsEmpty())
	{
		while (p)
		{
			temp.ptr = p;
			S.Push(temp);
			if (p->RChild)
				p->Rflag = false;
			else
				p->Rflag = true;
			if (p->LChild)
			{
				if (!p->RChild)
					p->RChild = p->LChild;			//���ڵ�������������
				p->Lflag = false;
				q = p;
				p = p->LChild;
			}
			else
			{
				p->Lflag = true;
				p->LChild = q;
				q = p;
				break;
			}
		}
		if (!S.IsEmpty())
		{
			S.Pop(temp);
			p = temp.ptr;
			if (!p->Rflag)
			{
				q->RChild = p->RChild;
				p = p->RChild;
			}
			else
				p = NULL;
		}
	}
	q->Rflag = true;
	q->RChild = NULL;
}
void BinaryTree::InOrderThreading(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot, * q = NULL;
	StackType temp;
	int count = 0;
	NodeCount(BTroot, count);
	Stack S(count);
	while (p || !S.IsEmpty())
	{
		while (p)
		{
			temp.ptr = p;
			S.Push(temp);
			if (p->LChild)
			{
				p->Lflag = false;
				p = p->LChild;
			}
			else
			{
				p->LChild = q;
				p->Lflag = true;
				q = p;
				p = NULL;
			}
		}
		if (!S.IsEmpty())
		{
			S.Pop(temp);
			p = temp.ptr;
			p->Rflag = false;
			if (!q->RChild && q != p)
			{
				q->RChild = p;
				q->Rflag = true;
				q = p;
			}
			p = p->RChild;
		}
	}
	q->Rflag = true;
}

void BinaryTree::InsertLeftInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T)
{
	BinaryTreeNode* q;
	T->Rflag = true;
	T->RChild = S;
	T->Lflag = S->Lflag;
	T->LChild = S->LChild;
	S->Lflag = false;
	S->LChild = T;
	if (!T->Lflag)
	{
		q = T->LChild;
		while (!q->Rflag)
			q = q->RChild;
		q->RChild = T;
	}
}
void BinaryTree::InsertRightInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T)
{
	BinaryTreeNode* q;
	T->Lflag = true;
	T->LChild = S;
	T->Rflag = S->Rflag;
	T->RChild = S->RChild;
	S->Rflag = false;
	S->RChild = T;
	if (!T->Rflag)
	{
		q = T->RChild;
		while (!q->Lflag)
			q = q->LChild;
		q->LChild = T;
	}
}

bool BinaryTree::SearchElementSortBinaryTree(BinaryTreeNode* BTroot, student& result, int& SearchKey)
{
	BinaryTreeNode* p = BTroot;
	while (p)
		if (SearchKey < p->data.age)
			p = p->LChild;
		else
			if (SearchKey > p->data.age)
				p = p->RChild;
			else
			{
				result = p->data;
				return true;
			}
	return false;
}
bool BinaryTree::InsertElementSortBinaryTree(BinaryTreeNode* BTroot, student& newvalue)
{
	BinaryTreeNode* p = BTroot;
	BinaryTreeNode* parent = NULL;
	while (p)
	{
		parent = p;
		if (newvalue.age < p->data.age)
			p = p->LChild;
		else
			if (newvalue.age > p->data.age)
				p = p->RChild;
			else
				return false;				//�ظ�����,ɾ����else��ʾ�ظ��ķ�������
	}
	BinaryTreeNode* q = new BinaryTreeNode;
	q->data = newvalue;
	q->LChild = NULL;
	q->RChild = NULL;
	if (BTroot)
	{
		if (newvalue.age < parent->data.age)
			parent->LChild = q;
		else
			parent->RChild = q;
	}
	else
		BTroot = q;
	return true;
}
BinaryTreeNode* BinaryTree::DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode(BinaryTreeNode* BTroot, int& SearchKey)
{
	BinaryTreeNode* p = BTroot, * parent = NULL;
	BinaryTreeNode* son, * ps;
	while (p&&p->data.age!=SearchKey)
	{
		parent = p;
		if (SearchKey < p->data.age)
			p = p->LChild;
		else
			p = p->RChild;
	}
	if (!p)
	{
		cout << "*******û��ɾ�����******" << endl;
		return BTroot;
	}
	if (p->LChild && p->RChild)			//��ɾ�����������
	{
		son = p->LChild;
		ps = p;
		while (son->RChild)				//�������������������ƽ�������ֵ�滻����ɾ���
		{
			ps = son;
			son = son->RChild;
		}
		p->data = son->data;
		p = son;
		parent = ps;
	}
	if (p->LChild)
		son = p->LChild;
	else
		son = p->RChild;				//��ɾ������Һ��ӻ����޺���
	if (p == BTroot)
		BTroot = son;					//��ɾ���Ǹ����ֱ�ӽ��ҵ����ӽ�����ȥ
	else								//�ж�p��parent�������Һ���
	{
		if (p == parent->LChild)
			parent->LChild = son;
		else
			parent->RChild = son;
	}
	cout << "ɾ���ɹ�����";
	delete p;
	return BTroot;
}