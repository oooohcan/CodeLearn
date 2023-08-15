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

				//加入与删除
	BinaryTreeNode* MakeNode(student& newvalue);														//赋予结点数据
	void MakeBinaryTree(BinaryTreeNode* root, BinaryTreeNode* left, BinaryTreeNode* right);				//连接结点上树
	BinaryTreeNode* DeleteBinaryTree(BinaryTreeNode* Btroot);											//删除整棵树

				//结点数、深度、打印
	void NodeCount(BinaryTreeNode* BTroot, int& count);
	int Height(BinaryTreeNode* BTroot);
	void DisplayNode(BinaryTreeNode* root);

				//递归遍历算法
	void PreOrderRecursive(BinaryTreeNode* BTroot);
	void InOrderRecursive(BinaryTreeNode* BTroot);
	void PostOrderRecursive(BinaryTreeNode* Btroot);

				//非递归遍历算法
	void PreOrderNoRecursive(BinaryTreeNode* BTroot);
	void InOrderNoRecursive(BinaryTreeNode* BTroot);
	void PostOrderNoRecursive(BinaryTreeNode* BTroot);

				//按层次遍历算法
	void LevelOrder_LtoR_UtoD(BinaryTreeNode* BTroot);
	void LevelOrder_RtoL_UtoD(BinaryTreeNode* BTroot);
	void LevelOrder_LtoR_DtoU(BinaryTreeNode* BTroot);
	void LeverOrder_RtoL_DtoU(BinaryTreeNode* BTroot);

				//二叉线索树遍历
	void PreOrderThreadTraversal(BinaryTreeNode* BTroot);
	void InOrderThreadTraversal(BinaryTreeNode* BTroot);
			//void PostOrderThreadTraversal(BinaryTreeNode* BTroot);			后序的课本没有，较为复杂，以后可搞

				//二叉树转化为线索树
	void PreOrderThreading(BinaryTreeNode* BTroot);
	void InOrderThreading(BinaryTreeNode* BTroot);
			//void PostOrderThreading(BinaryTreeNode* BTroot);					后序的课本没有，较为复杂，以后可搞

				//中序线索树插入孩子
	void InsertLeftInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T);			//T作为新左孩子插入S
	void InsertRightInOrderRhread(BinaryTreeNode* S, BinaryTreeNode* T);	

				//分类二叉树
	bool SearchElementSortBinaryTree(BinaryTreeNode* BTroot, student& reult, int& SearchKey);
	bool InsertElementSortBinaryTree(BinaryTreeNode* BTroot, student& newvalue);
	BinaryTreeNode* DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode(BinaryTreeNode* BTroot, int& SearchKey);

};

BinaryTreeNode* BinaryTree::MakeNode(student& newvalue)
{
	BinaryTreeNode* ptr;					//定义一个数据类型为二叉结点的指针
	ptr = new BinaryTreeNode;				//ptr指向new出来的二叉树结点空间
	if (!ptr) return NULL;					//检测构造成功了没
	ptr->data = newvalue;
	ptr->LChild = NULL;
	ptr->Lflag = NULL;
	ptr->RChild = NULL;
	ptr->Rflag = NULL;
	return ptr;
}
void BinaryTree::MakeBinaryTree(BinaryTreeNode* root, BinaryTreeNode* left, BinaryTreeNode* right)
{
	root->LChild = left;					//连接它下面的左右结点而已，上面的还没处理
	root->RChild = right;
}
BinaryTreeNode* BinaryTree::DeleteBinaryTree(BinaryTreeNode* BTroot)
{
	if (BTroot)
	{
		DeleteBinaryTree(BTroot->LChild);
		DeleteBinaryTree(BTroot->RChild);
		delete BTroot;						//用后序遍历的方式删除结点
	}
	BTroot = NULL;
	return BTroot;							//删完后返回空指针
}
void BinaryTree::NodeCount(BinaryTreeNode* BTroot, int& count)
{
	if (BTroot)
	{
		count++;							//用前序遍历的方式计数
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
		if (!Q.DeQueue(temp)) return;				//这个判断有意思，以出队是否成功判断是否队空（出队函数内有判断队空函数）
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
		if (!Q.DeQueue(temp)) return;					//return后不加参数可以直接结束函数
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
		if (!Q.DeQueue(temp)) break;				//不用return用break，因为队空后栈内可能还没排完，此时结束遍历循环，后面还得访问
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
			p = p->LChild;				//Lflag为flase的话则正常往左子树访问
		else
			p = p->RChild;				//最左子树的Lflag为true，此时访问RChild则访问其后继结点（某右子树）
	}
}
void BinaryTree::InOrderThreadTraversal(BinaryTreeNode* BTroot)
{
	BinaryTreeNode* p = BTroot;
	bool flag;
	while (p)
	{
		while (!p->Lflag)					//寻找最左子树
			p = p->LChild;
		flag = true;
		while (flag && p)
		{
			DisplayNode(p);
			if (!p->Rflag)					//有右子树的话准备结束小循环，没有的话就继续后继
				flag = p->Rflag;
			p = p->RChild;					//指针指向后继或右子树
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
					p->RChild = p->LChild;			//根节点后继连向其左孩子
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
				return false;				//重复出现,删掉此else表示重复的放右子树
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
		cout << "*******没有删除结点******" << endl;
		return BTroot;
	}
	if (p->LChild && p->RChild)			//被删结点有俩孩子
	{
		son = p->LChild;
		ps = p;
		while (son->RChild)				//向左子树的最右子树推进，将其值替换进被删结点
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
		son = p->RChild;				//被删结点有右孩子或者无孩子
	if (p == BTroot)
		BTroot = son;					//被删的是根结点直接将找到的子结点放上去
	else								//判断p是parent的左还是右孩子
	{
		if (p == parent->LChild)
			parent->LChild = son;
		else
			parent->RChild = son;
	}
	cout << "删除成功！！";
	delete p;
	return BTroot;
}