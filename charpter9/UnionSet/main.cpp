#include <iostream>

using namespace std;

const int N = 100;
int father[N];

//�Ҹ��ڵ�, ����x���ڼ��ϵĸ��ڵ�
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
    //��ʱxΪ���ڵ�
    while(a != father[a])
    {
        int z = a;
        a = father[a];//a���a�ĸ���
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
