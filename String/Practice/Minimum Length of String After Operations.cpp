// approach: greedy 
// The idea is to remove the same characters from the beginning and end of the string.
// So, we can keep track of the frequency of each character in the string.
// Then, we can iterate through the string and remove the same characters from the beginning and end of the string.
// We can keep track of the frequency of each character in the left and right side of the string.
// If the frequency of a character is greater than 1 in both the left and right side of the string, we can remove the character from the beginning and end of the string.
// We can keep track of the total number of characters in the string and return the total number of characters in the string after removing the same characters from the beginning and end of the string.
// The time complexity is O(n) and the space complexity is O(n) where n is the length of the string.
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        unordered_map<char,int> total,left;
        for(int i=0;i<n;i++) {
            total[s[i]]++;
        }
        for(int i=0;i<n;i++) {
            if(left[s[i]]>0&&(total[s[i]]-left[s[i]]-1)>0) {
                total[s[i]]-=2;
                left[s[i]]-=2;
                //cout<<s[i]<<endl;
            }
            left[s[i]]++;
        }
        int ans=0;
        for(auto &x:total) {
            //cout<<x.first<<" "<<x.second<<endl;
            ans+=x.second;
        }
        return ans;
    }
};