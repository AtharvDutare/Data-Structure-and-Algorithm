// time complexity: O(n) and space complexity: O(n)

class Solution {
  public:
    vector<int> countUnique(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        unordered_map<int,int>mp;
        int distCount=0;
        int i=0;
        while(i<k) {
            if(mp.find(arr[i])==mp.end()) {
                    distCount++;
                mp[arr[i]]=1;
            }
            else {
                if(mp[arr[i]]==1) {
                    distCount--;
                }
                mp[arr[i]]++;
            }
            i++;
        }
        vector<int> ans;
        ans.push_back(distCount);
        while(i<n) {

            int j=i-k;
            if(mp[arr[j]]==1) {
                mp.erase(arr[j]);
                distCount++;
            }
            else {
                mp[arr[j]]--;
            }
            if(mp.find(arr[i])==mp.end()) {
                mp[arr[i]]=1;
                distCount++;
            }
            else {
                if(mp[arr[i]]==1) {
                    distCount--;
                }
                mp[arr[i]]++;
            }
            ans.push_back(distCount);
            i++;
        }
        return ans;
    }
};