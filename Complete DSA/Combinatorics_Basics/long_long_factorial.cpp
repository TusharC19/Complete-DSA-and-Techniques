#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
typedef long long ll;

// -------------------------------------------          Write your solution         -------------------------------------------------------------------------------//



ll powMOD(ll x,ll n){
    ll ans=1;
    x%=M;

    while(n>0){
        if(n&1) ans=(ans*x)%M;
        x=(x*x)%M;
        n>>=1;
    }
    return ans;
}

// FermetTheorem
ll modInverse(ll a){
    return powMOD(a,M-2);
    // M must be prime  
    // Fermat’s theorem only works when the modulus is prime (like 1e9+7
    // , which is the standard contest modulus).
    // a must not be divisible by M
    // If 𝑎≡0(mod𝑀), then no inverse exists (because 𝑎.𝑥≡0,
    //     can never equal 1).
}

vector<ll> compute(ll n){
    vector<ll>f(n+1,1);
    for(int i=1;i<=n;i++){
        f[i]=(1LL*i*f[i-1])%M;
    }
    return f;
}

vector<ll>compute2(ll n,vector<ll>&fact){
    // invefact Arr
    vector<ll>v(n+1,1);
    // compute invfact[N] first
    v[n]=powMOD(fact[n],M-2);

    // compute all other n-1,n-2,n-3.....so on
    for(int i=n-1;i>=0;i--){
        v[i]=(1LL*v[i+1]*(i+1))%M;
    }

    // return invfact Arr
    return v;

}

ll findnCr(int n,int r,vector<ll>&fact,vector<ll>&invfact){
    ll ans = fact[n];
    ans = (ans * invfact[n-r]) % M;
    ans = (ans * invfact[r]) % M;

    return ans;
}

int main(){

    int N=1e5;
    auto fact = compute(N);
    auto invfact = compute2(N,fact);

    int n=8,r=4;
    ll nCr = findnCr(n,r,fact,invfact);

    cout<<nCr<<endl;
    
    // 🔹 Example
    // How many distinct permutations of the word “BALLOON”?
    // Total letters: n=7
    // Repetitions: L appears 2 times, O appears 2 times


    

    return 0;
}
