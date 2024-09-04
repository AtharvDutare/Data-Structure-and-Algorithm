class Solution {
public:
/*this approach not work because at every point we need lastPrevGreaterElement and LastNextGreaterElement 
but nextGreaterEqElement function give firstNextGreaterElement not last
*/
vector<int> nextGreaterEqElement(vector<int> &height){
    stack<int> s;
    s.push(-1);
    vector<int> ans(height.size());
    for(int i=height.size()-1;i>=0;i--){
        int element=height[i];
        while(s.top()!=-1&&height[s.top()]<element){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);

    }
    return ans;
}
   int totalWaterContain(vector<int>& height){
       int i=0;
       vector<int> next=nextGreaterEqElement(height);
        int area=0;
       while(i!=height.size()){
           if(next[i]!=-1){
               area+=(next[i]-i-1)*height[i];
               for(int j=i+1;j<next[i];j++){
                   area=area-height[j];
               }
               i=next[i];
           }
           else i++;
       }
       return area;

   }
    int trap(vector<int>& height) {
        if(height.size()==1) return 0;
        int i=0;
        int j=height.size()-1;
        while(height[i]==0){
            i++;
        }
        while(height[j]==0){
            j--;
        }
        vector<int> heights;
        for(int k=i;k<=j;k++){
            heights.push_back(height[k]);
        }
        int ans=totalWaterContain(heights);
        return ans;
        
    }
};
/*to have lastNextGreaterElement we simply use prefixSum */
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=0;
        int maxLeft=0;
        int maxRight=0;
        //i==j point to heighest bar in map
        while(l<r) {
            if(height[l]<=height[r]) {
                if(maxLeft>height[l]) {
                    ans+=maxLeft-height[l];
                }
                else{
                    maxLeft=height[l];
                }
                l++;
            }
            else {
                if(maxRight>height[r]) {
                    ans+=maxRight-height[r];
                }
                else{
                    maxRight=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};