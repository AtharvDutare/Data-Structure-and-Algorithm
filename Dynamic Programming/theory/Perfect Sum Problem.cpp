class Solution{
	public:
	int m=1e9+7;
	int solve(int arr[],int n,int index,int sum,vector<vector<int>>&dp) {
	    if(index>=n) {
	        return sum==0;
	    }
        if(dp[index][sum]!=-1) {
            return dp[index][sum];
        }
	    int include=0,exclude=0;
	    if(sum-arr[index]>=0) {
	        if(sum==0) {
    	        include++;
    	    }
	        include=solve(arr,n,index+1,sum-arr[index],dp);
	    }
	    exclude=solve(arr,n,index+1,sum,dp);
	    return dp[index][sum]=(include+exclude)%m;
	}
	int tab(int arr[],int n,int total) {
	    vector<vector<int>>dp(n+1,vector<int>(total+1,0));
	    dp[n][0]=1;
	    for(int index=n-1;index>-1;index--) {
	        for(int sum=0;sum<=total;sum++) {
	            int include=0,exclude=0;
        	    if(sum-arr[index]>=0) {
        	        if(sum==0) {
            	        include++;
            	    }
        	        include=dp[index+1][sum-arr[index]];
        	    }
        	    exclude=dp[index+1][sum];
        	    dp[index][sum]=(include+exclude)%m;
	        }
	    }
	    return dp[0][total];
	}
	int tabOpti(int arr[],int n,int total) {
	    vector<int> next(total+1,0);
	    vector<int> curr(total+1,0);
	    next[0]=1;
	    for(int index=n-1;index>-1;index--) {
	        for(int sum=0;sum<=total;sum++) {
	            int include=0,exclude=0;
        	    if(sum-arr[index]>=0) {
        	        if(sum==0) {
            	        include++;
            	    }
        	        include=next[sum-arr[index]];
        	    }
        	    exclude=next[sum];
        	    curr[sum]=(include+exclude)%m;
	        }
	        next=curr;
	    }
	    return next[total];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // int ans=solve(arr,n,0,sum,dp);
        int ans=tabOpti(arr,n,sum);
        return ans;
	}
};