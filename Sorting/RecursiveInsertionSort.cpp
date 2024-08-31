#include <bits/stdc++.h>
using namespace std;

void  insertionSort(int arr[],int i,int n){
    if(i==n) return;
    int minIndex=i;
    for(int j=i;j<n;j++){
        if(arr[minIndex]>arr[j]){
            minIndex=j;
        }
    }
    if(minIndex!=i)
    swap(arr[i],arr[minIndex]);
    insertionSort(arr,i+1,n);

}