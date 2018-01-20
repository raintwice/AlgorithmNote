#include <iostream>
#include <cmath>
#include<cstdio>

using namespace std;

bool isPrime(int n) //判断是否素数 true表示是素数
{
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i = 2;i <= sqr;i++)
    {
        if(n%i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

const int maxn = 101;
int prime[101], pNum = 0; //素数记录数组
bool p[101] = {0};      //素数判断数组

void Find_Prime()  //O(nsqrt(n))
{
    for(int i = 1;i<101;i++)
    {
        if(isPrime(i) == true)
        {
            prime[pNum++] = i;
            p[i] = true;
        }
    }
}

bool p2[maxn] = {0}; //FALSE为素数

void Find_Prime2()
{
    for(int i=2; i<maxn;i++)
    {
         if(p2[i] == false)  //若是素数，则其倍数不是素数
         {
             prime[pNum++] = i;
             for(int j=i+i;j<maxn;j+=i)
             {
                 p2[j] = true;
             }
         }
    }
}

int main()
{
    Find_Prime2();
    for(int i=2;i<pNum;i++)
    {
        printf("%d ", prime[i]);
    }
    return 0;
}
