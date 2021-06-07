#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(), (c).end()

using namespace std;


const int mxn = 2e3;
void solve(){
    int n, q;cin >> n >> q;
    char c;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<vector<int>>mat(n+1,vector<int>(n+1,0));
    rep(i,1,n){
        rep(j,1,n){
            cin>>c;
            if(c=='*')mat[i][j]=1;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = mat[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    int ans=0;
    int r1,c1,r2,c2;
    rep(i,1,q){
        cin>>r1>>c1>>r2>>c2;
        ans= dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
        cout<<ans<<endl;
    }

    
}
signed main()
{
    FIO;
    int T = 1;//cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
