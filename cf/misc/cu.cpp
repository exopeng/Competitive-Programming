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
const int MAXN = 3e6;
//store test cases here
/*


*/
int n,k;
int bl[MAXN];
vector<int> adj[MAXN];
int dp1[MAXN];
ll sd[MAXN];
ll as=0;
void dfs(int v,int p){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
            dp1[v]+=dp1[adj[v][i]];
            sd[v]+=sd[adj[v][i]]+dp1[adj[v][i]];
        }
    }
    dp1[v]+=bl[v];
}
void dfs1(int v,int p){
    int c1=dp1[v];
    int c2=dp1[p];
    ll c3=sd[v];
    ll c4=sd[p];
    sd[p]-=sd[v]+dp1[v];
    dp1[p]-=dp1[v];
    dp1[v]+=dp1[p];
    sd[v]+=sd[p]+dp1[p];
    bool g=true;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs1(adj[v][i],v);
        }
        if(dp1[adj[v][i]]>k){
            g=false;
        }
    }
    if(g){
        as=max(as,sd[v]);
    }
    dp1[v]=c1,dp1[p]=c2,sd[v]=c3,sd[p]=c4;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<2*k;i++){
        int a;cin>>a;
        bl[a]=true;
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,-1);
    bool g=true;
    for(int i=0;i<adj[1].size();i++){
        dfs1(adj[1][i],1);
        if(dp1[adj[1][i]]>k){
            g=false;
        }
    }
    if(g){
        as=max(as,sd[1]);
    }
    cout<<as<<'\n';
    return 0;
}

