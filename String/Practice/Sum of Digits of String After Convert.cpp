class Solution {
public:
/*time complexity is O(N*K) where n is length of string and space complexity is O(N)*/
    int getLucky(string s, int k) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++) {
            ans.append(to_string(s[i]-'a'+1));
        }
        cout<<ans<<endl;
        int an=0;
        while(k--) {
            an=0;
            for(auto &x:ans) {
                int t=x-'0';
                an+=t;
            }
            ans=to_string(an);
            
        }
        return an;
    }
};