//Brute Force Approach TLE
// implementation of the question
// Time Complexity: O(n*m) 
// Space Complexity: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(auto &x:nums1) {
            for(auto &y:nums2) {
                ans^=(x^y);
            }
        }
        return ans;
    }
};
//my approach
// Time Complexity: O(n+m)
// Space Complexity: O(32)===O(1)
class Solution {
public:
    vector<int> convertToVector(int x) {
        vector<int> ans(32,0);
        int index=0;
        while(x>0) {
            if(x&1) {
                ans[index]=1;
            }
            index++;
            x=x>>1;
        }
        return ans;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int xor2=nums2[0];
        for(int i=1;i<m;i++) {
            xor2^=nums2[i];
        }
        vector<int> t;
        if(n%2==1) {
            t=convertToVector(xor2);
        }
        else {
            t=vector<int>(32,0);
        }
        for(int i=0;i<n;i++) {
            int x=nums1[i];
            vector<int>temp=convertToVector(x);
            for(int j=0;j<32;j++) {
                int bit=temp[j];
                if(bit) {
                    if(m%2==1) {
                        bit=1;
                    }
                    else {
                        bit=0;
                    }
                }
                else {
                    bit=0;
                }
                t[j]^=bit;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++) {
            if(t[i]) {
                ans+=(1<<i);
            }
        }
        return ans;
    }
};