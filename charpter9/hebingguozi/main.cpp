#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

//С����
priority_queue<long long, vector<long long>, greater<long long> > q;

int main()
{
    int n;
    scanf("%d", &n);
    long long temp, x,y,ans = 0;
    for(int i = 0;i<n;i++)
    {
        scanf("%lld", &temp);
        q.push(temp);
    }
    while(q.size()>1) //ֻҪ������Ԫ��
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x+y);
        ans = ans + x + y;
    }
    printf("%lld\n", ans);
    return 0;
}
