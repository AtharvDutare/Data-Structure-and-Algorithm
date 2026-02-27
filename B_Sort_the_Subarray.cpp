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
    if i and j are answer then all the element between i and j in b is sorted
    and the all element present in same range of a 

    try 
    first find the pivot index and 
    then  b1,b2,b3|bi,....bj|bj+1...bn
    for each a1 find the element in the range of i and j 
            if find then ok
            else go to next pivot
        if reach the end of range 
            if current_range>previous_range
                ansi=i;
                ansj=j;

    WRONG APPROACH  IT IS USE TO FIND THE
        code looks for the longest segment in array b
        that could be a sorted version of the same segment in a.

        IT MAY BE POSSIBLE THAT THE PREVIOUS SPLIT OF B IS SORTED BY NATURE 
        NOT MY OPERATION AND GREATER THAN THE OPERATION RANGE THEN MY 
        CODE SELECT THAT RANGE NOT THE OPERATINO RANGE 

*/

// bool found(vll &arr,int s,int e,int ele) {
//     while(s<=e) {
//         int mid=(e-s)/2+s;
//         if(arr[mid]==ele) {
//             return true;
//         }
//         else if(arr[mid]<ele) {
//             s=mid+1;
//         }
//         else {
//             e=mid-1;
//         }
//     }
//     return false;
// }

// void solve()
// {
//     ll n;
//     cin>>n;
//     vll a(n),b(n);
//     for(int i=0;i<n;i++) {
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++) {
//         cin>>b[i];
//     }
//     vector<int> piv;
//     piv.pb(0);
//     for(int i=1;i<n;i++) {
//         if(b[i-1]>b[i]) {
//             piv.pb(i);
//         }
//     }
//     piv.pb(n);
//     //print_v(piv);
//     int ansi=-1;
//     int ansj=-1;
//     for(int i=0;i<piv.size()-1;i++) {
//         int p=piv[i];
//         int q=piv[i+1]-1;
//         bool itCan=true;
//         for(int j=p;j<=q;j++) {
//             if(!found(b,p,q,a[j])) {
//                 itCan=false;
//                 break;
//             }
//         }
//         if(itCan) {
//             //cout<<p<<" "<<q<<endl;
//             if(abs(q-p)>abs(ansj-ansi)) {
//                 ansi=p;
//                 ansj=q;
//             }
//         }

//     }
//     cout<<ansi+1<<" "<<ansj+1<<endl;
// }

void solve() {
    ll n;
    cin>>n;
    vll a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    int firstDiff=-1;
    int lastDiff=-1;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i]) {
            if(firstDiff==-1) firstDiff=i;
            lastDiff=i;
        }
    }
    while((firstDiff>0)&&(b[firstDiff]>=b[firstDiff-1])) {
        firstDiff--;
    }
    while((lastDiff<n-1)&&(b[lastDiff]<=b[lastDiff+1])) {
        lastDiff++;
    }
    cout<<firstDiff+1<<" "<<lastDiff+1<<endl;
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