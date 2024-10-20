import java.util.*;
public class Solution {
    public static int countSubStrings(String s, int k) {
        int ans=0;
        if(k==1) {
            return solutionForOne(s);
        }
        int n=s.length();
        HashMap<Character,Integer> kOne=new HashMap<>();
        HashMap<Character,Integer> lessK=new HashMap<>();
        int is=-1;
        int ib=-1;
        int j=-1;
        while(true) {
            boolean f1=false;
            boolean f2=false;
            boolean f3=false;
            while(ib<n-1) {
                f1=true;
                ib++;
                char ch=s.charAt(ib);
                kOne.put(ch,kOne.getOrDefault(ch,0)+1);
                if(kOne.size()==k+1) {// kOne.size()>k
                    removeInMap(kOne,ch);
                    ib--;
                    break;
                }
            }
            while(is<ib) {
                f2=true;
                is++;
                char ch =s.charAt(is);
                lessK.put(ch,lessK.getOrDefault(ch,0)+1);
                if(lessK.size()==k) {
                    removeInMap(lessK,ch);
                    is--;
                    break;
                }
            }
            while(j<is) {
                f3=true;
                if(kOne.size()==k&&lessK.size()==k-1) {
                    ans+=ib-is;
                }
                j++;
                char ch = s.charAt(j);
                removeInMap(kOne,ch);
                removeInMap(lessK,ch);
                if(kOne.size()<k||lessK.size()<k-1) {
                    break;
                }
            }
            if(!f1&&!f2&&!f3) {
                break;
            }
        }
        return ans;
    }
     private static void removeInMap(HashMap<Character,Integer>mp,char ch){
        if(mp.get(ch)==1) {
            mp.remove(ch);
        }
        else {
            mp.put(ch,mp.get(ch)-1);
        }
    }
    private static int solutionForOne(String s) {
        int ans = 0;
        HashMap<Character,Integer> mp=new HashMap<>();
        int i=-1;
        int j=-1;
        while(true) {
            boolean f1=false;
            boolean f2=false;
            while(i<s.length()-1) {
                f1=true;
                i++;
                char ch=s.charAt(i);
                mp.put(ch,mp.getOrDefault(ch,0)+1);
                if(mp.size()>1) {
                    removeInMap(mp,ch);
                    i--;
                    break;
                }
            }
            while(j<i) {
                f2=true;
                if(mp.size()==1) {
                    ans+=i-j;
                }
                j++;
                char ch=s.charAt(j);
                removeInMap(mp,ch);
                if(mp.size()==0) {
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