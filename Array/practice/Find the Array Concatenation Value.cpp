// time complexity=O(n)
// space complexity=O(1)
class Solution {
public:
    // Function to concatenate two numbers
    // time complexity=O(4)==O(1)
    long long concate(int a,int b) {
        string s=to_string(b);
        long long ans=a;
        for(int i=0;i<s.length();i++) {
            ans=ans*10+(s[i]-'0');
        }
        return ans;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<j) {
            long long temp=concate(nums[i++],nums[j--]);
            ans+=temp;
        }
        if(n%2==1) {
            ans+=nums[i];
        }
        return ans;
    }
};