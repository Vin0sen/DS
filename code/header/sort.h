#include <stdio.h>
#include <iostream>
using namespace std;
void arrPrint(int*, int);
void ShellSort(int*, int);
void BubbleSort(int A[], int n);
void QuickSort(int*, int, int);
void MergeSort(int*, int low, int high);
void SimpleSelectSort(int *, int);
void InseratSort(int A[], int n){
    // int tmp=0, index=0;
    // for (int i = 1; i < n; i++){
    //     tmp = A[i];
    //     index = i;
    //     for (int j = i-1; j >= 0; j--){
    //         if(tmp < A[j])
    //             swap(A[index--], A[j]);
    //     }
    // }
    int i, j ,tmp;
    for (i = 1; i < n; i++){
        if(A[i]<A[i-1]){
            tmp = A[i];
            for(j=i-1;j>=0&&tmp<A[j];j--)
                A[j+1] = A[j];
            A[j+1] = tmp;
            arrPrint(A, n);
        }
    }
    
}
// 折半插入排序
void InsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++){  // 依次将A[2]~A[n]插入前面的已排序序列
        A[0] = A[i];  // 将A[i]暂存到A[0]
        low = 1;high = i - 1; // 设置折半查找的范围
        while (low<=high){ // 折半查找(默认递增有序)
            mid = (low + high) / 2; // 取中间点
            if (A[mid] > A[0]) high = mid - 1; // 查找左半子表
            else low = mid + 1; // 查找右半子表
        }
        for (j = i - 1; j >= high + 1; --j)
            A[j + 1] = A[j]; // 统一后移元素，空出插入位置
        A[high + 1] = A[0];  // 插入操作
    }
    arrPrint(A,n);
}

// int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
int n =9;// sizeof(arr)/sizeof(int);
int *B = (int *)malloc(n*sizeof(int)); // 辅助数组B
int main(){
    int arr[] = {50,40,95,20,15,70,60,45,80};
    int n=9;
    arrPrint(arr, n);
    // InsertSort(arr, n);
    // ShellSort(arr, n);
    BubbleSort(arr, n);
    // QuickSort(arr, 0, n-1);
    // MergeSort(arr, 0, n-1);
    // SimpleSelectSort(arr, n);
    return 0;
}
// 希尔排序
void ShellSort(int arr[], int len){
    int gap, i, j;
    int temp;
    for (gap = len/2; gap > 0; gap /= 2){
        for (i = gap; i < len; i++){
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
        arrPrint(arr, len);
    }
    
}
//冒泡排序
void BubbleSort(int A[], int n){
    bool flag;int exchange = 0;
    for(int i=0;i<n-1;i++){
		flag=false;exchange=0;
        for (int j = 1; j<n-i; j++){
            if(A[j-1]>A[j]){
                swap(A[j-1], A[j]);
                flag = true;exchange++;
            }
        }arrPrint(A, n);cout<<"交换次数:"<<exchange<<endl;
        if (flag == false)break;  // 如果一趟排序没有发生交换, 说明已有序, 可以提前结束
    }
}
// void BubbleSort(int A[], int n){
//     bool flag; int exchange = 0;
//     for(int i =0;i<n-1;i++){
//         flag=false;
//         exchange = 0;
//         for (int j = n-1; j >i; j--){
//             if(A[j-1]>A[j]){
//                 swap(A[j-1], A[j]);
//                 cout<<A[j-1]<<" "<<A[j]<<endl;
//                 flag = true;
//                 exchange++;
//             }     
//         }
//         arrPrint(A, n);cout<<"交换次数:"<<exchange<<endl;
//         if (flag == false)break;  // 如果一趟排序没有发生交换, 说明已有序, 可以提前结束
//     }
    
// }
// 快速排序
// //严蔚敏《数据结构》标准分割函数
/**
 * 6 1 2 7 9 3 4 5 10 8
 * 5 1 2   9 3 4 7 10 8                    
*/
int Paritition1(int A[], int low, int high){
    int pivot = A[low]; // 首元素为基准，形成坑位
    while (low < high){
        while (low < high && A[high] >= pivot) --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
// // 快排母函数
void QuickSort(int* A, int low, int high){
    if (low < high){
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
        arrPrint(A, 8); // 函数内部无法求出数组的长度, 这是指针，可以额外传参
    }
}
// 二路归并排序
void Merge(int A[],int low, int mid, int high){
    int i,j,k;
    for (k = low; k<=high; k++) B[k]=A[k];
    for(i=low,j=mid+1,k=i; i<=mid && j<=high;k++){
        if (B[i]<=B[j]){
            A[k]=B[i++];
        }else{
            A[k]=B[j++];
        }
        while(i<=mid) A[k++]=B[i++];
        while(j<=mid) A[k++]=B[j++];
    }
}
void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
    arrPrint(A, 8);
}
// 简单选择排序
void SimpleSelectSort(int A[], int n){
    int min_index;
    for (int i = 0; i<n-1; i++){
        min_index = i;
        for (int j = i+1; j<n; j++){
            if(A[j]<A[min_index])
                min_index = j;
        }
        if(min_index != i)swap(A[i], A[min_index]);
    }
    arrPrint(A,n);
}
void arrPrint(int A[], int n){
    for(int i = 0; i<n; i++)
        printf("%d ", A[i]); 
    printf("\n");
}