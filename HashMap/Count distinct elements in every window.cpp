class Solution
{
    ArrayList<Integer> countDistinct(int arr[], int n, int k)
    {
        ArrayList<Integer> ans=new ArrayList<>();
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<k-1;i++) {
            int freq=mp.getOrDefault(arr[i],0);
            mp.put(arr[i],freq+1);
        }
        int i=0;
        int j=k-1;
        while(j<n) {
            int freq=mp.getOrDefault(arr[j],0);
            mp.put(arr[j],freq+1);
            ans.add(mp.size());
            int fre=mp.get(arr[i]);
            //mp.put(arr[i],fre-1);
            if(fre==1) {
              mp.remove(arr[i]);  
            }
            else {
                mp.put(arr[i],fre-1);
            }
            i++;
            j++;
            
        }
        return ans;
    }
}
//c++
class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int>mp;
        //create the window
        for(int i=0;i<k-1;i++) {
            mp[arr[i]]++;
        }
        int i=0;
        int j=k-1;
        while(j<n) {
            //acquire
            mp[arr[j]]++;
            //result
            ans.push_back(mp.size());
            //release
            mp[arr[i]]--;
            if(mp[arr[i]]==0) {
                mp.erase(arr[i]);
            }
            i++;
            j++;
        }
        return ans;
    }
};

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int>mp;
        //create the window
        for(int i=0;i<k;i++) {
            mp[arr[i]]++;
        }
        int i=0;
        int j=k-1;
        while(j<n) {
            ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0) {
                mp.erase(arr[i]);
            }
            i++;
            j++;
            mp[arr[j]]++;
        }
        return ans;
    }
};