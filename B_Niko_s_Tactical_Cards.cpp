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

    r is red
    b is blue

If she chooses the red card, her score becomes k−ai, where k is her score before the turn.
If she chooses the blue card, her score becomes bi−k, where k is her score before the turn.

*/

// int mm(vll &r,vll &b,int index,bool turn) {
//     if(index<0) {
//         return 0;
//     }
//     int t1=0;
//     int t2=0;
//     if(turn){
//         t1=mm(r,b,index-1,!turn)-r[index];
//         t2=mm(r,b,index-1,turn)-r[index];
//     }
//     else {
//         t1=b[index]-mm(r,b,index-1,!turn);
//         t2=b[index]-mm(r,b,index-1,turn);
//     }
//     return max(t1,t2);
// }

// void solve()
// {
//     ll n;
//     cin>>n;
//     vll r(n),b(n);
//     for(int i=0;i<n;i++) {
//         cin>>r[i];
//     }
//     for(int i=0;i<n;i++) {
//         cin>>b[i];
//     }
//     cout<<max(mm(r,b,n-1,0),mm(r,b,n-1,1))<<endl;
// }
void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // dpMax[i] = max score after turn i
    // dpMin[i] = min score after turn i
    // Initial score is 0 before turn 0
    ll curMax = 0;
    ll curMin = 0;

    for (int i = 0; i < n; i++) {
        // Option 1: Choose Red (Score = k - a[i])
        ll redMax = curMax - a[i];
        ll redMin = curMin - a[i];

        // Option 2: Choose Blue (Score = b[i] - k)
        ll blueMax = b[i] - curMin;
        ll blueMin = b[i] - curMax;

        // Update current Max and Min for the next turn
        curMax = max({redMax, redMin, blueMax, blueMin});
        curMin = min({redMax, redMin, blueMax, blueMin});
    }

    cout << curMax << "\n";
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