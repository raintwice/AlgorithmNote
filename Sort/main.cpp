#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sort.h>
#include <algorithm>
using namespace std;

#define SORTNUM 123
datatype array[SORTNUM];

void printArray(datatype arr[], int num);
bool check(datatype arr[], int num);

bool cmp(datatype a, datatype b)
{
    return a<b;
}

int main()
{
    int i = 0;
    srand(time(NULL));
    for(;i<SORTNUM;i++)   //待排数组赋值
    {
        array[i] = rand()%100;
    }
    printf("Before sorted!\n");
    printArray(array,SORTNUM);
    cout<<endl<<endl;


 //   SelectSort(array,SORTNUM);        //选择排序
//    sort(array, &array[SORTNUM]);     //STL sort
    //mergeSort(array,0,SORTNUM);
    mergeSort2(array,SORTNUM);

    bool res = check(array,SORTNUM);
    printf("After sorted!\n");
    printArray(array,SORTNUM);
    if(res)
    {
        printf("Correct!\n");
    }else
    {
        printf("Wrong!\n");
    }


    return 0;
}

void printArray(datatype arr[],int num)
{
    int i = 0;
    for(;i<num;i++)
    {
        printf("%6d",arr[i]);
        if( i%10 == 9)
        {
            printf("\n");
        }
    }
    putchar('\n');
}
bool check(datatype arr[], int num)
{
    int i = 1;
    for(;i<num;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}
