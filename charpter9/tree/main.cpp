#include <iostream>
#include<queue>
#include <cstdio>

using namespace std;

typedef int datatype;

struct node
{
    datatype data;
    node *lchild;
    node *rchild;
};
typedef node *tree;

node *newNode(datatype v)
{
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

bool search(tree t, datatype x)
{
    if(t == NULL)
    {
        return false;
    }
    if(t->data == x)
    {
        return true;
    }
    bool res = search(t->lchild, x)||search(t->rchild, x);
    return res;
}

void preorder(node * root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%d\n", root->data);
    //访问左
    preorder(root->lchild);
    //
    preorder(root->rchild);
}

void LayerOrder(node * root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *now = q.front();
        q.pop();
        printf("%d", now->data);
        if(now->lchild != NULL)
        {
            q.push(now->lchild);
        }
        if(now->rchild!= NULL)
        {
            q.push(now->rchild);
        }
    }

}

//通过先根序列和中根序列
const int maxn = 100;
int pre[maxn];
int in[maxn];
node *create(int preL, int preR, int inL, int inR)
{
    if(preL>preR)
        return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==pre[preL])
        {
            break;
        }
    }
    int numLeft = k - inL;//此处需小心 左子树个数
    root->lchild = create(preL+1,preL+numLeft, inL,k-1);
    root->rchild = create(preL+numLeft+1, preR,k+1,inR);
    return root;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
