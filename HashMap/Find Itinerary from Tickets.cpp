import java.util.*;
public class Main{

    private static void solve(HashMap<String,String> mp) {
        int n=mp.size();
        ArrayList<String> ans=new ArrayList<>();
        HashMap<String,Integer> freq=new HashMap<>();
        for(String source: mp.keySet()) {
            String dest=mp.get(source);
            freq.put(dest,0);
            if(freq.containsKey(source)==false) {
                freq.put(source,1);
            } 
        }
        String t="";
        for(String k:freq) {
            if(freq.get(k)==1) {
                t=k;
                break;
            }
        }
        while(mp.containKey(t)) {
            ans.add(t);
            t=mp.get(t);
        }
        for(String a:ans) {
            System.out.println(a);
        }
    }
    public static void main(String args[]) {

    }
}