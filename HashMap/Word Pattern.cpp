class Solution {
    public boolean wordPattern(String p, String s) {
        String[] t=s.split(" ");
        if(t.length!=p.length()) {
            return false;
        }
        HashMap<Character,String> mp=new HashMap<>();
        HashMap<String,Character> mp2=new HashMap<>();
        int n=p.length();
        for(int i=0;i<p.length();i++) {
            char ch=p.charAt(i);
            String k=t[i];
            boolean f1=mp.containsKey(ch);
            boolean f2=mp2.containsKey(k);
            if(f1&&f2) {
                if(mp.get(ch)!=k&&mp2.get(k)!=ch) {
                    return false;
                }
            }
            else if(f1||f2) {
                return false;
            }
            else {
                mp.put(ch,k);
                mp2.put(k,ch);
            }
        }
        return true;
    }
}