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
// 1. For most containers (Vector, Set, List)
template <typename T>
void print(const T& container) {
    std::cout << "[ ";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it;
        auto next_it = it;
        if (++next_it != container.end()) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

// 2. For Associative Containers (map, multimap, unordered_map)
template <typename K, typename V>
void print(const std::map<K, V>& m) {
    std::cout << "{ ";
    size_t count = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << ":" << it->second;
        if (++count < m.size()) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

// 3. Overload for Queues (Adapters)
template <typename T>
void print(std::queue<T> q) { 
    std::cout << "q[ ";
    while(!q.empty()){
        std::cout << q.front();
        q.pop();
        if(!q.empty()) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

//static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const int RD = rng() & ((1 << 31) - 1);

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

    x ,type 

    y,type 
    for 


*/

int lengthOfLis(vector<int> &arr) {
    int n=arr.size();
    vector<int> lis;
    for(int i=0;i<n;i++) {
        if(lis.empty()||arr[i]>lis.back()) {
            lis.pb(arr[i]);
        }
        else {
            auto it=lower_bound(all(lis),arr[i]);
            *it=arr[i];
        }
    }
    return (int)lis.size();
}


void solve()
{
    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        mp[y].pb(x);
    }
    for(auto&x:mp) {
        sort(x.second.rbegin(),x.second.rend());
        /*
            reason of why we sort in desending order

            lets say we have 3 value of south side

            25,3,4

            if we sort by increasing order
            3,4,25
            then for the calculation of 4 and 25 we take that
            as valid lis and create a bridge and then 
            lis is 
            3,4,25
            1,2,3
            which create problem


            if decreasing order 
            then 

            25,4,3
            then lis is 
            lis is 
            25,4,3
            1,1,1 
            then 
            how about that 25 isn't it create the problem 
            because of his value "NOOOOO"

            else {
            auto it=lower_bound(all(lis),arr[i]);
            *it=arr[i];
            }
            this code reduce the value as much as possible 
            by store the max lis of length 1 as {3,1}=={value ,length}
        
        
        */


    }
    sort(all(a));
    vector<int> seq;
    for(int i=0;i<n;i++) {
        int type=a[i].second;
        for(auto &x:(mp[type])) {
            seq.pb(x);
        }
    }
    cout<<lengthOfLis(seq)<<endl;


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}