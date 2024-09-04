class Solution {
public:
    /*got TLE this code is simply double for loop*/
    int m=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int k=n;
        long long ans=0;
        for(int i=k;i>=1;i--) {
            int l=0;
            int r=i-1;
            int minElement=INT_MAX;
            for(int w=l;w<=r;w++) {
                minElement=min(arr[w],minElement);
            }
            ans+=minElement;
            
            while(r+1<n) {
                if(arr[l]>minElement) {
                    minElement=min(minElement,arr[r+1]);
                    ans+=minElement;
                }
                else{
                    minElement=arr[r+1];
                    for(int w=l+1;w<=r+1;w++) {
                        minElement=min(arr[w],minElement);
                    }
                    ans=(minElement%m+ans%m)%m;
                }
                l++;
                r++;
                //cout<<ans<<endl;
            }

        }
        return ans;
        
    }
};
/*time complexity is O(3*n)==O(N)*/
class Solution {
public:
    vector<int> nextSmallerElement(vector<int>&arr) {
        stack<int> st;
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>-1;i--) {
            while(!st.empty()&&arr[st.top()]>=arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i]=n;
            }
            else
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerEqualElement(vector<int>&arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++) {
            while(!st.empty()&&arr[st.top()]>arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i]=-1;
            }
            else
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int m=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmaller=nextSmallerElement(arr);
        vector<int> prevSmallerEqual=prevSmallerEqualElement(arr);  
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int left=i-prevSmallerEqual[i];
            int right=nextSmaller[i]-i;
            ans=(ans%m+(left*right*1LL*arr[i])%m)%m;
        }
        return ans;
    }
};