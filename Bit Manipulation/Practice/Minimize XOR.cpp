//My solution
//time complexity=O(32)==O(1) and space complexity=O(32)==O(1)

class Solution {
public:
    int bitCount(int x) {
        int ans=0;
        while(x>0) {
            if(x&1) {
                ans++;
            }
            x=x>>1;
        }
        return ans;
    }
    int minimizeXor(int num1, int num2) {
        int t=bitCount(num2);
        vector<int> t1(32,0),t2(32,0);
        for(int i=0;num1>0&&i<32;i++) {
            if(num1&1) {
                t1[i]=1;
            }
            num1=num1>>1;
        }
        for(int i=31;i>=0&&t>0;i--) {
            if(t1[i]==1) {
                t2[i]=1;
                t--;
            }
        }
        if(t>0) {
            for(int i=0;t>0&&i<32;i++) {
                if(t2[i]==0) {
                    t2[i]=1;
                    t--;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++) {
            if(t2[i]) {
                ans+=(1<<i);
            }
        }
        return ans;
    }
};