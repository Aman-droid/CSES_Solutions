#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

 
int inv(ll x){
    return power(x, mod - 2);
}
 
int sum(int n){
    // sum 1 to n = (n*(n+1))/2
    ll res = ((((n % mod) * ((n + 1) %mod)) % mod) * inv(2)) % mod;
    return res;
}
 
int divisorSum(ll n){
    int l = 1;
    int ans = 0;
 
    while (l <= n){
        int k = n / l;
        int r = n / k;

        k %= mod;
         
        // For i=l to i=r, floor(n/i) will be k
        ans += (((sum(r) - sum(l - 1)+ mod ) %mod) * k) % mod;
        
        ans %= mod;

        l = r + 1;
    }

    ans = (ans+mod) % mod;
    return ans;
}

void solve(){
    int n;cin>>n;
    cout<<divisorSum(n)<<endl;
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}