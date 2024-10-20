class Solution {
    public boolean canArrange(int[] arr, int k) {
        int n=arr.length;
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<n;i++) {
            int rem=(arr[i]%k+k)%k;
            int curfreq=mp.getOrDefault(rem,0);
            mp.put(rem,curfreq+1);
        }
        for(Integer ele:mp.keySet()) {
            int freq=mp.get(ele);
            if(ele==0||2*ele==k) {
                if(freq%2==1) {
                    return false;
                }
            }
            else {
                if(mp.containsKey(k-ele)) {
                    if(freq!=mp.get(k-ele)) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
}
//c++
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int n= arr.size();
        for(int i=0;i<n;i++) {
            mp[(arr[i]%k+k)%k]++;
        }
        for(auto &x:mp) {
            if(x.first==0||2*x.first==k) {
                if(x.second%2==1) {
                    return 0;
                }
            }
            else {
                if(mp.find(k-x.first)!=mp.end()) {
                    if(x.second!=mp[k-x.first]) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};