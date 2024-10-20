#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    unordered_map<char,int> mp;
    int n = str.length();
    int ans=0;
    int distinct=0;
    int j=0;
    for(int i=0;i<n;i++) {
        if(mp.find(str[i])==mp.end()) {
            distinct++;
        }
        mp[str[i]]++;
        if(distinct<=k) {
            ans=max(ans,i-j+1);
        }
        else {
            while(j<=i&&distinct>k) {
                char t=str[j];
                mp[str[j]]--;
                if(mp[str[j]]==0) {
                    distinct--;
                    mp.erase(str[j]);
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
    }
    //ans=max(ans,n-j);
    return ans;
}
import java.util.HashMap;

public class Solution {

	public static int kDistinctChars(int k, String s) {
		int ans =0;
		int i=-1;
		int j=-1;
		int n=s.length();
		HashMap<Character,Integer> mp=new HashMap<>();
		while(true) {
			boolean f1=false;
			boolean f2=false;
			while(i<n-1) {
				f1=true;
				i++;
				char ch=s.charAt(i);
				mp.put(ch,mp.getOrDefault(ch,0)+1);
				if(mp.size()>k) {
					break;
				}
				else {
					ans=Math.max(ans,i-j);
				}
			}
			while(j<i) {
				f2=true;
				j++;
				char ch=s.charAt(j);
				if(mp.get(ch)==1) {
					mp.remove(ch);
				}
				else {
					mp.put(ch,mp.get(ch)-1);
				}
				if(mp.size()==k) {
					ans=Math.max(ans,i-j);
					break;
				}
				else if(mp.size()<k) {
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
