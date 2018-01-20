#include <iostream>

using namespace std;
const int maxn = 1000001;

int prime[maxn], primeNum = 0;
int primeJudge[maxn] = {0}; //false表示素数，0,1不处理
void Find_Prime(int n)  //n表示第个素数
{
    for(int i=2;i<maxn;i++)
    {
        if(primeJudge[i] == false)
        {
            prime[primeNum++] = i;
            if(primeNum >= n) break;
            for(int j=i+i;j<maxn;j+=i)
            {
                primeJudge[j] = true; //不是素数
            }
        }

    }
}

int main(int argc, char *argv[])
{
    int a, b;
    int cnt = 0;
    scanf("%d%d",&a, &b);
    Find_Prime(b);
    for(int i = a;i<=b;i++)
    {
        printf("%d",prime[i-1]);
        cnt++;
        if(cnt%10 != 0&&i<b)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
