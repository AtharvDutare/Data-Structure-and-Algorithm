// my first approach FAILED
// because of we always find {x,0} or {0,x}
// their can be exist {a,b} such that a-b==x or b-a==x
// time complexity O(n) and space complexity O(n)
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int ans=0;
        map<pair<int,int>,int>mp;
        pair<int,int> cumFreq={0,0};
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++) {
            if(arr[i]) {
                cumFreq.second++;
            }
            else {
                cumFreq.first++;
            }
            if(cumFreq.first==cumFreq.second) {
                ans=max(ans,i+1);
            }
            pair<int,int> rem;
            if(cumFreq.first>cumFreq.second){
                rem={cumFreq.first-cumFreq.second,0};
            }else {
                rem={0,cumFreq.second-cumFreq.first};
            }
            if(mp.find(rem)!=mp.end()) {
                ans=max(ans,i-mp[rem]);
            }
            if(mp.find(cumFreq)==mp.end())  {
                mp[cumFreq]=i;
            }
        }
        return ans;
    }
};
// second approach Optimal
// here we count 1 as +1 and 0 as -1
// so here if diff =5 then we find the least index
// having diff =5 so that we decrease the count of 1 
// to make no of 1 and 0 equal
// time complexity O(n) and space complexity O(n)
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int ans=0;
        unordered_map<int,int>mp;
        int currDiff=0;
        for(int i=0;i<n;i++) {
            if(arr[i]) {
                currDiff++;
            }
            else {
                currDiff--;
            }
            if(currDiff==0) {
                ans=max(ans,i+1);
            }
            else if(mp.find(currDiff)!=mp.end()) {
                ans=max(ans,i-mp[currDiff]);
            }
            if(mp.find(currDiff)==mp.end()) {
                mp[currDiff]=i;
            }
        }
        return ans;
    }
};