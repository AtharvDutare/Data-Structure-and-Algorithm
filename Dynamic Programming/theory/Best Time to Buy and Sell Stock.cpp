class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniBuy=prices[0];
        int n=prices.size();
        int maxProfit=0;
        for(int i=0;i<n;i++) {
            int profit=prices[i]-miniBuy;
            if(maxProfit<profit){
                maxProfit=profit;
            }
            if(miniBuy>prices[i]){
                miniBuy=prices[i];
            }
        }
        return maxProfit;
    }
};