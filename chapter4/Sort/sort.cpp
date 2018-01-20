//排序算法实现
#include<sort.h>
#include<algorithm>
using namespace std;

void SelectSort(datatype array[],int num)
{
    int i = 0;
    for(;i<num;i++)  //从0开始到结尾前一个
    {
        int k = i; //最小下标
        int j = i;
        for(;j<=num;j++) //从i开始到结尾, 选择最小的元素的下标
        {
            if(array[j]<array[k])
            {
                k = j;
            }
        }
        datatype temp = array[k];  //交换从i开始最小元素
        array[k] = array[i];
        array[i] = temp;
    }
}

const int maxn = 1000;

//归并函数，特定对于一个数组的两个区间
void merge(datatype A[], int L1, int R1, int L2, int R2)
{
    int i=L1, j=L2;
    datatype temp[maxn];
    int index = 0;
    while((i<=R1)&&(j<=R2))  //退出条件为任一个区间已空
    {
        if(A[i]<=A[j])
        {
            temp[index++] = A[i++];
        }else
        {
            temp[index++] = A[j++];
        }
    }
    while(i<=R1)  //区间未空
    {
        temp[index++] = A[i++];
    }
    while(j<=R2)  //区间未空
    {
        temp[index++] = A[j++];
    }
    for(i=0;i<index;i++)
    {
        A[L1 + i] = temp[i];
    }
}

//归并算法，递归
void MergeSort(datatype A[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        MergeSort(A, left, mid);
        MergeSort(A, mid+1, right);
        merge(A, left, mid, mid+1, right);
    }
}

//归并算法，
void MergeSort2(datatype A[], int n)
{
    for(int step = 2; step/2 <= n;step *=2) //两个两个，四个四个
    {
        for(int i=0;i<n;i+=step)
        {
            int mid = i + step/2 -1;
            if(mid + 1<=n)
            {
                merge(A, i, mid, mid+1, min(i+step - 1, n));
            }
        }
    }
}

//快速排序划分函数
int Partition(datatype A[], int left, int right)
{
    datatype temp = A[left];
    int i = left ,j = right;
    while(i < j)  //i == j时，就是这个位
    {
        while((i<j)&&(A[j]>temp))
        {
            j--;
        }
        A[i] = A[j];
        while((i<j)&&(A[i]<=temp))  //左右与temp比较必须要有一个判断等于，不然会将相等的数左右重复对换，死循环
        {
            i++;
        }
        A[j] = A[i];
    }
    A[i] = temp;
    return i;
}

void QuickSort(datatype A[], int left, int right)
{
    if(left <= right)
    {
        int pos = Partition(A, left, right); //pos位置已排好
        QuickSort(A,left,pos-1);            //递归左子区间，注意是pos -1 ,不然一直划分出pos，死循环
        QuickSort(A,pos+1,right);           //递归右子区间
    }
}

