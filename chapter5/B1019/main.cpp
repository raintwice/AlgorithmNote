//最大公约数
#include <iostream>
#include<cstdio>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int main(int argc, char *argv[])
{
    int m,n;
    while(scanf("%d%d",&m,&n))
    {
        printf("%d\n",gcd(m,n));
    }
    return 0;
}
