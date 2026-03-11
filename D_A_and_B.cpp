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

    INITUITION

    four cases 
    a*b*a*
    b*a*b*
    a*b*
    b*a*

*/

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vll pa(n),pb(n),sa(n),sb(n);
    vll cnta(n),cntb(n);
    ll totala=0;
    ll totalb=0;
    for(ll i=0;i<n;i++) {
        if(s[i]=='a') {
            totala++; 
        }
        else {
            totalb++;  
        }
        cnta[i]=totala;
        cntb[i]=totalb;
    }
    // prll_v(cnta);
    // prll_v(cntb);

    //pa[0]=s[0]=='a';
    //make all a togethor
    for(ll i=1;i<n;i++) {
        if(s[i]=='b') {
            pa[i]=pa[i-1]+cnta[i];
            //cout<<"hello"<<endl;
        }
        else {
            pa[i]=pa[i-1];
        }
    }

    //pb[0]=s[0]=='b';
    //make all b togethor
    for(ll i=1;i<n;i++) {
        if(s[i]=='a') {
            pb[i]=pb[i-1]+cntb[i];
        }
        else {
            pb[i]=pb[i-1];
        }
    }

    //sa[n-1]=s[n-1]=='a';
    //make all a togethor
    for(ll i=n-2;i>-1;i--) {
        if(s[i]=='b') {
            sa[i]=sa[i+1]+totala-cnta[i];
        }
        else {
            sa[i]=sa[i+1];
        }
    }

    //sa[n-1]=s[n-1]=='b';
    //make all b togethor
    for(ll i=n-2;i>-1;i--) {
        if(s[i]=='a') {
            sb[i]=sb[i+1]+totalb-cntb[i];
        }
        else {
            sb[i]=sb[i+1];
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<n;i++) {
        ans=min(ans,pa[i]+sa[i]);
        ans=min(ans,pb[i]+sb[i]);
        // if(ans==0) {
        //     cout<<i<<endl;
        // }
    }
    cout<<ans<<endl;
    // cout<<"pa"<<endl;
    // print_v(pa);
    // cout<<"pb"<<endl;
    // print_v(pb);
    // cout<<"sa"<<endl;
    // print_v(sa);
    // cout<<"sb"<<endl;
    // print_v(sb);

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