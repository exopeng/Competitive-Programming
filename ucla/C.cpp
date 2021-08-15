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
int n,m;
vector<int> adj[MAXN];
int cc[MAXN];
int ct=1;
bool on=false;

void dfs(int v){
    if(!cc[v]){
        on=true;
        cc[v]=ct;
        for(int i=0;i<adj[v].size();i++){
            dfs(adj[v][i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
        if(on){
            ct++;
        }
        on=false;
    }
    if(ct>2){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    cout<<"\n";
    return 0;
}

