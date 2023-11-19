#include<iostream>

using namespace std;
struct Array
{
    int len;
    int *arr;
}A, B;

int a[] = {1,2,3,7,9};
int b[] = {2,4,6,8};
void mergeData(int a[], int b[], int lenA, int lenB){
    int t[9];int s=0;
    int i=0,j=0;
    while(i<A.len&&j<B.len){
        if(a[i]>b[j])
            t[s++] = b[j++];
        else
            t[s++] = a[i++];
    }
    while(i<A.len) t[s++]=a[i++];
    while (j<B.len)t[s++]=b[i++];
    for(int i=0;i<A.len + B.len;i++)
        cout<<t[i]<<" ";
}
int binarySearch(int a[], int low, int high, int e){
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] == e)return mid;
        else if (a[mid]<e)
            low= mid+1;
        else
            high = mid-1;
    }return -1;
}
int main(){
    A.arr = a;A.len = sizeof(a)/sizeof(int);
    B.arr = a;B.len = sizeof(b)/sizeof(int);
    // mergeData(a, b, A.len, B.len);   
    cout<<binarySearch(a, 0, A.len-1, 2);
    return 0;
}