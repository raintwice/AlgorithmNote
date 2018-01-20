#include <iostream>
#include<cstdio>
#include <cmath>

using namespace std;

struct node
{
    int v, height;
    node *lchild, *rchild;
};

node *newNode(int v)
{
    node *Node = new node;
    Node->v = v;
    Node->height =1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node *root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node *root)  //���Һ��ӱ���ˣ���Ҫ����
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild));
}

void search(node *root, int x)
{
    if(root == NULL)
    {
        printf("search failed\n");
        return ;
    }
    if(x == root->v)
    {
        printf("%d\n", root->v);
    }else if(x < root->v)
    {
        search(root->lchild, x);
    }else
    {
        search(root->rchild, x);
    }
}

//����
void L(node *root)
{
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//����
void R(node *root)
{
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp ->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node *root, int v)
{
    if(root == NULL)
    {
        root = newNode(v);
        return ;
    }
    if(v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)  //��������
        {
            if(getBalanceFactor(root->lchild) == 1) //LL��
            {
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1) //LR��
            {
                L(root->lchild);
                R(root);
            }
        }
    }else
    {
        insert(root->rchild, v); //
        updateHeight(root);  //
        if(getBalanceFactor(root) == -2)
        {
            if(getBalanceFactor(root->rchild) == -1) //RR��
            {
                L(root);
            }else if(getBalanceFactor(root->rchild) == 1) //RL��
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}

node *Create(int data[], int n)
{
    node *root = NULL;
    for(int i = 0;i<n;i++)
    {
        insert(root, data[i]);
    }
    return root;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
