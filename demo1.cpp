#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};
//khoi tao
NODE* CreateNode(int x)
{
    NODE* p = new NODE();
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
//tim vi tri can chen
NODE* FindInsert(NODE* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}
//chen node
void InsertNode(NODE* &root, int x)
{
    NODE* n = CreateNode(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        NODE* f = FindInsert(root, x);
        if (f != NULL)
        {
            if (f->data > x)
            {
                f->pLeft = n;
            }
            else
            {
                f->pRight = n;
            }
        }
    }
}
//tao cay tim kiem nhi phan
void CreateTree(NODE* &root, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, a[i]);
    }
}
//tim kiem bang vong lap
NODE* SearchNode(NODE* root, int x)
{
    if (root == NULL)
        return NULL;

	NODE* p = root;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		else if (p->data > x)
		{
			p = p->pLeft;
		}
		else
		{
			p = p->pRight;
		}
	}
}
//duyet cay node-trai-phai
void NLR(NODE* root)
{
	if (root != NULL)
	{
		cout<<root->data<<"\t";
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}
//duyet trai-node-phai
void LNR(NODE* root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		cout<<root->data<<"\t";
		LNR(root->pRight);
	}
}
//duyet trai phai node
void LRN(NODE* root)
{
	if (root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		cout<<root->data<<"\t";
	}
}

int main()
{
	NODE* root = NULL;
	int a[] = { 50, 1, 35, 15, 95, 16, 48, 111, 16, 49, 47 };
	int n = 11;
    cout<<"gia tri cua cay nhi phan:";
	CreateTree(root, a, n);
    cout<<"tim kiem:";
    SearchNode(root,16);
    cout<<"node-trai-phai"<<endl;
	NLR(root);
    cout<<"trai-node-phai"<<endl;
	LNR(root);
    cout<<"trai-phai-node"<<endl;
	LRN(root);
	return 0;
}
