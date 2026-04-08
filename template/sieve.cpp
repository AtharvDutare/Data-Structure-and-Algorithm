#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> sieve(ll lm) {
    //O(NloglogN)
    //assume all are prime
    vector<bool> is_prime(lm + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i=2;i*i<=lm;i+=1) {
        if(is_prime[i]){
            for (ll j=i*i;j<=lm;j+=i) {
                is_prime[j] = false;
            }
        }
    }   
    vector<ll> primes;
    for (ll i=2;i<=lm;i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

vector<ll> divisor(int n) {
    vector<ll> divor;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            divor.push_back(i);
        }
        if(i!=(n/i)) {
            divor.push_back(n/i);
        }
    }
    return divor;
}


long long countDivisor(int n) {
    long long ans=1;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            int cnt=0;
            while(n>0&&(n%i==0)) n/=i,cnt++;
            ans+=(cnt+1);
        }
    }
    if(ans>1) ans=2;
    return ans;
}

long long sumOfDivisor(long long n) {
    ll ans=1;
    ll div=1;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            int cnt=0;
            while(n>1&&(n%i==0)) n/=i,cnt++;
            ans*=(pow(i,cnt+1)-1);
            div*=(i-1);
        }
    }
    if(n>1) ans*=(1+n);
    return (ll)ans/div;
}

//precompute divisors for number [1,N]

/*
    vector<vector<int>> divor(N+1,vector<int>());

    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i) {
            divor[j].push_back(i);
        }
    }

    P(N*(log(N)))


*/