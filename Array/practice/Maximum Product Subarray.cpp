class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++) {
            prod*=arr[i];
            maxi=max(prod,maxi);
            if(prod==0) {
                prod=1;
            }
        }
        prod=1;
        for(int i=n-1;i>-1;i--) {
            prod*=arr[i];
            maxi=max(prod,maxi);
            if(prod==0) {
                prod=1;
            }
        }
        return maxi;
    }
};