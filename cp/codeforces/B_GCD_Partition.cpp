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


    BRUTE FORCE SOLUTON
        find the total divisors of n 
            ONE BY ONE CHECK 
                ans=max(ans,gcd);
        O(n*sqrt(n))
            IT SAY K SEGMENT NOT EQUAL SUBARRAY 



        RIGHT INTIUTION

        LETS SAY WE have K segment 
        so....
        gcd(b1,b2,...bk)<=gcd(b1+b2,b3+b4,...bk-1+bk)
        why????
            let say for k segment gcd is w
            then for all segment it is w 
                FORM B1+B2 IS W*(Y1+Y2) 
                SO ATMOST GCD IS W it can increasce by y1+y2 maybe or
                maybe not 



*/

// vector<long long> getAllDivisors(long long n) {
//     vector<long long> divisors;
//     //divisors.pb(1);
//     for(long long i=1;i*i<=n;i++){
//         if(n%i==0){
//             divisors.push_back(i);
//             if(i*i!=n){
//                 divisors.push_back(n/i);
//             }
//         }
//     }
//     sort(divisors.begin(),divisors.end());
//     return divisors;
// }

void solve()
{
    ll n;
    cin>>n;
    vll arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll sum=accumulate(all(arr),0LL);
    ll ans=0;
    ll pre=0;
    for(int i=0;i<n-1;i++) {
        pre+=arr[i];
        ans=max(ans,gcd(pre,sum-pre));
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