class Solution {
public:
    vector<int> prevSmallerElement(vector<int> &heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=0;i<heights.size();i++){
            int element =heights[i];
            while(s.top()!=-1&&heights[s.top()]>=element){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }
    vector<int> nextSmallerElement(vector<int> &heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            int element=heights[i];
            while(s.top()!=-1&&heights[s.top()]>=element)
            s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=prevSmallerElement(heights);
        vector<int> next=nextSmallerElement(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            int width=(next[i]==-1?heights.size():next[i])-prev[i]-1;
            int area=length*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};