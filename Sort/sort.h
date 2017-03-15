#ifndef SORT_H
#define SORT_H

typedef int datatype;

//选择排序
void SelectSort(datatype array[],int num);
void merge(datatype A[], int L1, int R1, int L2, int R2);
void mergeSort(datatype A[], int left, int right);
void mergeSort2(datatype A[], int n);
#endif // SORT_H
