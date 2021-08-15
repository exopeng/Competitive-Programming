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
const int MAXN = 5e5;
//store test cases here
/*


*/
int n,m;
vector<int> adj[MAXN];
ll dp[MAXN];
vector<ll> rs;
void dfs(int v,int p){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
            dp[v]+=dp[adj[v][i]];
        }
    }
    dp[v]++;
    //cout<<v<<" "<<dp[v]<<'\n';
}
void dfs1(int v,int p){
    int v1=dp[v];
    int v2=dp[p];
    dp[p]-=dp[v];
    rs.pb((dp[p]*dp[v]));
    //cout<<rs[rs.size()-1]<<" ";

    dp[v]+=dp[p];
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs1(adj[v][i],v);
        }
    }
    dp[v]=v1,dp[p]=v2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n-1;j++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b),adj[b].pb(a);
        }
        dfs(1,-1);
        for(int j=0;j<adj[1].size();j++){
            dfs1(adj[1][j],1);
        }
        sort(rs.begin(),rs.end());
        cin>>m;
        vector<ll> ps;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            ps.pb(a);
        }
        while(ps.size()<n-1){
            ps.pb(1);
        }
        sort(ps.begin(),ps.end());
        while(ps.size()>n-1){
            ll a=ps[ps.size()-1];
            ll b=ps[ps.size()-2];
            ps.pop_back(),ps.pop_back();
            ps.pb((a*b)%MOD);
        }
        ll as=0;
        for(int j=0;j<n-1;j++){
            rs[j]%=MOD;
            as=(as+rs[j]*ps[j])%MOD;
        }
        cout<<as<<'\n';
        for(int j=1;j<=n;j++){
            adj[j].clear();
            dp[j]=0;
        }
        rs.clear();
    }
    return 0;
}

