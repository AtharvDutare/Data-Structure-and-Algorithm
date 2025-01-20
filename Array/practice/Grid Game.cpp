// my solution
// test case Failed in 6/109

class Solution {
public:
    int maxIdx(vector<long long> &pre,vector<long long> &suff) {
        int n=pre.size();
        int maxIndex=-1;
        int maxValue=-1;
        for(int i=0;i<n;i++) {
            if(pre[i]+suff[i]>maxValue) {
                maxValue=pre[i]+suff[i];
                maxIndex=i;
            }
        } 
        return maxIndex;
    }
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> prefix(n,0),suffix(n,0);
        int pre=0;
        int suf=0;
        for(int i=0;i<n;i++) {
            pre+=grid[0][i];
            prefix[i]=pre;
        }
        for(int i=n-1;i>-1;i--) {
            suf+=grid[1][i];
            suffix[i]=suf;
        }
        for(auto &x:prefix) {
            cout<<x<<" ";
        }cout<<endl;
        for(auto &y:suffix) {
            cout<<y<<" ";
        }cout<<endl;
        int index=maxIdx(prefix,suffix);
        cout<<index<<endl;
        for(int i=0;i<=index;i++) {
            grid[0][i]=0;
        }
        for(int i=index;i<n;i++) {
            grid[1][i]=0;
        }
        pre=0;
        suf=0;
        for(int i=0;i<n;i++) {
            pre+=grid[0][i];
            prefix[i]=pre;
        }
        for(int i=n-1;i>-1;i--) {
            suf+=grid[1][i];
            suffix[i]=suf;
        }
        index=maxIdx(prefix,suffix);
        cout<<index<<endl;
        long long ans=0;
        for(int i=0;i<=index;i++) {
            ans+=grid[0][i];
        }
        for(int i=index;i<n;i++) {
            ans+=grid[1][i];
        }
        return ans;
    }
};