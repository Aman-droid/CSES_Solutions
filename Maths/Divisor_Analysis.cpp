#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;
const int mod1=mod-1;
int inv(int x){
    return power(x,mod-2);
}

void solve(int T){
    int n;cin>>n;
    int x[n],k[n];
    int num=1,sum=1,prod=1,tmp=0;

    rep(i,0,n-1){
        cin>>x[i]>>k[i];
    }
    //number of divisors
    rep(i,0,n-1){
        num=(num*(k[i]+1))%mod;
    }
    //sum
    rep(i,0,n-1){
        tmp=(power(x[i],k[i]+1LL)-1LL+mod)%mod;
        tmp=(tmp*inv(x[i]-1LL))%mod;
        sum=(sum*tmp)%mod;
    }
    //prod 
    int num1=1;
    int fl=0;
    int div_prod=1;
    int div_cnt=1;
    rep(i,0,n-1){
        int val=power(x[i], (k[i] * (k[i] + 1) / 2));
        div_prod = power(div_prod, k[i] + 1) * power(val, div_cnt) % mod;
		div_cnt = div_cnt * (k[i] + 1) % (mod - 1);
    }

    cout<<num<<" "<<sum<<" "<<div_prod<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(T);
    }
    return 0;   
}