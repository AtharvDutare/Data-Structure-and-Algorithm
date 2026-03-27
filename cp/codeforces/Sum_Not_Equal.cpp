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

/* clang-format on */

void solve()
{
     ll n;
    cin>>n;
    vector<pii> arr(n);
    f(i,0,n) {
        int x;
        cin>>x;
        arr[i]={x,i};
    }
    sort(all(arr));
    for(int i=1;i<n-1;i++) {
        if((arr[0].first+arr[n-1].first)!=arr[i].first) {
            cout<<arr[0].second+1<<" "<<arr[n-1].second+1<<" "<<arr[i].second+1<<endl;
            return;
        }
    }
   cout<<-1<<endl;
    
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