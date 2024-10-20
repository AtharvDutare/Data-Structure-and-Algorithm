class Solution {
public:
    string removeKdigits(string nums, int k) {
        string result="";
        int n=nums.length();
        if(n==k) return"0";
        for(int i=0;i<n;i++){
            //we maiatain the increasing order
            while(result.length()>0&&(result.back()>nums[i])&&k>0){
                //1 4 3 we delete 4 
                result.pop_back();
                k--;
            }
            // it prevent 0 from starting
            if(result.length()>0||nums[i]!='0'){
            result.push_back(nums[i]);
            }
        }
        /*now result now in increasing order then if k is not zero
        then we remove from right most side */
        while(result.length()>0&&k>0){
            result.pop_back();
            k--;
        }
        if(result=="") return "0";
        return result;
    }
};