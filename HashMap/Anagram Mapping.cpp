import java.util.* ;
import java.io.*; 
public class Solution {
	public static int[] anagramMapping(int n, int[] a, int[] b) {
		int[] ans=new int[n];
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int i=0;i<n;i++) {
			mp.put(b[i],i);
		}
		for(int i=0;i<n;i++) {
			ans[i]=mp.get(a[i]);
		}
		return ans;
	}
}