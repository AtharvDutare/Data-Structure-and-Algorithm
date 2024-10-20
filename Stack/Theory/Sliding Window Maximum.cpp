class Solution {
public:
//got TLE
    int m=1e9+7;
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
            vector<int> ans;
            int n=arr.size();
            int l=0;
            int r=k-1;
            int maxElement=INT_MIN;
            for(int w=l;w<=r;w++) {
                maxElement=max(arr[w],maxElement);
            }
            ans.push_back(maxElement);
            
            while(r+1<n) {
                if(arr[l]>maxElement) {
                    maxElement=max(maxElement,arr[r+1]);
                    ans.push_back(maxElement);
                }
                else{
                    maxElement=arr[r+1];
                    for(int w=l+1;w<=r+1;w++) {
                        maxElement=max(arr[w],maxElement);
                    }
                    ans.push_back(maxElement);
                }
                l++;
                r++;
                //cout<<ans<<endl;
            }
            return ans;
    }
};
///
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        //first window of K size
        for(int i=0;i<k;i++) {
            //we create a decreasing monotocity 
            while(!dq.empty() && nums[i]>=nums[dq.back()]) {
                dq.pop_back();
            }
            //inserting index,so that we can checkout of window element 
            dq.push_back(i);
        }

        //store answer of first window
        ans.push_back(nums[dq.front()]);
        //remaining window ko process
        for(int i=k;i<nums.size();i++) {
            //out of window element ko remove krdia
            if(!dq.empty() && i-dq.front()>=k) {
                dq.pop_front();
            }
            //adding the new element 
            while(!dq.empty()&&nums[i]>=nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            //current window ka answer store krna
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};