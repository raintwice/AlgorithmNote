#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct Node
{
    int address;
    char data;
    int next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b)
{
    if(a.flag = false||b.flag == false)
    {
        return a.flag > b.flag;
    }
    else
    {
        return a.data < b.data;
    }
}

int main()
{
    for(int i = 0;i<maxn;i++)
    {
        node[i].flag = false;
    }
    int n, begin, address;
    scanf("%d %d", &n, &address);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int count = 0, adr = begin;
    while(adr != -1)
    {
        node[adr].flag = true;
        count ++;
        adr = node[adr].next;
    }
    if(count ==0)
    {
        printf("0 -1");
    }
    else
    {
        sort(node, node+maxn, cmp);
    }
    return 0;
}
