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

    INTIUTION
        base case 
            if all character of s in not t the "Impossible"
        
        lexo decrease if the string in which first is character is lexo
        largest the rest
        
        ba is lexo decrease
            so 
        dab is lexo decrease 
        


*/

void solve()
{
    string s,t;
    cin>>s;
    cin>>t;
    int m=s.length();
    int n=t.length();

    vector<int> freq(26,0);
    for(int i=0;i<n;i++) {
        freq[t[i]-'a']++;
    }
    for(int i=0;i<m;i++) {
        freq[s[i]-'a']--;
        if(freq[s[i]-'a']<0) {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    multimap<char,string> mp;
    int i=0;
    while(i<m-1) {
        if(i<m&&((s[i]-'a')>(s[i+1]-'a'))) {
            int j=i+1;
            while(j<m&&(s[i]-'a')>(s[j]-'a')) {
                j++;
            }
            mp.insert(pair<char,string>{s[i],s.substr(i,j-i)});
            i=j-1;
        }
        else {
            mp.insert(pair<char,string>{s[i],string(1,s[i])});
        }
        i++;
    }
    if(i==m-1) {
        mp.insert(pair<char,string>{s[i],string(1,s[i])});
    }
    
    // for(auto it = mp.begin(); it != mp.end(); ++it) {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    // cout<<"raewrta"<<endl;

    //freq.clear();
    vector<int> freq1(26,0);
    for(int i=0;i<n;i++) {
        freq1[t[i]-'a']++;
    }
    // cout<<freq1['e'-'a']<<endl;
    for(int i=0;i<m;i++) {
        freq1[s[i]-'a']--;
    }
    // cout<<freq1['e'-'a']<<endl;
    for(int i=0;i<n;i++) {
        if(freq1[t[i]-'a']>0) {
            mp.insert(pair<char,string>{t[i],string(1,t[i])});
        }
        freq1[t[i]-'a']--;
    }
    // for(auto it = mp.begin(); it != mp.end(); ++it) {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    string ans="";
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        //cout<<it->first<<" "<<it->second<<endl;
        ans+=it->second;
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