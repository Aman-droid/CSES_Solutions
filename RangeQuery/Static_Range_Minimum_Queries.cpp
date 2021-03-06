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
const int mxn=2e5;
//node=segment tree index.

ll tree[4*mxn] , A[mxn];

void build(int node, int start, int end)
{
    if(start == end){
        //tree[si]=arr[ss];//here leaf node directly correspond element start=end=idx in the real array..
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node] , tree[2*node+1]);
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end){
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else{
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node] ,tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        // range represented by a node is completely outside the given range
        return INF;
    }
    if(l <= start && end <= r){
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

signed main(){
    ll n , q , l , r;
    cin>>n>>q;

    rep(i,1, n)cin>>A[i];
    build(1 , 1 , n);

    while(q--){
        cin>>l>>r;
        cout<<query(1 , 1 , n , l , r)<<endl; 
    }
}