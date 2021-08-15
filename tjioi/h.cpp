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
int n,m;
vector<int> adj[MAXN];
int d[MAXN];
int dl[MAXN];
void dfs(int v, int p){
    d[v]=d[p]+1;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
            dl[v]+=dl[adj[v][i]]+1;
        }
    }
    if(adj[v].size()==1&&v!=1){
        dl[v]=0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    d[1]=-1;
    dfs(1,1);
    multiset<int,greater<int>> ts;
    for(int i=1;i<=n;i++){
        ts.is(d[i]-dl[i]);
    }
    ll as=0;
    for(int i=0;i<m;i++){
         as+=*ts.begin();
         ts.erase(ts.begin());
    }
    cout<<as<<"\n";
    return 0;
}

