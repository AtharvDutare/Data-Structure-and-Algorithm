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
    int n;
    cin>>n;
    vll sw(n+1);
    vll mon(n+1);
    for(int i=1;i<=n;i++) {
        cin>>sw[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>mon[i];
    }
    mon[0]=0;
    for(int i=1;i<=n;i++) {
        mon[i]=mon[i]+mon[i-1];
    }
    sort(all(sw));
    ll ans=0;
    // auto upperBound=[&](int &remSw) {
    //     // int level=0;
    //     // for(int i=1;i<=n;i++) {
    //     //     if(mon[i]<=remSw){
    //     //         level++;
    //     //     }
    //     //     else{
    //     //         break;
    //     //     }
    //     // }
    //     // return level;
    //     // TLE due to O(n)

    //     int level=0;
    //     int i=1;
    //     int j=n;
    //     while(i<=j) {
    //         int mid=(j-i)/2+i;
    //         if(mon[mid]<=remSw) {
    //             level=mid;
    //             i++;
    //         }
    //         else {
    //             j--;
    //         }
    //     }
    //     return level;
    // };

    for(int i=1;i<=n;i++) {
        int diff=sw[i];
        int remSw=n-i+1;
        //int level=upperBound(remSw);
        int level=upper_bound(all(mon),remSw)-mon.begin()-1;
        //cout<<diff<<" "<<level<<endl;
        ans=max(ans,1LL*diff*level);
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

