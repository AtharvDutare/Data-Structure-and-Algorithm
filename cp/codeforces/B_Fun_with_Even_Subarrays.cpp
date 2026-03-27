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
    cin >> n;
    vll arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll gcd1 = arr[0];
    ll gcd2 = arr[1];
    for (ll i = 2; i < n; i += 2)
    {
        gcd1 = gcd(arr[i], gcd1);
    }
    for (ll i = 3; i < n; i += 2)
    {
        gcd2 = gcd(arr[i], gcd2);
    }

    bool flag = true;
    for (ll i = 1; i < n; i += 2)
    { // Check if gcd1 can be a valid d
        if (arr[i] % gcd1 == 0)
        { // If any odd indexed element is divisible by gcd1
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << gcd1 << endl; // gcd1 is a valid d
        return;
    }

    flag = true;
    for (ll i = 0; i < n; i += 2)
    { // Check if gcd2 can be a valid d
        if (arr[i] % gcd2 == 0)
        { // If any even indexed element is divisible by gcd2
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << gcd2 << endl; // gcd2 is a valid d
    }
    else
    {
        cout << 0 << endl; // No valid d found
    }

    // cout<<max(gcd1,gcd2)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}