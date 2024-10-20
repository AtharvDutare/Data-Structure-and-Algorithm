class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto &x:arr) {
            mp[x]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++) {
            if(mp.find(arr[i])!=mp.end()) {
                int des1=arr[i]*2;
                int f1=0;
                if(arr[i]%2==0)
                f1=1;
                int des2=arr[i]/2;
                if(mp.find(des1)!=mp.end()) {
                    mp[des1]--;
                    if(mp[des1]==0) {
                        mp.erase(des1);
                    }
                }
                else if(f1&&mp.find(des2)!=mp.end()) {
                    mp[des2]--;
                        if(mp[des2]==0) {
                            mp.erase(des2);
                        }
                }
                else {
                    return 0;
                }
            }
            
        }
        return 1;
    }
    
};