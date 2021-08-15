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
vector<int> k[MAXN];
vector<int> adj[MAXN];
set<int> csa;
bool as[MAXN];
int d[MAXN];
vector<int> vs[MAXN];
void dfs(int v,int p){
    if(p!=-1){
        d[v]=d[p]+1;
    }
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs(adj[v][i],v);
        }
    }
}
void dfs1(int v,int p){
    for(int i=0;i<vs[v].size();i++){
        for(int j=0;j<k[vs[v][i]].size();j++){
            if(csa.find(k[vs[v][i]][j])==csa.end()){
                break;
            }
            if(j==k[vs[v][i]].size()-1){
                as[vs[v][i]]=true;
            }
        }
    }
    for(int i=0;i<adj[v].size();i++){
        csa.is(adj[v][i]);
    }
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs1(adj[v][i],v);
        }
    }
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            csa.erase(adj[v][i]);
        }
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
    d[1]=0;
    dfs(1,-1);
    for(int i=0;i<m;i++){
        int ks;
        cin>>ks;
        int md=0;
        int ix=1;
        for(int j=0;j<ks;j++){
            int a;
            cin>>a;
            k[i].pb(a);
            if(d[a]>md){
                md=d[a];
                ix=a;
            }
        }
        vs[ix].pb(i);
    }
    csa.is(1);
    dfs1(1,-1);
    for(int i=0;i<m;i++){
        if(as[i]){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}

