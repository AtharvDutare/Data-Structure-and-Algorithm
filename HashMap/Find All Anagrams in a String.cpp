class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans=new ArrayList<>();
        if(s.length()<p.length()) {
            return ans;
        }
        HashMap<Character,Integer> mp1=new HashMap<>();
        HashMap<Character,Integer> mp2=new HashMap<>();
        for(int i=0;i<p.length();i++) {
            char ch =p.charAt(i);
            mp2.put(ch,mp2.getOrDefault(ch,0)+1);
           // mp2[p[j]]++;
        }  
        for(int i=0;i<p.length();i++) {
            char ch =s.charAt(i);
            mp1.put(ch,mp1.getOrDefault(ch,0)+1);
           // mp2[p[j]]++;
        }
        if(mp1.equals(mp2)) {
            ans.add(0);
        }
        int i=p.length()-1;
        int j=-1;
        while(i<s.length()-1)  {
            i++;
            j++;
            char ch= s.charAt(i);
            char ch1=s.charAt(j);
            mp1.put(ch,mp1.getOrDefault(ch,0)+1);
            if(mp1.get(ch1)==1) {
                mp1.remove(ch1);
            }
            else
            mp1.put(ch1,mp1.get(ch1)-1);
            if(mp1.equals(mp2)) {
                ans.add(j+1);
            }
        }    
        return ans;
    }
}