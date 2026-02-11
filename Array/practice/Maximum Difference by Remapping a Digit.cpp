//Optimal Solution
// time complexity O(n)
// space complexity O(1) ===O(9)
class Solution {
public:
    int minMaxDifference(int num) {
        string s1=to_string(num);
        string s2=s1;
        int n=s1.length();
        int i=0;
        int f=0;
        while(i<n&&s1[i]=='9') {
            s2[i]='0';
            f=1;
            i++;
        }
        if(i==n) {
            return stoi(s1);
        }
        char ch1=s1[i];
        char ch2='9';
        if(!f) {
            ch2=ch1;
        }
        for(int k=i;k<n;k++) {
            if(s1[k]==ch1) {
                s1[k]='9';
            }
            if(s2[k]==ch2) {
                s2[k]='0';
            }
        }
        return stoi(s1)-stoi(s2);
    }
};