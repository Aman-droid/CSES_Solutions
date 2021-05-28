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


//LAZY update when only needed otherwise keep a note
const int mxn=2e5;
ll tree[4*mxn] ,lazy[4*mxn],A[mxn];

void build(int node, int start, int end){
    if(start == end){
        tree[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0){ 
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end){
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }

    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r){
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end){
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r){
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    
	if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }

    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

 
signed main()
{
	int n , q ,code,k, l , r , val;
	cin>>n>>q;
    rep(i,1,n)cin>>A[i];
    //watch(n);

	build(1 , 1 , n);
    int ans=0;
	while(q--){
		cin>>code;
		if(code == 2){
			cin>>k;
			ans=queryRange(1 , 1 , n , 1 , k);
            
            if(k!=1)
                ans=ans-queryRange(1 , 1 , n , 1 , k-1);
            
            cout<<ans<<endl;
		}
		else{
			cin>>l>>r>>val;
			updateRange(1 , 1 , n , l , r , val);
		}
	}
}
 