#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int ele1=NULL;
        int count1=0;
        int ele2=NULL;
        int count2=0;
        for(int i=0;i<n;i++) {
            if(arr[i]==ele1) {
                count1++;
            }
            else if(arr[i]==ele2) {
                count2++;
            }
            else if(count1==0) {
                ele1=arr[i];
                count1++;
            }
            else if(count2==0) {
                ele2=arr[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        vector<int>ans;
        int k1,k2=0;
        for(int i=0;i<n;i++) {
            if(arr[i]==ele1) {
                k1++;
            }
            else if(arr[i]==ele2) {
                k2++;
            }
        }
        if(k1>floor(n/3)) {
            ans.push_back(ele1);
        }
        if(k2>floor(n/3)) {
            ans.push_back(ele2);
        }
        return ans;
    }
};