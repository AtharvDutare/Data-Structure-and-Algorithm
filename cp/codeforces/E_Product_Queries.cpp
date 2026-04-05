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

    what is question exactly???


    for each index from 1 to n
    if it is possible to make product of element into i with min element then yes 
    else -1


    dp???

    dp[n]
    //we had a mapping of element 
    for(int i=1;i<=n;i++) {
        for(int j=1;j*j<=i;i++) {
            int t=0
            int k=i;
            while(k%j==0) {
                k/=j;
                t++;
            }   
            dp[i]=min(dp[i],t+dp[k]);
        }
    }
    for(int i=1;i<=n;i++) {
        if(dp[i]==INT_MAX) {
            cout<<-1<<" ";
        }
        else {
            cout<<dp[i]<<" ";l
        }
    }cout<<endl;



*/

void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    f(i,0,n) cin>>arr[i];
    sort(all(arr));
    vector<int> dp(n+1,1e9);
    for(int i=0;i<n;i++) {
        dp[arr[i]]=1;
    }
    dp[1]=0;
    for(int i=1;i<=n;i++) {
        if(dp[i]==1e9) continue;

        for(auto &x:arr) {
            if(1LL*x*i<=n) {
                dp[x*i]=min(dp[x*i],dp[i]+1);
            }
            else {
                break;
            }
        }
    }
    dp[1]=-1;
    for(int i=0;i<n;i++) {
        if(arr[i]==1) {
            dp[1]=1;
            break;
        }
    }
    for(int i=1;i<=n;i++) {
        if(dp[i]==1e9) {
            cout<<-1<<" ";
        }
        else
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
void solve1() {
    int n;
    cin>>n;
    vi dp(n+1,1e9);
    f(i,0,n) {
        int x;
        cin>>x;
        dp[x]=1;
    }
    // print(dp);
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            dp[j]=min(dp[j],dp[i]+dp[j/i]);

            /* 

                it is a pull dp 

                j=i*(j/i)
            


            
            */
        }
        // print(dp);
    }
    for(int i=1;i<=n;i++) {
        if(dp[i]==1e9) {
            cout<<-1<<" ";
        }
        else {
            cout<<dp[i]<<" ";
        }
    }cout<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--){
        solve1();
    }
    return 0;
}