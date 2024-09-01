//Approch 1
class Solution {
public:
    /*this code find ways and its combination in ques we have to not find combination*/
    int solve(vector<int>&arr,int target,vector<int> path) {
        int n=arr.size();
        if(target==0) {
            for(auto &x:path) {
                cout<<x<<" ";
            }cout<<endl;
            return 1;
        }
        if(target<0) {
            return 0;
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            path.push_back(arr[i]);
            ans+=solve(arr,target-arr[i],path);
            path.pop_back();
        }
        return ans;
    }
    /*time complexity is O(n*target) and space complexity O(n*target) and recursion stack is O(target)*/
    int dp[301][5001];
    int solve2(vector<int>&arr,int index,int target) {
        if(index>=arr.size()) {
            return target==0;
        }
        if(target==0) {
            return 1;
        }
        if(dp[index][target]!=-1) {
            return dp[index][target];
        }
        int take=0;
        int not_take=solve2(arr,index+1,target);
        if(target-arr[index]>=0) {
            //here by not change index we take all arr[i] coin at once
            take=solve2(arr,index,target-arr[index]);
        }
        return dp[index][target]=take+not_take;
    }

    int tab(vector<int>&arr,int amount) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        for(int index=n-1;index>-1;index--) {
            for(int target=0;target<=amount;target++) {
                int take=0;
                int not_take=dp[index+1][target];
                if(target-arr[index]>=0) {
                    //here by not change index we take all arr[i] coin at once
                    take=dp[index][target-arr[index]];
                }
                dp[index][target]=take+not_take;
            } 
        }
        return dp[0][amount];
    }

    int change(int amount, vector<int>& coins) {
        // memset(dp,-1,sizeof(dp));
        // int ans=solve2(coins,0,amount);
        int ans=tab(coins,amount);
        return ans;
    }
};