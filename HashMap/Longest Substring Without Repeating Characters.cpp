class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans=0;
        int n=s.length();
        if(n<=1) {
            return n;
        }
        queue<char> q;
        //create the window
        int i=0;
        while(i<n) {
            if(st.find(s[i])==st.end()) {
                q.push(s[i]);
                st.insert(s[i]);
                i++;
            }
            else {
                break;
            }
        }
        ans=max(ans,(int)q.size());
        //moving the window 
        while(i<n&&q.size()>0) {
            char t=q.front();
            q.pop();
            st.erase(t);
            while(i<n&&st.find(s[i])==st.end()) {
                q.push(s[i]);
                st.insert(s[i]);
                i++;
            }
            ans=max(ans,(int)q.size());
        }
        //last window consume
        ans=max(ans,(int)q.size());
        return ans;

    }
};


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        HashSet<Character> hs=new HashSet<>();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n) {
            if(!hs.contains(s.charAt(j))) {
                hs.add(s.charAt(j));
                j++;
            }
            else {
                break;
            }
        }
        while(j<n) {
            ans=Math.max(ans,j-i);
            char t=s.charAt(i);
            i++;
            hs.remove(t);
            while(j<n&&!hs.contains(s.charAt(j))) {
                hs.add(s.charAt(j));
                j++;
            }
        }
        ans=Math.max(ans,j-i);
        return ans;
        
    }
}