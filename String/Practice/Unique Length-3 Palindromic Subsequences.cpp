//approach 1 O(26*2*(n^3)) time complexity
class Solution {
public:
    int found(string &s,string st) {
        char k1=st[0];
        char k2=st[1];
        for(int i=0;i<s.length();i++) {
            if(k1==s[i]) {
                for(int j=i+1;j<s.length();j++) {
                    if(k2==s[j]) {
                        for(int k=j+1;k<s.length();k++) {
                            if(s[k]==k1) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    int countPalindromicSubsequence(string s) {
        vector<string> st;
        char k1='a';
        char k2='a';
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                string t="";
                t.push_back((char)(k1+i));
                t.push_back((char)(k2+j));
                st.push_back(t);
            }
        }
        int ans=0;
        for(int i=0;i<st.size();i++) {
            if(found(s,st[i])) {
                ans++;
            }
        }
        return ans;
    }
};

//approach 2 O(26*n) time complexity
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> g(26,-1);
        vector<int> first(26,-1);
        int n=s.length();
        unordered_set<string> st;
        for(int i=0;i<n;i++) {
            if(g[s[i]-97]!=-1) {
                for(int j=0;j<26;j++) {
                    char o='a'+j;
                    string t="";
                    t.push_back(s[i]);
                    t.push_back(o);
                    if(st.find(t)!=st.end()) {
                        continue;
                    }
                    if(s[i]==o) {
                        if(first[o-97]<g[o-97]&&g[o-97]<i) {
                            st.insert(t);
                        }
                    }
                    else if(g[j]>g[s[i]-97]&&g[j]<i) {
                        st.insert(t);
                    }
                }
            }
            if(first[s[i]-97]==-1) {
                first[s[i]-97]=i;
            }
            g[s[i]-97]=i;
        }
        return st.size();
    }
};