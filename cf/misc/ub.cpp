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
const int MAXN = 2e5+1;
//store test cases here
/*


*/
int n,m;
int p[MAXN];
int h[MAXN];
int ns[MAXN];
int x[MAXN];
int y[MAXN];
vector<int> adj[MAXN];
bool g=true;
void dfs(int v,int ps){
    ns[v]=0;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=ps){
            dfs(adj[v][i],v);
            ns[v]+=ns[adj[v][i]];
        }
    }
    ns[v]+=p[v];
}
void dfs1(int v,int ps){
    x[v]=(h[v]+ns[v])/2;
    y[v]=(ns[v]-h[v])/2;
    if((h[v]+ns[v])%2||(ns[v]-h[v])%2||
        x[v]<0||y[v]<0){
        g=false;
        return;
    }
    int totx=0;
    int toty=0;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=ps){
            dfs1(adj[v][i],v);
            totx+=x[adj[v][i]];
            toty+=y[adj[v][i]];
        }
    }
    if(totx>x[v]||toty<y[v]-p[v]||totx+toty!=ns[v]-p[v]){
        g=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        g=true;
        for(int j=1;j<=n;j++){
            cin>>p[j];
        }
        for(int j=1;j<=n;j++){
            cin>>h[j];
            adj[j].clear();
        }
        for(int j=1;j<n;j++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b),adj[b].pb(a);
        }
        dfs(1,-1);
        dfs1(1,-1);
        if(ns[1]!=m){
            g=false;
        }
        if(g){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}

