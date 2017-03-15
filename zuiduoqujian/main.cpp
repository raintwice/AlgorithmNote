#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
const int maxn = 110;

struct Interval
{
    int x,y; //开区间左右
}I[maxn];

bool cmp(Interval a, Interval b)
{
    if(a.x != b.x)   //先选择左端点大的
    {
        a.x > b.x;
    }
    else
    {
        return a.y < b.y; //左端点相同，选小的右端点
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d", &I[i].x,&I[i].y);
    }
    sort(I,I+n,cmp);

    //选左端点最大的，取次大的，比较次大的右端是否在最大的范围内，不在则选中，更新最大，次大
    //在则继续下一个比较
    int cnt = 1,lastX = I[0].x;
    for(int i = 1;i < n;i++)
    {
        if(I[i].y<= lastX) //不在则选中
        {
            cnt ++;
            lastX = I[i].x;
        }
    }
    printf("%d",cnt);
    return 0;
}
