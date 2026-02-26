class Solution {
    long long ans=0;
    void conqure(vector<int>&arr,int s,int mid,int e) {
        int left=s;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid&&right<=e) {
            if(arr[left]>arr[right]) {
                temp.push_back(arr[right]);
                right++;
                //ans+=(mid-left+1);
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
    void countPairs(vector<int>&arr,int s,int mid,int e) {
        int left=s;
        int right=mid+1;
        for(int i=left;i<=mid;i++) {
            while(right<=e&&arr[i]>2LL*arr[right]) {
                right++;
            }
            ans+=right-(mid+1);
        }
    }

    void divide(vector<int>&arr,int s,int e) {
        if(s>=e) {
            return;
        }
        int mid=(e-s)/2+s;
        divide(arr,s,mid);
        divide(arr,mid+1,e);
        countPairs(arr,s,mid,e);
        conqure(arr,s,mid,e);
    }
public:
    int reversePairs(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return ans;
    }
};