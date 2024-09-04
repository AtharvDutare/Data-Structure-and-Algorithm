class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=p.size();
        vector<int> ans;
        vector<int> realIndex(n);
        iota(realIndex.begin(),realIndex.end(),0);
        auto lambha=[&](int &i,int &j){
            return p[i]<p[j];
        };
        //0 1 2 3 ->realIndex arr
        //3 5 2 6 ->P arr
        //here we are sort on base of P array 
        sort(realIndex.begin(),realIndex.end(),lambha);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            int index=realIndex[i];
            //this part is same as Astoried collision
            if(d[index]=='R'){
                st.push(index);
            }
            else{
                while(!st.empty()&&h[index]>0){
                    int topIndex=st.top();
                    st.pop();
                    if(h[index]>h[topIndex]){
                        h[index]--;
                        h[topIndex]=0;
                    }
                    else if(h[index]<h[topIndex]){
                        h[index]=0;
                        h[topIndex]--;
                        st.push(topIndex);
                    }
                    else{
                        h[index]=0;
                        h[topIndex]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(h[i]>0){
                ans.push_back(h[i]);
            }
        }
        return ans;
    }
    
};