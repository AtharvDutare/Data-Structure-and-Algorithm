#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
template<typename... Args>
void printAll(Args... args) {
    ((std::cout << args << " "), ...) << std::endl;
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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;
//FIND_BY_ORDER(K)  --> VALUE AT KTH INDEX (ITERATOR)
//ORDER_OF_KEY(K)   --> INDEX OF VALUE K

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


/* 
    Problem Statement: 
    Observation: 
    we have to find the maximum prime number and in below we find the largest possible divisor
    Thoughts: 

        ll n;
        cin>>n;
        ll ans=1;
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0) {
                ans=max(ans,i);
                if(i!=(n/i)) ans=max(ans,n/i);
            }
        }
        if(ans==1) ans=n;
        cout<<ans<<endl;


        int n;
        cin>>n;
        int maxPrime=-1;
        if(n%2==0) {
            maxPrime=2;
            n/=2;
        }
        for(ll i=3;i<=sqrt(n);i+=2) {
            if(n%i==0) {
                maxPrime=i;
                n/=i;
            }
        }
        if(n>2) {
            maxPrime=n;
        }
        cout<<maxPrime<<endl;
*/

long largestPrimeFactor(long n) {
    // Step 1: Divide by 2 repeatedly if n is even
    while (n % 2 == 0) {
        n /= 2;
    }

    // Step 2: If n becomes 1, return 2 as the largest prime factor
    if (n == 1) {
        return 2;
    }

    // Step 3: Start with i=3 and check for divisibility by odd numbers
    long i = 3;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            n /= i;
        } else {
            i += 2;
        }
    }

    // Step 4: Return the largest prime factor
    return max(n, i);
}
void solve()
{
    int n;
    cin>>n;
    int maxPrime=-1;
    if(n%2==0) {
        maxPrime=2;
        n/=2;
    }
    for(ll i=3;i<=sqrt(n);i+=2) {
        if(n%i==0) {
            maxPrime=i;
            n/=i;
        }
    }
    if(n>2) {
        maxPrime=n;
    }
    cout<<maxPrime<<endl;
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