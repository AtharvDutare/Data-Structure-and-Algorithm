class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            if(mp.find(answers[i])==mp.end()) {
                mp[answers[i]]=answers[i];
                ans+=answers[i]+1;
            }
            else {
                if(mp[answers[i]]==0) {
                    mp[answers[i]]=answers[i];
                    ans+=answers[i]+1;
                }
                else {
                    mp[answers[i]]--;
                }
            }
        }
        return ans;
    }
};