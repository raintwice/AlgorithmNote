#include <iostream>

using namespace std;

const int N = 100;
int father[N];

//找根节点, 返回x所在集合的根节点
int findFather(int x)
{
    while(x!=father[x])
    {
        x = father[x];
    }
    return x;
}

int findFather_re(int x)
{
    if(x == father[x])
    {
        return x;
    }else
    {
        return findFather(father[x]);
    }
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
    {
        father[faA] = faB;
    }
}

int findFatherShort(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }
    //此时x为根节点
    while(a != father[a])
    {
        int z = a;
        a = father[a];//a变成a的父亲
        father[z] = x;
    }
    return x;
}

int main()
{
    for(int i=1;i<=N;i++)
    {
        father[i] = i;
    }
    return 0;
}
