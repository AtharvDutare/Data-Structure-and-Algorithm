class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n=deck.size();
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            mp[deck[i]]++;
            ans=mp[deck[i]];
            
        }
        for(auto &x:mp) {
            ans=__gcd(ans,x.second);
        }
        if(ans<=1) {
            return false;
        }
        // for(auto &x:mp) {
        //     if(x.second%ans!=0) {
        //         return false;
        //     }
        // }
        return true;

    }
};