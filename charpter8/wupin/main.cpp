#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 30;
int n, V, maxValue = 0;  //��Ʒ����n����������V������ֵmaxValue
int w[maxn], c[maxn];

//naive version O(2^n)
//�Է�֧�����Ż�
void DFS(int index, int sumW, int sumC)
{
    if(index == n)
    {
        if(sumW <= V&&sumC > maxValue)
        {
            maxValue = sumC;
        }
        return;
    }
    //�����
    DFS(index+1, sumW, sumC); //��ѡ��index����Ʒ
    DFS(index+1, sumW + w[index],sumC + c[index]); //ѡ��index����Ʒ
}

//Better version
void DFS2(int index, int sumW, int sumC)
{
    if(index == n)
    {
        return ;
    }
    //�����
    DFS(index+1, sumW, sumC); //��ѡ��index����Ʒ
    if(sumW + w[index] <=V)
    {
        if(sumC + c[index] > maxValue)
        {
            maxValue = sumC + c[index];
        }
        DFS2(index+1, sumW + w[index], sumC + c[index]); //ѡ��index����Ʒ
    }
}

int main()
{
    scanf("%d%d", &n,&V);
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &w[i]);
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &c[i]);
    }
    DFS2(0,0,0);
    printf("%d\n", maxValue);
    return 0;
}
