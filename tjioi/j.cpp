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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 6e5;
//store test cases here
/*


*/
int n;
vector<int> adj[MAXN];
int cd[MAXN];
ll dp[MAXN];
ll as=INF;
void dfs(int v,int p){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
            cd[v]+=cd[adj[v][i]]+1;
            if(dp[adj[v][i]]!=0){
                for(int j=0;j<adj[adj[v][i]].size();j++){
                    dp[v]+=dp[adj[adj[v][i]][j]]+1;
                }
            }else{
                dp[v]+=cd[adj[v][i]];
            }
        }
    }
}
void dfs1(int v,int p){
    ll pr=dp[v];
    ll pp=dp[p];
    ll cr=cd[v];
    ll cp=cd[p];
    dp[p]-=dp[v]+cd[v];
    cd[p]-=cd[v]+1;
    cd[v]+=cd[p]+1;
    dp[v]+=dp[p]+cd[p];
    as=min(as,dp[v]);
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs1(adj[v][i],v);
        }
    }
    dp[v]=pr,dp[p]=pp,cd[v]=cr,cd[p]=cp;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs(1,-1);
    as=min(as,dp[1]);
    for(int i=0;i<adj[1].size();i++){
        dfs(adj[1][i],1);
    }
    cout<<as<<"\n";
    return 0;
}

