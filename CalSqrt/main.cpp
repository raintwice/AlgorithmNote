#include <iostream>


using namespace std;

const double eps = 1e-5;

double f(double x)
{
    return x*x;
}

double calSqrt2()
{
    double left = 1,right = 2, mid;
    while(right - left> eps)
    {
        mid = (right + left)/2;
        if(f(mid)>2)
        {
            right = mid;
        }else
        {
            left = mid;
        }
    }
    return mid;
}

double calSqrt(double L, double R)
{
    double left = L,right = R, mid;
    while(right - left> eps)
    {
        mid = (right + left)/2;
        if(f(mid)>2)
        {
            right = mid;
        }else
        {
            left = mid;
        }
    }
    return mid;
}

int main()
{
    printf("%f",calSqrt(1,2));
    return 0;
}
