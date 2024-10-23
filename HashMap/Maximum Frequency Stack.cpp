class FreqStack {
public:
    vector<int> v;
    unordered_map<int,int>mp;
    unordered_map<int,vector<int>> lastSeen;
    FreqStack() {
    
    }
    
    
    void push(int val) {
        mp[val]++;
        v.push_back(val);
        lastSeen[val].push_back(v.size()-1);
        auto lambha=[&](int a,int b) {
            if(mp[a]==mp[b]) {
                return lastSeen[a].back()<lastSeen[b].back();
            }
            else 
            return mp[a]<mp[b];
        };
        
        sort(v.begin(),v.end(),lambha);
        // for(auto &x:v) {
        //     cout<<x<<" ";
        // }cout<<endl;
    }
    
    int pop() {
        int k=v[v.size()-1];
        v.pop_back();
        lastSeen[k].pop_back();
        mp[k]--;
        auto lambha=[&](int a,int b) {
            if(mp[a]==mp[b]) {
                return lastSeen[a].back()<lastSeen[b].back();
            }
            else 
            return mp[a]<mp[b];
        };
        sort(v.begin(),v.end(),lambha);
        return k;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class FreqStack {
public:
    vector<int> v;
    unordered_map<int,int>mp;
    unordered_map<int,vector<int>> lastSeen;
    FreqStack() {
    
    }
    
    
    void push(int val) {
        mp[val]++;
        v.push_back(val);
        lastSeen[val].push_back(v.size()-1);
        auto lambha=[&](int a,int b) {
            if(mp[a]==mp[b]) {
                return lastSeen[a].back()<lastSeen[b].back();
            }
            else 
            return mp[a]<mp[b];
        };
        
        sort(v.begin(),v.end(),lambha);
        // for(auto &x:v) {
        //     cout<<x<<" ";
        // }cout<<endl;
    }
    
    int pop() {
        int k=v[v.size()-1];
        v.pop_back();
        lastSeen[k].pop_back();
        mp[k]--;
        auto lambha=[&](int a,int b) {
            if(mp[a]==mp[b]) {
                return lastSeen[a].back()<lastSeen[b].back();
            }
            else 
            return mp[a]<mp[b];
        };
        sort(v.begin(),v.end(),lambha);
        return k;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */