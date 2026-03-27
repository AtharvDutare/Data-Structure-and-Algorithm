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


int mm(int i,vector<int>&arr,vector<int>ind[],vector<int>&m,vector<int>&dp) {
    if(i==arr.size()) {
        return 0;
    }
    if(dp[i]!=-1) {
        return dp[i];
    }
    int ans=mm(i+1,arr,ind,m,dp);
    int curr=arr[i];
    int at=m[i];
    if(curr-1+at<ind[curr].size()) {
        ans=max(ans,mm(ind[curr][curr+at-1]+1,arr,ind,m,dp)+arr[i]);
    }
    return dp[i]=ans;
}

void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }

    // it is a array of array which store the indices of same element in array 
    vector<int> ind[n+1];
    //for each index in arr it store the index in that ind 
    vector<int> m(n);
    vector<int> dp(n+1,-1);
    f(i,0,n) {
        ind[arr[i]].pb(i);
        m[i]=ind[arr[i]].size()-1;
    }
    int ans=mm(0,arr,ind,m,dp);
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