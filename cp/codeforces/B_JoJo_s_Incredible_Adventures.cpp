#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define Graph unordered_map<int,vector<int>>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { for (auto x : v) cout << x << " "; cout << endl; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

//fast exponanation
ll power(int a,int b){
    if(!b) return 1;
    ll half_power=power(a,b/2);
    if(b%2==0) return( half_power*half_power)%MOD;
    return ((half_power*half_power)%MOD*a%MOD)%MOD;
}

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/* clang-format on

    we use two vector of prev and curr
        by using prev we construct the curr array 
        this array store the contigous 1's on vertical space 

        after calculate the curr find the maximum rectangle 
        by iterate the current vector 
            i=0 and j=0
                while(i==j) j++
                else ans=max(ans,(j-1)*curr[i])
                        i=j


*/

void solve()
{
    string s;
    cin>>s;
    //cout<<s<<endl;
    int n=s.length();
    int ans=0;
    vector<int> prev(n,0);
    for(int i=0;i<n;i++) {
        for(int w=0;w<n;w++) {
            if(s[w]=='0') {
                prev[w]=0;
            }
            else {
                prev[w]++;
            }
        }
        int j=0;
        int k=0;
        while(k<n) {
            if(prev[j]!=prev[k]) {
                ans=max((k-j)*prev[j],ans);
                //cout<<j<<" "<<k<<" "<<(k-j)*prev[j]<<" row is "<<i<<endl;
                j=k;
            }   
            k++;
        }
        //cout<<j<<" "<<k<<" "<<(k-j)*prev[j]<<" row is "<<i<<endl;
        ans=max((k-j)*prev[j],ans);
        //cout<<s<<endl;
        rotate(s.rbegin(), s.rbegin() + 1, s.rend());
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}