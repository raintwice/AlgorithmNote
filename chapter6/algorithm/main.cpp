#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int x=1, y=2;
    swap(x,y);
    printf("%d %d\n", x, y);

    int a[10] = {10,11,12,13,14,15};
    reverse(a, a+4);  //翻转
    for(int i =0;i<6;i++)
    {
        printf("%d ", a[i]);
    }

    char b[10] = "abc";
    do{
        printf("%c%c%c\n", b[0],b[1],b[2]);
    }while(next_permutation(b,b+3));
    return 0;
}
