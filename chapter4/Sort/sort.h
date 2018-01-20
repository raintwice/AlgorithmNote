#ifndef SORT_H
#define SORT_H

typedef int datatype;

//选择排序
void SelectSort(datatype array[],int num);
//归并
void merge(datatype A[], int L1, int R1, int L2, int R2);
//归并排序 递归
void MergeSort(datatype A[], int left, int right);
//归并排序 非递归
void MergeSort2(datatype A[], int n);
//快速排序
void QuickSort(datatype A[], int left, int right);
#endif // SORT_H
