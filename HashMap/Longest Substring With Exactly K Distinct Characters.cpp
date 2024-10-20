public class Main{
    private static int solve(String s) {
        int ans =-1;
        int i=-1;
        int j=-1;
        HashMap<Character,Integer> mp=new HashMap<>();
        int n=s.length();
        while(true) {
            boolean f1=false;
            boolean f2=false;
            while(i<n-1) {
                f1=true;
                i++;
                char ch=s.charAt(i);
                mp.put(ch,mp.getOrDefault(ch,0)+1);
                if(mp.size()<k) {
                    continue;
                }
                else if (mp.size()==k) {
                    int newAns=i-j;
                    if(newAns>ans) {
                        ans=newAns;
                    }
                }
                else {
                    break;
                }
            }
            if(i==n && mp.size()<k) {
                return ans;
            }
            while(j<i) {
                f2=true;
                j++;
                char ch=s.charAt(j);
                if(mp.get(ch)==1) {
                    mp.remove(ch);
                } 
                else {
                    mp.put(ch,mp.get(ch)-1);
                }
                if(mp.size()>k) {
                    continue;
                }
                if(mp.size()==k) {
                    int newAns=i-j;
                    if(newAns>ans) {
                        ans=newAns;
                    }
                    break;
                }
            }
            if(f1&&f2) {
                break;
            }
        }
        return ans;
    }
}

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> mp;
        int cnt=0;
        int i=0, j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                cnt++;
            }
            //cond
            if(cnt<k){
                j++;
                continue;
            }
            else if(cnt==k){
                ans=max(ans, j-i+1);
                j++;
                continue;
            }
            else if(cnt>k){
                while(cnt>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) cnt--;
                    i++;
                }
                if(cnt==k){
                    ans=max(ans, j-i+1);
                    j++;
                }
            }
        }
        if(ans==0) return -1;
        return ans;
    }

    class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int ans=-1;
        int n=s.length();
        while(j<n) {
             if(mp.size()<=k) {
                if(mp.size()==k&&mp.find(s[j])==mp.end()) {
                    break;
                }
                 mp[s[j]]++;
                 j++;
             }
             else {
                 break;
             }
        }
        if(j==n and mp.size()<k) {
            return ans;
        }
        ans=max(ans,j-i);
        while(j<n) {
            mp[s[i]]--;
            if(mp[s[i]]==0) {
                mp.erase(s[i]);
            }
            i++;
            while(j<n&&(mp.size()<=k)) {
                if(mp.size()==k&&mp.find(s[j])==mp.end()) {
                    break;
                }
                mp[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
        }
        ans=max(ans,j-i);
        return ans;
    }
};
