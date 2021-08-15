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
int n,m1,m2;
int p[MAXN][2];
int sz[MAXN][2];
void make_set(int v,int ix){
    p[v][ix]=v;
    sz[v][ix]=1;
}
int find_set(int v,int ix){
    if(v==p[v][ix])
        return v;
    return p[v][ix]=find_set(p[v][ix],ix);
}
void union_sets(int a,int b,int ix){
    a=find_set(a,ix);
    b=find_set(b,ix);
    if(a!=b){
        if(sz[a][ix]<sz[b][ix])
            swap(a,b);
        p[b][ix]=a;
        sz[a][ix]+=sz[b][ix];
    }
}
vector<int> adj[MAXN];
vector<int> adj1[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;i++){
        make_set(i,0),make_set(i,1);
    }
    for(int i=0;i<m1;i++){
        int a,b;cin>>a>>b;
        union_sets(a,b,0);
    }
    for(int i=0;i<m2;i++){
        int a,b;cin>>a>>b;
        union_sets(a,b,1);
    }
    vector<pii> as;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(find_set(i,0)!=find_set(j,0)
                &&find_set(i,1)!=find_set(j,1)){
                as.pb(mp(i,j));
                union_sets(i,j,0),union_sets(i,j,1);
            }
        }
    }
    cout<<as.size()<<"\n";
    for(int j=0;j<as.size();j++){
        cout<<as[j].f<<" "<<as[j].s<<'\n';
    }
    return 0;
}

