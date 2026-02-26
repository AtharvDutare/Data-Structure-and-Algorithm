class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[i]>arr[j]) ans++;
            }
        }
        return ans;
    }
};

#include <bits/stdc++.h>
long long ans=0;

void conqure(vector<int>&arr,int s,int mid,int e) {
    int left=s;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid&&right<=e) {
        if(arr[left]>arr[right]) {
            temp.push_back(arr[right]);
            right++;
            ans+=(mid-left+1);
        }
        else {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=e) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=0;i<temp.size();i++) {
        arr[i+s]=temp[i];
    }
}


void divide(vector<int>&arr,int s,int e) {
    if(s>=e) {
        return;
    }
    int mid=(e-s)/2+s;
    divide(arr,s,mid);
    divide(arr,mid+1,e);
    conqure(arr,s,mid,e);
}

long long getInversions(long long *a, int n){
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) {
        arr[i]=a[i];
    }
    divide(arr,0,n-1);
    return ans;
}