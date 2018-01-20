#include <iostream>

using namespace std;

long long C(long long n, long long m)
{
    if(m ==0||m == n)
    {
        return 1;
    }
    return C(n-1,m ) + C(n-1, m-1);
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
