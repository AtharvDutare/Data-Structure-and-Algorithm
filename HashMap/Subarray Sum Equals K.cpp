class Solution {
    public int subarraySum(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer> mp=new HashMap<>();
        int currSum=0;
        int ans=0;
        mp.put(currSum,1);
        for(int i=0;i<n;i++) {
            currSum+=nums[i];
            int temp=currSum-k;
            if(mp.containsKey(temp)) {
                ans+=mp.get(temp);
            }
            mp.put(currSum,mp.getOrDefault(currSum,0)+1);
        }
        return ans;
    }
}