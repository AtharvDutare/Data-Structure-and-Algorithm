class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int ans=0;
	    unordered_map<int,int> mp;
	    int currSum=0;
	    mp[currSum]=-1;
	    for(int i=0;i<n;i++) {
	        currSum+=arr[i];
	        int rem=(currSum%k+k)%k;
	        if(mp.find(rem)!=mp.end()) {
	            ans=max(ans,i-mp[rem]);
	        }
	        if(mp.find(rem)==mp.end()) {
	            mp[rem]=i;
	        }
	    }
	    return ans;
	}
};