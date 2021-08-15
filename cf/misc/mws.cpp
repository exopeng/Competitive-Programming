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
const int MAXN = 2e5+10;
//store test cases here
/*


*/
int n;
bool a[MAXN];
vector<int> adj[MAXN];
int dp[MAXN];
int as[MAXN];
void dfs(int v,int p){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
            if(dp[adj[v][i]]>=0){
                dp[v]+=dp[adj[v][i]];
            }
        }
    }
    if(a[v]){
        dp[v]++;
    }else{
        dp[v]--;
    }
}
void trs(int v,int p){
    int ls=dp[p];
    int lp=dp[v];
    if(dp[v]>=0){
        dp[p]-=dp[v];
    }
    if(dp[p]>=0){
        dp[v]+=dp[p];
    }
    as[v]=dp[v];
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            trs(adj[v][i],v);
        }
    }
    dp[p]=ls,dp[v]=lp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n; 
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,-1);
    as[1]=dp[1];
    /*
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<'\n';
    */
    for(int i=0;i<adj[1].size();i++){
        trs(adj[1][i],1);
    }
    for(int i=1;i<=n;i++){
        cout<<as[i]<<" ";
    }
    cout<<'\n';
    return 0;
}

