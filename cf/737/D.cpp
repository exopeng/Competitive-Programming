#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define ll long long
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 3e5;
//store test cases here
/*


*/
int n,m;
vector<pii> ts[MAXN];
int dp[MAXN];
int anc[MAXN];
void updateRange(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        tree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);

    // Use the result of children calls to update this node
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(i=0;i<m;i++){
        int rs,l,r;cin>>rs>>l>>r;
        ts[rs].pb(mp(l,r));
    }
    for(int i=n-1;i>-1;i--){
        int mn=INF;
        
        for(int j=0;j<ts[i].size();j++){
            mn=max(mn,ts[i][j].f,ts[i][j].s);
        }
        for(int j=0;j<ts[i].size();j++){
            if(mn>ts[i][j].f,ts[i][j].s){
                //update range
            }
        }

    }
    int as=0;
    int ix=0;
    for(int i=0;i<n;i++){
        if(dp[i]>as){
            as=dp[i];
            ix=i;
        }
    }
    cout<<n-as<<'\n';
    set<int> ts;
    ts.is(ix);
    while(anc[ix]!=-1){
        ts.is(anc[ix]);
        ix=anc[ix];
    }    
    for(int i=0;i<n;i++){
        if(ts.find(i)==ts.end()){
            cout<<(i+1)<<" ";
        }
    }
    cout<<'\n';
    return 0;
}

