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

    INTUITION
    



*/

void solve()
{
    string s;
    cin>>s;
    int n=s.length();      
	// Initialize a DP table with dimensions (n+1) x 4, filled with zeros
	// dp[i][0] - Tracks the number of subsequences ending at i that can start a 'wow'
	// dp[i][1] - Tracks subsequences that have formed 'w'
	// dp[i][2] - Tracks subsequences that have formed 'wo'
	// dp[i][3] - Tracks subsequences that have formed 'wow'
	vector<vector<int>> dp(n + 1, vector<int>(4, 0));

	// Initialize the base case: every position can start a new subsequence
	for (int i = 0; i <= n; i++) { // O(n)
		dp[i][0] = 1;
	}

	// Iterate over the string to fill the DP table
	for (int i = 1; i < n; i++) { // O(n)
		if (s[i] == 'v' && s[i - 1] == 'v') {
			// If we find 'vv', it can be considered as 'w'
			dp[i + 1][1] += dp[i - 1][0]; // Transition to 'w'
			dp[i + 1][3] += dp[i - 1][2]; // Transition to 'wow'
		} else if (s[i] == 'o') {
			// If we find 'o', it can continue a 'wo' subsequence
			dp[i + 1][2] += dp[i][1]; // Transition to 'wo'
		}
		// Carry forward the counts for each state
		dp[i + 1][1] += dp[i][1];
		dp[i + 1][2] += dp[i][2];
		dp[i + 1][3] += dp[i][3];
	}

	// Output the total number of 'wow' subsequences
	cout << dp[n][3] << endl;
    for(int i=0;i<=n;i++) {
        print(dp[i]);
    }
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