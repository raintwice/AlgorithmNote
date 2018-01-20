//最大子数组差值
#include <iostream>
#include<algorithm>
#include<ctime>

using namespace std;

const int maxn = 100010;
int A[maxn],n;
int randPartition(int A[], int left, int right)   //随机划分算法
{
    int p = round(1.0*rand()/RAND_MAX*(right - left))+ left;  //随机取
 //   printf("p = %d\n", p);
    swap(A[left], A[p]);
    int temp = A[left];
    while(left < right)
    {
        while(left<right&&(A[right]>temp)) right--;
        A[left] = A[right];
        while(left<right&&(A[left]<=temp)) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void randSelect(int A[], int left, int right, int K) //寻找区间第K大的元素,并将数组分成两组
{
    if(left == right) return;
    int p = randPartition(A, left, right);
    int M = p - left + 1;
    if(M == K) return ;
    if(K < M)
    {
        randSelect(A, left, p - 1, K);
    }
    else
    {
        randSelect(A, p + 1, right, K - M);
    }

}

int main()
{
    srand((unsigned)time(NULL));
    int sum = 0, sum1 = 0;
    scanf("%d", &n);
    for(int i = 0;i<n;i++) //累计全部元素
    {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    randSelect(A, 0, n-1, n/2);
    for(int i=0;i<n/2;i++)
    {
        sum1 += A[i];
    }
    printf("%d\n",(sum - sum1)- sum1);
    return 0;
}
