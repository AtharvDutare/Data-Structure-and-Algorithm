#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD=1e9+7;

ll power(int a,int b){
    //log(b)
    if(!b){
        return 1;
    }
    //a%=MOD;
    ll half_power=power(a,b/2);
    if(b%2==0){
        return( half_power*half_power)%MOD;
    }
    return ((half_power*half_power)%MOD*a%MOD)%MOD;
}
// a^b
long long power_iter(long long a,long long b) {
    long long res=1;
    while(b>0) {
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
static int i=0;
vector<ll> fact,invfac;
ll ncr(ll n,ll r){
    if(r>n||n<0||r<0){
        return 0;
    }

    ll nr=fact[n];
    ll dr=(invfac[r]*invfac[n-r])%MOD;
    return (nr*dr)%MOD;
}
void preCompute(ll n) {
    if(i==0) {
        fact.assign(n+1,1);
        invfac.assign(n+1,1);
        i=1;
    }
    for(ll i=2;i<=n;i++) {
        fact[i]=(i*fact[i-1])%MOD;
    }
    invfac[n]=power(fact[n],MOD-2);
    for(ll i=n-1;i>0;i--) {
        invfac[i]=(invfac[i+1]*(i+1))%MOD;
    }
}
/*
    fact.assign(1001,1);
    invfac.assign(1002,1);
    preCompute(1000);

*/