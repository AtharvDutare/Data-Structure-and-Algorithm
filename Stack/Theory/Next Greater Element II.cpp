class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int> st,temp;
        //st.push(-1);
        int mini=INT_MIN;
        for(int &x:arr) {
            if(x>mini) {
                temp.push(x);
                mini=x;
                //cout<<x<<endl;
            }
        }

        while(!temp.empty()) {
            st.push((int)temp.top());
            temp.pop();
        }
        int n=arr.size();
        
        vector<int> ans(n,0);
        for(int i=n-1;i>-1;i--) {
            while(!st.empty()&&st.top()<=arr[i]) {
                cout<<i<<" "<<st.top()<<" "<<arr[i]<<endl;
                st.pop();
            }
            if(st.empty()) {
                ans[i]=-1;
            }
            else
            ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};