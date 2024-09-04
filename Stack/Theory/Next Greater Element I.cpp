class Solution {
public:
    vector<int> nextGreater(vector<int>&arr,unordered_map<int,int>&mp) {
        stack<int> st;
        vector<int> ans;
        st.push(-1);
        int n = arr.size();
        for(int i=n-1;i>-1;i--) {
            while(st.top()!=-1&&st.top()<arr[i]) {
                st.pop();
            }
            ans.push_back(st.top());
            mp[arr[i]]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        nextGreater(nums2,mp);
        vector<int> ans;
        for(int &x:nums1) {
            ans.push_back(mp[x]);
        }
        return ans;

    }
};