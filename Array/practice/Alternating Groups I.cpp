class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int x=0;
        int y=1;
        int z=2;
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            if(colors[x]==colors[z]&&colors[y]!=colors[x]) {
                ans++;
            }
            x=(x+1)%n;
            y=(y+1)%n;
            z=(z+1)%n;
        }
        return ans;
    }
};