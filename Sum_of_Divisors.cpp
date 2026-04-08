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
const ll MOD = 1000000007;
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
    Thoughts: 
*/

// long long sumOfDivisor(long long n) {
//     ll ans=1;
//     ll div=1;
//     for(ll i=2;i*i<=n;i++) {
//         if(n%i==0) {
//             ll cnt=0;
//             while(n>1&&(n%i==0)) n/=i,cnt++;
//             ans*=(pow(i,cnt+1)-1);
//             div*=(i-1);
//         }
//     }
//     if(n>1) ans*=(1+n);
//     return (ll)ans/div;
// }

// long long sod(long long n) {
//     ll sum=0;
//     for(int i=1;i<=n;i++) {
//         sum=(sum+((n/i)*i)%MOD)%MOD;
//     }
//     return sum%MOD;
// }

ll range_sum(ll &a,ll &b) {
    /*
        range is AP with commom difference =1
        Sn=(n)*(a+l)/2;
    */
    ll range=(b-a+1)%MOD;
    ll sum=(a+b)%MOD;
    ll ans=(range*sum)%MOD;
    if(ans%2==0) {
        ans/=2;
    }
    else {
        ans=((ans+MOD)/2);
    }
    return ans%MOD;
}



ll sumOfDivisors(ll n) {
    ll ans=0;
    ll d=1;
    while(d<=n) {
        ll q=n/d; // it count the no of divisor the does this number have from range 
        /*
            for example n=17
            
            [1,17]
            if ele = 4
            n/ele  17/4 =4
            means the from range 1 to 17 we have 4 number which have the divisor of 4 

            4->[1,4],8->[1,2,4,8],12->[1,2,3,4,6,12],16->[1,2,3,4,6,8,16]

            and then 
        
        */
       ll r=n/q;
       /*
            we doe n/q --->> 17/4
            this show the last number/divisor which have the same frequency of within the range 

            i take the other example for that
            lets say n=14 and d=5
            means q=n/d is 2
            and r=n/q is 7
            means from d to r we have this element which have same frequency within the range 
            divisor 5 has 5,10
            divisor 6 has 6,12
            divisor 5 has 7,14

            so we sum the range and multiple by frequency which is q 
            
            then
       */
        ll rangeSum=range_sum(d,r);
        ans = (ans + (rangeSum % MOD) * (q % MOD) % MOD) % MOD;

      
      /*
        in just above example we see we calculate the divisor upto 7 
        we do for next divisor which is 8/7+1(r+1)

        some question why i<=n not i*i<=n because atmost for n we have largest factor upto 
        n/2 

        NO here we just dont sum for specific n. we are doing it for all so 
        their is number we which is greater than n/2 we need to calculate for those
      
      */
     d=r+1;
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    cout<<sumOfDivisors(n)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    //cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}