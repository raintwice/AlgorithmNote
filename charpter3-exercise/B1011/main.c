
#define N 10


//int main()
//{
//    int cnt = 0;
//    int i = 0;
//    long long a[N]={0}, b[N]={0}, c[N]={0};
//    scanf("%d",&cnt);
//    for(;i <cnt;i++)
//    {
//        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
//    }
//    printf("\n");
//    for(i = 0;i < cnt;i++)
//    {
//        if((a[i]+b[i])>c[i])
//        {
//            printf("Case #%d: true\n", i+1);
//        }
//        else
//        {
//            printf("Case #%d: false\n", i+1);
//        }
//    }
//    return 0;
//}
#include <stdio.h>
int main()
{
    int T, tcase = 1;
    scanf("%d", &T);
    while(T--)
    {
        long long a, b, c;
        scanf("%lld%lld%lld",&a, &b,&c);
        if(a + b >c)
        {
            printf("Case #%d: true\n", tcase++);
        }else
        {
            printf("Case #%d: false\n", tcase++);
        }
    }
    return 0;
}
