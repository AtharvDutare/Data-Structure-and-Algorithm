class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n=nums.length;
        int ans=0;
        HashMap<Integer,Integer> mp=new HashMap<>(); 
        int currSum=0;
        mp.put(currSum%k,1);
        for(int i=0;i<n;i++) {
            currSum+=nums[i];
            int rem=(currSum%k+k)%k;
            if(mp.containsKey(rem)) {
                ans+=mp.get(rem);
            }
            mp.put(rem,mp.getOrDefault(rem,0)+1);
        }
        return ans;
    }
}