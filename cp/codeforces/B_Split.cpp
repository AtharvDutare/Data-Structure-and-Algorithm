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
    ll n;
    cin>>n;
    vi arr(2*n);
    f(i,0,2*n) {
        cin>>arr[i];
    }
    map<int,int> mp;
    for(int i=0;i<2*n;i++) {
        mp[arr[i]]++;
    }
    int ans=0;
    // alway in even because 2*n is even
    int oddFreq=0;
    for(auto &t:mp) {
        int x=t.first;
        int y=t.second;
        if(y&1) {
            ans++;
            oddFreq++;
        }
    }

    // count of element which freq is multiple of 4
    int cnt=0;
    for(auto &t:mp) {
        int x=t.first;
        int y=t.second;
        if(y&1^1) {
            if(y&2) {
                ans+=2;
            }
            else {
                cnt++;
            }
        }
    }
    if(oddFreq<2) {
        ans=ans+2*(cnt-cnt%2);
    }
    else {
        ans=ans+2*cnt;
    }
    cout<<ans<<endl;



    // unordered_map<int,int> mp;
    // f(i,0,2*n) {
    //     mp[arr[i]]++;
    // }
    // if(mp.size()==1) {
    //     if(n%2==1) {
    //         cout<<2<<endl;
    //     }
    //     else {
    //         cout<<0<<endl;
    //     }
    //     return;
    // }
    // int p=n,q=n;
    // int ans=0;
    // for(auto &x:mp) {
    //     if(x.second%2==1) {
    //         if(p<q) {
    //             p-=x.second;
    //             ans++;
    //         }
    //         else {
    //             q-=x.second;
    //             ans++;
    //         }
    //     }
    //     else {
    //         double f=x.second;
    //         int t1=ceil((f-1)/2);
    //         int t2=floor((f+1)/2);
    //         if(p<q) {
    //             p-=t2;
    //             q-=t1;
    //         }
    //         else {
    //             p-=t1;
    //             q-=t2;
    //         }
    //         ans+=2;
    //     }
    // }
    // cout<<p<<" "<<q<<endl;
    // cout<<ans<<endl;
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