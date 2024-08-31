#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    bool didSwap=false;
    for(int i=0;i<n-1;i++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            didSwap=true;
        }
    }
    if(didSwap==false){
        return;
    }
    bubbleSort(arr,n-1);
}
