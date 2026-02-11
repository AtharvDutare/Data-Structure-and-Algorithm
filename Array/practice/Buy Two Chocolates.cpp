class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallEle=INT_MAX;
        int secSmallEle=INT_MAX;

        for(auto price:prices){
            if(price<smallEle){
                secSmallEle=smallEle;
                smallEle=price;
            }
            else{
                secSmallEle=min(secSmallEle,price);
            }
        }
        if(smallEle+secSmallEle>money){
            return money;
        }
        return money-smallEle-secSmallEle;
    }
};