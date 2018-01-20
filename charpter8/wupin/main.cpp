#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 30;
int n, V, maxValue = 0;  //物品件数n，背包容量V，最大价值maxValue
int w[maxn], c[maxn];

//naive version O(2^n)
//对分支不作优化
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
    //岔道口
    DFS(index+1, sumW, sumC); //不选第index件物品
    DFS(index+1, sumW + w[index],sumC + c[index]); //选第index件物品
}

//Better version
void DFS2(int index, int sumW, int sumC)
{
    if(index == n)
    {
        return ;
    }
    //岔道口
    DFS(index+1, sumW, sumC); //不选第index件物品
    if(sumW + w[index] <=V)
    {
        if(sumC + c[index] > maxValue)
        {
            maxValue = sumC + c[index];
        }
        DFS2(index+1, sumW + w[index], sumC + c[index]); //选第index件物品
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
