class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans;
        unordered_map<int,int> mp;
        long long sum=0;
        int duplicateEle=NULL;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            mp[arr[i]]++;
            if(mp[arr[i]]>1) {
                duplicateEle=arr[i];
            }
            
        }
        return {duplicateEle,1LL*n*(n+1)/2-(sum-duplicateEle)};
    }
};

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long aSum=1LL*(n*(n+1))/2;
        long long aSqSum=1LL*n*(n+1)*(2*n+1)/6;
        
         long long obSum=0;
        long long obSqSum=0;
        for(auto &x:arr) {
            obSum+=1LL*x;
            obSqSum+=(1LL*x*x);
        }
        long long val1=aSqSum-obSqSum;
        long long val2=aSum-obSum;
        val1=val1/val2;
        long long ans1=(val1-val2)/2;
        long long ans2=(val1+val2)/2;
        return {ans1,ans2};
    }
};