
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
const int mxn=1e6+5;
int G[mxn+1],cnt[mxn+1];

void solve(){
    int n,x;cin>>n;
    int a[n];
    rep(i,0,n-1){
        cin>>x;
        cnt[x]++;
    }
    int div_cnt=0;
    for(int i=mxn;i>=1;i--){
        div_cnt=0;
        for(int j=i;j<=mxn;j+=i){
            div_cnt+=cnt[j];            
        }
        if(div_cnt>=2){
            cout<<i<<endl;
            return;
        }
    }


}
signed main() {
    FIO;
    //pre();
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
