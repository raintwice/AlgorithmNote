#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100010;
struct NODE
{
    char data;
    int next;
    bool flag;
}node[maxn];

int main()
{
    for(int i =0;i<maxn;i++)
    {
        node[i].flag= false;
    }
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    for(int i=0;i<n;i++)
    {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int adr;
    for(adr = s1;adr!=-1;adr=node[adr].next)  //s1Á´×÷±ê¼Ç
    {
        node[adr].flag = true;
    }
    for(adr = s2;adr!=-1;adr=node[adr].next)
    {
        if(node[adr].flag == true)
        {
            break;
        }
    }
    if(adr != -1)
    {
        printf("%05d\n", adr);
    }else
    {
        printf("-1\n");
    }
    return 0;
}j
