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
const int MAXN = 2e5;
//store test cases here
/*


*/
int n;
int a[MAXN];
ll dp[MAXN];
vector<int> adj[MAXN];
void dfs(int v,int p){
	dp[v]=a[v];
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			dfs(adj[v][i],v);
			dp[v]^=dp[adj[v][i]];
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
    	cout<<dp[i]<<"\n";
    }
    return 0;
}

