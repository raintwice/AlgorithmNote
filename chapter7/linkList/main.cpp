#include <iostream>
#include <cstdio>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node * next;
};

typedef node *pNode;

typedef struct linklistNode
{
    pNode head;
    pNode rear;
}*linkList;


linkList create()
{
    linkList p = new linklistNode;
    p->head = NULL;     //ͷ�ڵ�
    p->rear = NULL;     //β�ڵ�
    return p;
}

void init(linkList plink, int array[], int num)
{
    for(int i=0;i<num;i++)
    {
        pNode p = new node;
        p->next = NULL;
        //����ڵ�
        if(plink->head->next == NULL)
        {
            plink->head->next = p;
            plink->rear = p;
        }else
        {
            plink->rear->next = p;
            plink->rear = p;
        }
    }
}

int main()
{

    return 0;
}
