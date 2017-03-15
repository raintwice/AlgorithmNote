#include <iostream>
#include <algorithm>

using namespace std;

struct mooncake
{
    double store;
    double sell;
    double price;
}Cake[1001];

bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n;
    double need;
    scanf("%d%lf",&n,&need);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&Cake[i].store);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&Cake[i].sell);
        Cake[i].price = Cake[i].sell/Cake[i].store;
    }
    sort(Cake, Cake + n, cmp);
    double ans = 0;   //收益
    for(int i = 0;i<n;i++)
    {
        if(need >= Cake[i].store)
        {
            need -= Cake[i].store;
            ans += Cake[i].sell;
        }
        else
        {
            ans += Cake[i].price * need;
            break;
        }
    }
    printf("%.2f",ans);
    return 0;
}
