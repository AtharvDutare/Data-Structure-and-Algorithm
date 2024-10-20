import java.util.* ;
import java.io.*; 
import javafx.util.Pair;
public class Solution {
	public static int countSubarrays(int n, int[] arr) {
		HashMap<Pair<Integer,Integer>,Integer> mp=new HashMap<>();
		int two=0;
		int one=0;
		int zero=0;
		int ans=0;
		int diff1=two-one;
		int diff2=one-zero;
		mp.put(new Pair(diff1,diff2),1);
		for(int i=0;i<n;i++) {
			if(arr[i]==2) {
				two++;
			}
			else if(arr[i]==1) {
				one++;
			}
			else {
				zero++;
			}
			diff1=two-one;
			diff2=one-zero;
			Pair temp=new Pair(diff1,diff2);
			if(mp.containsKey(temp)) {
				ans+=mp.get(temp);
			}
			mp.put(temp,mp.getOrDefault(temp,0)+1);
		}
		return ans;
// 	}
// public static class Pair<K extends Comparable<K>, V> implements Comparable<Pair<K, V>> {

//     private final K key;
//     private final V value;

//     public Pair(K key, V value) {
//         this.key = key;
//         this.value = value;
//     }

//     public K getKey() {
//         return key;
//     }

//     public V getValue() {
//         return value;
//     }

//     @Override
//     public int compareTo(Pair<K, V> other) {
//         return this.key.compareTo(other.key);
//     }

//     @Override
//     public boolean equals(Object o) {
//         if (this == o) return true;
//         if (o == null || getClass() != o.getClass()) return false;
//         Pair<?, ?> pair = (Pair<?, ?>) o;
//         return Objects.equals(key, pair.key) && Objects.equals(value, pair.value);
//     }

//     @Override
//     public int hashCode() {
//         return Objects.hash(key, value);
//     }
}
}