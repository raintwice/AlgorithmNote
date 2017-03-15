/*
 * n皇后 递归算法
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;

/*
void generateP(int index)
{
    if(index == n+1)  //递归边界
    {
        bool flag = true;
        for(int i=1;i<=n;i++)       //判断是否在同一对角线
        {
            for(int j=i+1;j<=n;j++)
            {
                if(abs(i - j) == abs(P[i] - P[j]))
                {
                    flag = false;
                }
            }
        }
        if(flag ) count++;
        return ;
    }
    for(int x=1;x<=n;x++)      //递归从1开始
    {
        if(hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }

}
*/

void generateP(int index)
{
    if(index == n+1)
    {
        count++;
        return ;
    }
    for(int x=1;x<=n;x++)
    {
        if(hashTable[x] == false)
        {
            bool flag = true;
            for(int pre =1;pre< index;pre++)
            {
                if(abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false;     //回溯, 任一出现对角线，直接返回上层
                    break;
                }
            }
            if(flag)
            {
                P[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

int main()
{
    n = 8;
    generateP(1);
    printf("%d",count);
    return 0;
}
