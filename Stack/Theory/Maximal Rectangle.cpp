class Solution {
public:
    vector<int> prevSmallerElement(vector<int>heights){
        stack<int>s;
        s.push(-1);
        int n=heights.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int element=heights[i];
            while(s.top()!=-1&&heights[s.top()]>=element){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int>heights){
        stack<int>s;
        s.push(-1);
        int n=heights.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int element=heights[i];
            while(s.top()!=-1&&heights[s.top()]>=element){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int histrogram(vector<int> &heights){
        int maxArea=-1;
        vector<int> prev=prevSmallerElement(heights);
        vector<int> next=nextSmallerElement(heights);
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            if(next[i]==-1) next[i]=heights.size();
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxArea=-1;
        vector<int> heights(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]-'0'==1){
                    heights[j]++;
                }
                else heights[j]=0;
            }
            maxArea=max(maxArea,histrogram(heights));

        }
        return maxArea;
    }
};