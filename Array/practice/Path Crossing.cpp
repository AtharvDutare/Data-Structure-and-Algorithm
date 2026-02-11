class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        map<pair<int,int>,int> mp;
        mp[{0,0}]=1;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
        for(auto &k:path) {
            //cout<<x<<" "<<y<<endl;
            if(k=='N') {
                x=x+dir[0].first;
                y=y+dir[0].second;
            }
            else if(k=='S') {
                x=x+dir[1].first;
                y=y+dir[1].second;
            }
            else if(k=='E') {
                x=x+dir[2].first;
                y=y+dir[2].second;
            }
            else {
                x=x+dir[3].first;
                y=y+dir[3].second;
            }
            if(mp.find({x,y})!=mp.end()) {
                return true;
            }
            mp[{x,y}]=1;
        }
        return false;
    }
};