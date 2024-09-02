class Solution {
public:
    /*this is the optimal solution their is brute force also which give TLE
        time complexity is O(N+log(N))==O(N)
     */
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long> prefixSum(n,0);
        long long t=0;
        for(int i=0;i<n;i++) {
            t+=chalk[i];
            prefixSum[i]=t;
        }
        int w=k%t;
        int index=upper_bound(prefixSum.begin(),prefixSum.end(),w)-prefixSum.begin();
        return index;

    }
};