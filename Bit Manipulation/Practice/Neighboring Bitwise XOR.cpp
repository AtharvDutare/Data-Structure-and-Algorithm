// my approach
//time complexity O(n) and space complexity O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n=d.size();
        int x=0;
        for(int i=0;i<n;i++) {
            if(d[i]) {
                x=!x;
            }
            if(i==n-1&&x==0) {
                return true;
            }
        }
        return false;
    }
};