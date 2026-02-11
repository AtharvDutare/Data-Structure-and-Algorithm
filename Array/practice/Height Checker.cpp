// Brute Force Approach
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.begin(),heights.end());
        sort(temp.begin(),temp.end());
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(heights[i]!=temp[i]){
                ans++;
            }
        }
        return ans;
    }
};

// Better Approach
// time complexity: O(n)
// space complexity: O(n)

class Solution {
public:
    int heightChecker(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        for(int i=1;i<=100;i++) {
            if(mp[i]>0) {
                while(mp[i]--)
                ans.push_back(i);
            }
        }
        int t=0;
        for(int i=0;i<n;i++) {
            if(arr[i]!=ans[i]) {
                t++;
            }
        }
        return t;
    }
};

// Optimal Approach
// time complexity: O(n)
// space complexity: O(n)

class Solution {
public:
    int heightChecker(vector<int>& arr) {
        int n=arr.size();
        int pos=0;
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        for(int i=1;i<=100;i++) {
            if(mp[i]>0) {
                while(mp[i]--) {
                    if(arr[pos++]!=i) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};