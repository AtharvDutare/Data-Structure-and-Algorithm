class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
public:
    int lengthOfLis(vector<int>&arr) {
        int n=arr.size();
        vector<int> lis;
        for(int i=0;i<n;i++) {
            if(lis.empty()||lis.back()<arr[i]) {
                lis.push_back(arr[i]);
            }
            else {
                auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
                *it=arr[i];
            }
        }
        return (int)lis.size();
    }
   
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        vector<int> seq;
        for(auto &x:arr) {
            seq.push_back(x[1]);
        }
        int ans=lengthOfLis(seq);
        return ans;
    }
};