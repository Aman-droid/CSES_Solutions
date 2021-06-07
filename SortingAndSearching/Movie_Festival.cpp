#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;
 
const int mxn=2e5;
 
void solve(){
    int n;cin>>n;
    pair<int,int>a[n]; //end start
 
    rep(i,0,n-1){
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int ans=0;int lst=0;
    rep(i,0,n-1){
        if(a[i].second >= lst){
            ans++;
            lst=a[i].first;
        }
    }
    cout<<ans<<endl;
}
 
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}