#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

void search(node *root, int x)
{
    if(root == NULL)
    {
        printf("search failed\n");
        return ;
    }
    if(x == root->data)
    {
        printf("%d\n", root->data);
    }else if(x < root->data)
    {
        search(root->lchild, x);
    }else
    {
        search(root->rchild, x);
    }
}

void insert(node *root, int x)
{
    if(root == NULL) //空树，插入
    {
        root = new node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        return;
    }
    if(x == root->data) //查找成功
    {
        return ;
    }else if(x < root->data)
    {
        insert(root->lchild, x);
    }else
    {
        insert(root->rchild, x);
    }
}

node *Create(int data[], int n) //创建
{
    node *root = NULL;
    for(int i=0;i<n;i++)
    {
        insert(root, data[i]);
    }
    return root;
}

node *findMax(node *root)
{
    while(root->rchild != NULL) //不断往右
    {
        root = root->rchild;
    }
    return root;
}

node *findMin(node *root)
{
    while(root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node *root, int x)
{
    if(root == NULL)
    {
        return ;
    }
    if(root->data == x)
    {
        if(root->lchild == NULL && root->rchild == NULL) //leaf
        {
            root = NULL;
        }else if(root->lchild != NULL)
        {
            node *pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        }
        else
        {
            node *next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    }else if(root->data >x)
    {
        deleteNode(root->lchild, x);
    }else
    {
        deleteNode(root->rchild, x);
    }
}

int main()
{
    return 0;
}
