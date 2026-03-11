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
    map<ll,ll> mp;
    f(i,0,n) {
        int x;
        cin>>x;
        mp[x%k]++;
        mp[k-x%k]++;
    }
    f(i,0,n) {
        int x;
        cin>>x;
        mp[x%k]--;
        mp[k-x%k]--;
    }

    for(auto &it:mp) {
        if(it.second){
            no();
            return;
        }
    }
    yes();



    // multiset<ll> m;
    // for(auto &x:s) {
    //     if(t.find(x)!=t.end()) {
    //         t.erase(t.find(x));
    //     }
    //     else {
    //         m.insert(x);
    //     }
    // }
    // cout<<m.size()<<" "<<t.size()<<endl;
    // if(t.size()==0) {
    //     yes();
    //     return;
    // }
    // int minRange=*t.begin();
    // int maxRange=*prev(t.end());
    // cout<<minRange<<" "<<maxRange<<endl;
    // for(auto &x:m) {
    //     int t1=x;
    //     int t2=x;
    //     bool isFind=false;
    //     while(t2<=maxRange) {
    //         if(t.find(t2)!=t.end()) {
    //             t.erase(t.find(t2));
    //             isFind=true;
    //             break;
    //         }
    //         t2+=k;
    //     }
    //     if(isFind) {
    //         continue;
    //     }
    //     while(t1>=minRange) {
    //         if(t.find(t1)!=t.end()) {
    //             t.erase(t.find(t1));
    //             isFind=true;
    //             break;
    //         }
    //         //cout<<t1<<endl;
    //         t1=abs(t1-k);
    //     }
    //     if(isFind==false) {
    //         no();
    //         return;
    //     }
    // }
    // if(t.size()==0) {
    //     yes();
    // }
    // else {
    //     no();
    // }
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