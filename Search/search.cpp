#include<search.h>
int binarySearch(datatype A[], int left ,int right, datatype x)
{
    int mid;
    while(left <= right)
    {
        //mid = (left + right)/2;
        mid = left + (right - left)/2;
        if(x == A[mid])
        {
            return mid;
        }else if(x > A[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    return -1;
}

//求左闭界
int lower_bound(datatype A[], int left ,int right, datatype x)
{
    int mid;
    while(left < right) //若left == right 是他就是他
    {
        mid = left + (right - right)/2;
        if(A[mid]>=x)
        {
            left = mid;  //往左区间[left,mid]查找，不能写成left = mid - 1 ，因为假如此时刚好在左界，会跳过左界
        }
        else
        {
           right = mid + 1; //小于时，一定在当前mid 的右方
        }
    }
    return left;
}

//求右开界
int upper_bound(datatype A[], int left ,int right, datatype x)
{
    int mid;
    while(left < right)
    {
        mid = left + (right - left)/2;
        if(A[mid] > x)
        {
            right = mid;
        }else
        {
            left = mid + 1;
        }
    }
    return left;
}

