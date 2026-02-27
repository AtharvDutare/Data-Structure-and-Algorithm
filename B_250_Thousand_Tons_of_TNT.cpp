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

vector<long long> getAllDivisors(long long n) {
    vector<long long> divisors;
    
    // Iterate to the square root of n
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i); // The smaller divisor
            
            // If the divisors are different, add the larger one
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    
    // Optional: Sort them for clear output
    sort(divisors.begin(), divisors.end());
    return divisors;
}
ll solve(vll &arr,int k) {
    int n=arr.size();
    ll ans1=LLONG_MIN;
    ll ans2=LLONG_MAX;
    for(int i=0;i<n;i+=k) {
        ll tempAns=0;
        int j;
        for(j=0;j<k;j++) {
            tempAns+=arr[j+i];
        }
        // if(tempAns==0) {
        //     cout<<i<<" "<<j<<endl;
        //     assert("error");
        // }
        ans1=max(tempAns,ans1);
        ans2=min(tempAns,ans2);
    }
   // cout<<k<<" "<<ans1<<" "<<ans2<<endl;
    return ans1-ans2;
}

void solve()
{
    int n;
    cin>>n;
    vll arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    //sort(all(arr));
    vector<ll> d=getAllDivisors(n);
    ll ans=0;
    //print_v(d);
    // ll s=0;
    // ll e=d.size()-1;
    // while(s<=e) {
    //     ll mid=(e-s)/2+s;
    //     ll tempAns=solve(arr,d[mid]);
    //     if(ans<=tempAns) {
    //         s=mid+1;
            
    //     }
    //     else {
    //         e=mid-1;
    //     }
    //     cout<<tempAns<<endl;
    //     ans=max(ans,tempAns);
    // }

    for(int i=0;i<d.size();i++) {
        ll tempAns=solve(arr,d[i]);
        //cout<<tempAns<<endl;
        ans=max(ans,tempAns);
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