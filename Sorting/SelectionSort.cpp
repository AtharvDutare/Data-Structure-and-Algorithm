#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i;j<n;j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
        }
    }
}