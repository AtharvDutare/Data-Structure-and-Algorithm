#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int n,int low,int high){
    int selectEle=low       // can be high can be mid can be random(rand() function for random value)
    int pivot=arr[selectEle];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<high){
            i++;
        }
        while(arr[j]>pivot&&j>low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    //i index pointed to element that value is strictly greater than pivot or last index
    //j index pointed to element that value is less than and equal to pivot
    swap(arr[low],arr[j]);
    return j;
}


void quickSort(int arr[],int n,int low,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        quickSort(arr,n,low,pIndex-1);
        quickSort(arr,n,pIndex+1,high);
    }
}