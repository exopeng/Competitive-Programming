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
vector<pii> adj;
vector<pii> ad[MAXN];
int parent[MAXN];
int sz[MAXN];
vector<pair<int,pii>> eg;
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
ll krs(){
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    ll ts=0;
    vector<pair<int,pii>> mst;
    sort(eg.begin(),eg.end());
    int ix=0;
    while(ix<eg.size()&&mst.size()<n-1){
        pair<int,pii> temp=eg[ix];
        int a=temp.s.f;
        int b=temp.s.s;
        if(find_set(b)!=find_set(a)){
            union_set(a,b);
            ts+=temp.f;
        }
        ix++;
    }
    return ts;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj.pb(mp(a,b));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                eg.pb(mp(abs(adj[i].f-adj[j].f)+abs(adj[i].s-adj[j].s),mp(i,j)));
            }
        }
    }
    cout<<2*krs()<<"\n";
    return 0;
}

