#include <iostream>
#include <cstdio>
using namespace std;

struct Fraction
{
    int up, down;  //分子 分母
};

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

Fraction reduction(Fraction result) //化简
{
    if(result.down < 0)
    {
        result.down *= -1;
        result.up *= -1;
    }
    if(result.up == 0)
    {
        result.down = 1;
    }
    else
    {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /=d;
        result.down /=d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2) //加数
{
    Fraction result;
    result.up = f1.up*f2.down + f1.down*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2) //减法
{
    Fraction result;
    result.up = f1.up*f2.down - f1.down*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2)
{
    if(f1.up == 0)
    {
        printf("Error!\n");
    }
    Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
}

void showResult(Fraction r)
{
    r = reduction(r);
    if(r.down == 1)
    {
        printf("%lld", r.up);
    }
    else if(abs(r.up) > r.down) // 带分数
    {
        printf("%d%d/%d", r.up/r.down, abs(r.up)%r.down, r.down);
    }else
    {
        printf("%d%d", r.up, r.down);
    }
}



int main()
{


    return 0;
}
