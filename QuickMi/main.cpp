#include <iostream>

typedef long long LL;
using namespace std;

LL binaryPow(LL a, LL b, LL m)
{
    if(b == 0)
    {
        return 1;
    }
    if(b%2 == 1)
    {
        return a*binaryPow(a, b-1, m);
    }
    else
    {
        LL mu1 = binaryPow(a, b/2, m);
        return mu1*mu1%m;
    }
}

LL bianryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    while(b > 0)  //将b展开成二进制 如9展开成1001
    {
        if(b&1)
        {
            ans = ans*a%m;
        }
        a = a*a%m;
        b>>=1;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
