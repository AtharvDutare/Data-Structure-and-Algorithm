// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        // code here
        int n=s.length();
        n=(n+1)/2;
        vector<vector<int>> dpt(n,vector<int>(n,0)),dpf(n,vector<int>(n,0));
        for(int g=0;g<n;g++) {
            for(int i=0,j=g;j<n;i++,j++) {
                if(g==0) {
                    char ch=s[2*i];
                    if(ch=='T') dpt[i][i]=1,dpf[i][i]=0;
                    if(ch=='F') dpt[i][i]=0,dpf[i][i]=1;
                }
                else {
                    for(int k=i;k<j;k++) {
                        char op=s[2*k+1];
                        long long lt=dpt[i][k];
                        long long lf=dpf[i][k];
                        long long rt=dpt[k+1][j];
                        long long rf=dpf[k+1][j];
                        if(op=='&') {
                            dpt[i][j]+=lt*rt;
                            dpf[i][j]+=lt*rf+lf*rt+lf*rf;
                            
                        }
                        else if(op=='|') {
                            dpt[i][j]+=lt*rf+lf*rt+lt*rt;
                            dpf[i][j]+=lf*rf;
                            
                        }
                        else if(op=='^') {
                            dpt[i][j]+=lt*rf+lf*rt;
                            dpf[i][j]+=lf*rf+lt*rt;
                        }
                    }
                }
            }
        }
        return dpt[0][n-1];
        
    }
};