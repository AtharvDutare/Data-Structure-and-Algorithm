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

/* clang-format on

    INITUTION 


    range of no of partition is [2,max freq of any element]

            Note that after partitioning the array,
            you do not change the order of the segments. 
    Also, note that if an element appears several times in some segment bj
            , it only needs to appear at least once in bj+1.

            HOW TO USE THIS LINE ?????

            means the segment of equal size is not a constraint
            means size of each segment can be different 


    BRUTE FORCE

    ANS=2
    FOR I IN RANGE [2,max freq of any element,-1] 
        CHECK IF VALID ANS =I
            WRONG ->> means the segment of equal size is not a constraint
            means size of each segment can be different 
        BREAK;


*/

// vector<long long> getAllDivisors(long long n) {
//     vector<long long> divisors;
//     for (long long i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             divisors.push_back(i);
//             if (i * i != n) {
//                 divisors.push_back(n / i);
//             }
//         }
//     }
//     sort(divisors.begin(), divisors.end());
//     return divisors;
// }

// bool isValid(vll &arr,int win) {
//     int n=arr.size();
//     vector<int> mp(n+1,0);
//     for(int i=0;i<win;i++) {
//         mp[arr[i]]++;
//     }
//     int i=win;
//     while(i<n) {
//         int j=0;
//         while(j<win) {
//             if(mp[arr[i+j]]==0) {
//                 return false;
//             }
//             j++;
//         }
//         i=j;
//     }
//     return true;
// }

void solve()
{
    ll n;
    cin>>n;
    vll arr(n);
    
    f(i,0,n) {
        cin>>arr[i];
    }
    set<ll> prev,total;
    ll ans=0;
    for(ll i=0;i<n;i++) {
        total.insert(arr[i]);
        if(prev.count(arr[i])) {
            prev.erase(arr[i]);
        }
        if(prev.size()==0) {
            ans++;
            prev=total;
        }
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