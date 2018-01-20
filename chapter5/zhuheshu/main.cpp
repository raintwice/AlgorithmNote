#include <iostream>
#include<cstdio>

using namespace std;

//求n!有多少个质因子p
int cal(int n, int p)  //O(nlogn)
{
    int ans = 0;
    for(int i=2;i<=n;i++)
    {
        int temp = i;
        while(temp%p == 0)
        {
            ans++;
            temp/=p;
        }
    }
    return ans;
}

int cal2(int n, int p)  //n/p + n/p2 + n/p3 +....
{
    int ans = 0;
    while(n)
    {
        ans += n/p;
    }
    return ans;
}

int cal_Re(int n, int p)
{
    if(n < p)
        return 0;
    return n/p + cal_Re(n/p,p);
}

int main()
{
    printf("%d", cal_Re(10, 2));
    return 0;
}
