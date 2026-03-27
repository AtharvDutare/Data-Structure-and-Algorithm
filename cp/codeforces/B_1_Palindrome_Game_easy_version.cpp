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

    both play optimally means 

    alice wants to spend money by bob
                and
    bob wants to spend money by alice 

    so they try to make string not a palindrome 
    so that other player cant use reverse operation


    how to check palindrome for each turns 
        Brute Force O(N)

    no by using pair 
        if a string S of length n which is initially palindrome

        if player make the i index bit 1 then i cant be palindrome 
        until n-i become 1 

        use a set we check isPalindrome in O(Log(N))
    

    to play optimally we select the index which tends to make the 
    string palindrome 
    
    we can further optimize by say that if the no of this bits which tends to make 
    string palindrome is odd the alice have to face cost when finally string become 
    palindrome so she choose the index apart from that bit 

*/

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<int> st;
    queue<int> zeroIndex;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            zeroIndex.push(i);
        }
    }
    if(n%2) {
        if(s[n/2]=='0') {
            st.insert(n/2);
        }
    }
    int count=0;
    bool turn=1;
    int alice=0;
    int bob=0;
    int prev=0;// 1 is reverse and 0 is not reverse 
    while((zeroIndex.size()-count)>0) {
        int cost=0;
        if((st.size()>0)&&(prev==0)) {
            prev=1;
            turn=!turn;
            continue;
        }
        else {
            if(st.size()==0) {
                while(zeroIndex.size()>0&&s[zeroIndex.front()]=='1') {
                    zeroIndex.pop();
                }
                if(zeroIndex.size()==0) {
                    continue;
                }
                else {
                    int p=zeroIndex.front();
                    zeroIndex.pop();
                    s[p]='1';
                    st.insert(n-1-p);
                }
            }
            else {
                //odd
                if(st.size()%2) {
                    int p=*st.begin();
                    st.erase(st.begin());
                    s[p]='1';
                    count++;
                }
                //even
                else {
                    //we have to find the index which is not in set but have bit 0
                    int t=1;
                    while(t==1&&zeroIndex.size()>0) {
                        while(zeroIndex.size()>0&&s[zeroIndex.front()]=='1') {
                            zeroIndex.pop();
                        }
                        if(zeroIndex.size()==0) {
                            break;
                        }
                        if(st.find(zeroIndex.front())==st.end()) {
                            t=0;
                            int p=zeroIndex.front();
                            zeroIndex.pop();
                            s[p]='1';
                            st.insert(n-1-p);
                        }
                        zeroIndex.pop();
                    }
                }
            }
           cost++;
           prev=0;

        }
        if(turn) {
            alice+=cost;
        }
        else {
            bob+=cost;
        }
        turn=!turn;
    }
    if(alice==bob) {
        cout<<"DRAW"<<endl;
        return;
    }
    else if(alice<bob) {
        cout<<"ALICE"<<endl;
        return;
    }
    else {
        cout<<"BOB"<<endl;
    }

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