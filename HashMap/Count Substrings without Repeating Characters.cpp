public class Main {
    private static void solve(String s) {
        int ans=0;
        int n=s.length();
        HashSet<Character> hs=new HashSet<>();
        int i=0;
        int j=0;
        //creating the window
        while(j<n) {
            if(!hs.contains(s.charAt(j))) {
                hs.add(s.charAt(j));
                j++;
            }
            else {
                break;
            }
        }
        ans+=j-i;
        //moving the window
        while(j<n) {
            char t=s.charAt(i);
            i++;
            hs.remove(t);
            while(j<n&&!hs.contains(s.charAt(j))) {
                hs.add(s.charAt(j));
                j++;
                ans+=j-i;
            }
        }
        //aabcbcdbca     
        //consuming the last window
        //ans+=j-i;
        return ans;
    }
}

// no of new substring created between i to j if we add new character at j is j-i