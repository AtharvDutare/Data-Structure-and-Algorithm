class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sortedStr;
        set<string> uniq;
        for(auto x:strs){
            sort(x.begin(),x.end());
            sortedStr.push_back(x);
        }
        for(auto y:sortedStr){
            uniq.insert(y);
        }
        for(auto z:uniq){
            vector<string>temp;
            for(int j=0;j<sortedStr.size();j++){
                if(z==sortedStr[j]){
                    temp.push_back(strs[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> temp;
        for(auto x:strs){
            string t=x;
            sort(t.begin(),t.end());
            temp[t].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto [x,y]:temp){
            ans.push_back(y);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> mp;
        int n=strs.size();
        for(int i=0;i<n;i++) {
            map<char,int> tempMp;
            for(int j=0;j<strs[i].length();j++) {
                tempMp[strs[i][j]]++;
            }
            mp[tempMp].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &x:mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
class Solution {
    public List<List<String>> groupAnagrams(String[] s) {
        int n=s.length;
        List<List<String>> ans=new ArrayList<>();
        HashMap<HashMap<Character,Integer>,List<String>> mp=new HashMap<>();
        for(int i=0;i<n;i++) {
            HashMap<Character,Integer> temp=new HashMap<>();
            for(int j=0;j<s[i].length();j++) {
                char ch=s[i].charAt(j);
                temp.put(ch,temp.getOrDefault(ch,0)+1);
            }
            if(mp.containsKey(temp)) {
                List<String> t=mp.get(temp);
                t.add(s[i]);
            }
            else {
                List<String> t=new ArrayList<>();
                t.add(s[i]);
                mp.put(temp,t);
            }
        }
        mp.forEach((v,k)->ans.add(k));
        return ans;
    }
}