class Solution {
public:
    /*time complexity is O(N) and space is O(N)*/
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++) {
            if(s[i]=='('||s[i]=='{'||s[i]=='[') {
                st.push(s[i]);
            }
            else{
                if(st.empty()) {
                    return false;
                }
                if(s[i]==')') {
                    if(st.top()=='(') {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]=='}') {
                    if(st.top()=='{') {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]==']') {
                    if(st.top()=='[') {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};