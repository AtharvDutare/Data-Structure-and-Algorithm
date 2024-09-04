#include<bits/stdc++.h>
vector<int> prevSmaller(vector<int> &arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        while(!st.empty()&&st.top()>=arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
    
}
