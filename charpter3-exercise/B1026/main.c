#include <stdio.h>
#include <time.h>
int main()
{
    int c1 = 0,c2 = 0;
    scanf("%d%d",&c1,&c2);
    int sectotal = 0;

    if((c2 - c1)%100 >= 50)
    {
        sectotal = (c2 -c1)/100 + 1 ;
    }
    else
    {
        sectotal = (c2 -c1)/100 ;
    }
    int h = sectotal/3600;
    int min = (sectotal%3600)/60;
    int sec = sectotal%60;
    printf("%02d:%02d:%02d",h,min,sec);
    return 0;
}

//int main()
//{
//    double val = 0;
//    scanf("%lf",&val);
//    int v = val + 0.5;
//    printf("%d",v);
//}
