#include <bits/stdc++.h> 
int maxLength(int n, vector<int> &arr){
    int ans=0;
    for(int i=0;i<n;i++) {
        int maxi=arr[i];
        int mini=arr[i];
        for(int j=i;j<n;j++) {
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
            if(maxi-mini==j-i) {
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;
}