class Solution {
public:
    /*time complexity is O(N) and space is O(N)*/
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(auto &x:asteroids) {
            while(!st.empty() && st.back()>0 && x<0) {
                int sum=st.back()+x;
                if(sum>0) {
                    //left side >right side then asteroids destoryed
                    x=0;
                } 
                else if(sum <0) {
                    //left<right means asteroid is powerful so it destroy left asteroid
                    st.pop_back();
                }
                else{
                    //both destory each other
                    st.pop_back();
                    x=0;
                }
            }
            //if asteroid is have some power
            if(x!=0) {
                st.push_back(x);
            }
        }
        return st;
    }
};