class Solution {
private:
    unordered_map<int,int>mp;
    int top;
public:
    Solution(int n, vector<int>& blacklist) {
        int k=blacklist.size();
        top=n-k;
        unordered_set<int> st;
        for(int i=0;i<k;i++) {
            st.insert(blacklist[i]);
        }
        n--;
        for(int i=0;i<k;i++) {
            if(blacklist[i]<top) {
                while(st.find(n)!=st.end()) {
                    n--;
                }
                mp[blacklist[i]]=n;
                n--;
            }
        }
    }
    
    int pick() {
        int r=rand()%top;
        if(mp.find(r)!=mp.end()) {
            return mp[r];
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */