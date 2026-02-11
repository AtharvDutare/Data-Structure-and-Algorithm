//Brute force solution
//Time complexity: O(n)
//Space complexity: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++) {
            st.insert(nums[i]);
        }
        int i=0;
        for(auto &x:st) {
            nums[i++]=x;
        }
        return st.size();
    }
};

//Optimal solution
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=nums[0];
        int w=1;
        int ans=1;
        for(int i=1;i<n;i++) {
            if(k==nums[i]) {
                nums[i]=-101;
            }
            else {
                nums[w++]=nums[i];
                k=nums[i];
                ans++;
            }
        }
        return ans;
    }
};