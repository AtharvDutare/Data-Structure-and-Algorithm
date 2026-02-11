class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                oneCount++;
                s[i]='0';
            }
        }
        s[n-1]='1';
        oneCount--;
        int i=0;
        while(oneCount--){
            s[i]='1';
            i++;
        }
        return s;
    }
};

class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        n = len(s)
        oneCount=0
        s=list(s)
        for i in range(0,n):
            if s[i]=='1':
                oneCount=oneCount+1
        
        s[n-1]='1'
        oneCount-=1
        for i in range(n-1):
            if oneCount>0:
                s[i]='1'
                oneCount-=1
            else:
                s[i]='0'
        return ''.join(s)