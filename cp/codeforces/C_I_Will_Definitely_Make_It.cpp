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


// 1. For most containers (Vector, Set, List)
template <typename T>
void print(const T& container) {
    cout << "[ ";
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it;
        auto next_it = it;
        if (++next_it != container.end()) cout << ", ";
    }
    cout << " ]" << endl;
}

// 2. Overload for Maps (Old Syntax)
template <typename K, typename V>
void print(const map<K, V>& m) {
    cout << "{ ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ":" << it->second;
        auto next_it = it;
        if (++next_it != m.end()) cout << ", ";
    }
    cout << " }" << endl;
}

// 3. Overload for Queues (Adapters)
template <typename T>
void print(queue<T> q) { 
    cout << "q[ ";
    while(!q.empty()){
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << " ]" << endl;
}

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int RD = rng() & ((1 << 31) - 1);

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
    vll arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    k--;
    ll curr=arr[k];
    ll time=0;
    ll level=1;
    sort(all(arr));
    for(ll i=0;i<n;i++) {
        if(arr[i]<curr) continue;
        if(curr<level+(arr[i]-curr)-1) {
            no();
            return;
        }
        level+=(arr[i]-curr);
        curr=arr[i];
    }
    yes();
 

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