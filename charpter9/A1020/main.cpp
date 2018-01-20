#include <iostream>
#include<cstdio>
#include <queue>
using namespace std;

typedef struct node
{
    int data;
    node *lchild;
    node *rchild;
}*tree;
const int maxn = 10000;
int nodeNum = 0;
int post[maxn];
int in[maxn];

tree create(int postL, int postR, int inL, int inR)
{
    if(postL > postR)
        return NULL;
    node *root = new node;
    root->data = post[postR];

    //寻找左右子树
    int k; //中序根位置
    for(k=inL;k<=inR;k++)
    {
        if(post[postR]==in[k])
            break;
    }
    int leftNum = k-inL; //左子树个数
    root->lchild = create(postL, postL+leftNum -1, inL, k-1);
    //右子树
    root->rchild = create(postL + leftNum ,postR -1 , k+1, inR);
    return root;
}

int main()
{
    scanf("%d",&nodeNum);
    for(int i = 0;i<nodeNum;i++)
    {
        scanf("%d", &post[i]);
    }
    for(int i = 0;i<nodeNum;i++)
    {
        scanf("%d", &in[i]);
    }
    tree t= create(0,nodeNum - 1,0,nodeNum-1);
    queue<node *> q;
    q.push(t);
    int num = 0;
    while(!q.empty())
    {
        node *p = q.front();
        q.pop();
        printf("%d",p->data);
        num++;
        if(num<nodeNum)
        {
            printf(" ");
        }
        if(p->lchild != NULL)
        {
            q.push(p->lchild);
        }
        if(p->rchild != NULL)
        {
            q.push(p->rchild);
        }
    }
    return 0;
}
