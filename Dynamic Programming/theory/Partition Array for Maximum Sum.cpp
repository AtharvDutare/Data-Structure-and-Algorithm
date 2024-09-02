class Solution {
public:
    int dp[501];
    int solve(vector<int> &arr,int i,int k){
         if(i>=arr.size()){ 
            return 0;
         }
         if(dp[i]!=-1) return dp[i];
         int ans=0;
         int currMax=INT_MIN;
         for(int j=i;j<arr.size()&&(j-i+1)<=k;j++){
             currMax=max(currMax,arr[j]);
             ans=max(ans,(j-i+1)*currMax+solve(arr,j+1,k));
         }
         dp[i]=ans;
         return dp[i];
    }

    int tab(vector<int>&arr,int k ) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>-1;i--) {
            int ans=0;
            int currMax=INT_MIN;
            for(int j=i;j<arr.size()&&(j-i+1)<=k;j++){
                currMax=max(currMax,arr[j]);
                ans=max(ans,(j-i+1)*currMax+dp[j+1]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }

    int solveTab(vector<int> &arr,int k){
        int n=arr.size();
        vector<int> ans(n+1,0);
        for(int size=1;size<=n;size++){
            int currMax=INT_MIN;
            for(int j=1;j<=k&&(size-j)>=0;j++){
                currMax=max(currMax,arr[size-j]);
                dp[size]=max(dp[size],(j*currMax)+dp[size-j]);
            }
        }
        return dp[n];
    }


    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //memset(dp,-1,sizeof(dp));
        //int ans=solve(arr,0,k);
        int ans=tab(arr,k);
        return ans;
    }
};