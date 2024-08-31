
/* time complexicity is O(n*log(n))*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;
        int ans=0;
        int m=g.size();
        int n=s.size();
        while(i<m&&j<n){
            if(g[i]<=s[j]){
                i++;
                j++;
                ans++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }  
        return ans;      

    }
};