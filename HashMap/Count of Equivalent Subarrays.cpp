public class Main {
    class Solution{ 
        // Method to calculate distinct sub-array 
        static int countDistinctSubarray(int arr[], int n) { 
            int ans=0;
            HashSet<Integer> hs=new HashSet<>();
            for(int i=0;i<n;i++) {
                hs.add(arr[i]);
            }
            int k=hs.size();
            int i=-1;
            int j=-1;
            HashMap<Integer,Integer> mp=new HashMap<>();
            while(true) {
                boolean f1=false;
                boolean f2=false;
                while(i<n-1) {
                    f1=true;
                    i++;
                    mp.put(arr[i],mp.getOrDefault(arr[i],0)+1);
                    if(mp.size()==k) {
                        ans+=n-i;
                        break;
                    }
                }
                while(j<i) {
                    f2=true;
                    j++;
                    if(mp.get(arr[j])==1) {
                        mp.remove(arr[j]);
                    }
                    else 
                    mp.put(arr[j],mp.getOrDefault(arr[j],0)-1);
                        
                    if(mp.size()==k) {
                        ans+=n-i;
                    }
                    else {
                        break;
                    }
                }
                if(!f1&&!f2) {
                    break;
                }
            }
            return ans;
        }
    }
}