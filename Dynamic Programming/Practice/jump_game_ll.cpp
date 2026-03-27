// it is forward pull dp version of problem
// tc=O(n^2)
class Solution {
public:
    /* 
    INTUITION
    */

    int jump(vector<int>& arr) {
        int n=arr.size();
        if(n==1) {
            return 0;
        }
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<i;j++) {
                if(j+arr[j-1]>=i) {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};

// this is the forward push dp version of problem 
// tc =O(N^2)
class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        if(n==1) {
            return 0;
        }
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        dp[1]=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=min(n,i+arr[i-1]);j++) {
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        return dp[n];
    }
};
// this is backward pull dp version of perblem
// tc=O(n^2)
class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        if(n==1) {
            return 0;
        }
        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;i>0;i--) {
            for(int j=1;j<=min(n,i+arr[i-1]);j++) {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
        return dp[1];
    }
};
class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }
        
        // 1-indexed DP array: dp[1] is the start, dp[n] is the destination.
        vector<int> dp(n + 1, 1e9);
        
        // Base case: We are already at the destination, so it takes 0 jumps.
        dp[n] = 0; 
        
        // 'i' is our CURRENT position. 
        // We move backwards from the 2nd-to-last cell down to the 1st cell.
        for (int i = n - 1; i > 0; i--) {
            
            // Calculate the furthest absolute index we can reach from 'i'.
            // Because 'i' is 1-indexed, its jump power is at arr[i-1].
            int max_reach = min(n, i + arr[i - 1]);
            
            // 'j' is the FUTURE cell we are jumping to. 
            // We strictly start looking at the very next cell (i + 1).
            for (int j = i + 1; j <= max_reach; j++) {
                
                // We PULL the best answer from our future landing zones.
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        
        // Return the minimum jumps required starting from the 1st cell.
        return dp[1];
    }
};