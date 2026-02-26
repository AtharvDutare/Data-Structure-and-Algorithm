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

/* clang-format on */

void solve()
{
    ll n,k;
    cin>>n>>k;
    // set<ll,greater<ll>> q;
    // q.insert(k);
    // int ans=0;
    // if(k==n) {
    //     cout<<ans<<endl;
    //     return;
    // }
    
    // while(q.size()>0) {
    //     ans++;
    //     int k=q.size();
    //     int turn=0;
    //     while(k--) {
    //         turn++;
    //         ll t=*q.begin();
    //         q.erase(q.begin());
    //         ll x=2*t;
    //         ll y=2*t-1;
    //         ll z=2*t+1;
    //         if(x==n||y==n||z==n) {
    //             cout<<ans<<endl;
    //             return;
    //         }
    //         //cout<<x<<" "<<y<<endl;
    //         if(x<n) {
    //             q.insert(x);
    //         }
    //         if(y<n) {
    //             q.insert(y);
    //         }
    //         if(z<n) {
    //             q.insert(z);
    //         }
    //         if(turn>40) {
    //             cout<<q.size()<<" "<<turn<<endl;
    //             assert(ans>40);

    //         }
                
    //     }
        
    // }
    // cout<<-1<<endl;

    int l=n;
    int r=n;
    int ans=0;
    if(l==k||r==k) {
        cout<<0<<endl;
        return;
    }
    while(r!=1) {
        if(l<=k&&k<=r) break;//
        l=floor(l*1.0/2);
        r=ceil(r*1.0/2);
        ans++;
    }
    if(l==k||r==k) {
        cout<<ans<<endl;
    }
    else {
        cout<<-1<<endl;
    }
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