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
const int MAXN = 2e6;
//store test cases here
/*


*/
int n,m,q;
int pop[MAXN];
vector<pii> adj[MAXN];
multiset<ll,greater<ll>> mx;
int parent[MAXN];
int size[MAXN];
ll tp[MAXN];
bool bk[MAXN];
vector<pair<int,pii>> od;
vector<pii> aj;
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    mx.is(pop[v]);
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        mx.erase(mx.find(tp[b]));
        mx.erase(mx.find(tp[a]));
        tp[a]+=tp[b];
        mx.is(tp[a]);
        parent[b] = a;
        size[a] += size[b];
    }
}
void dfs(int v){
    for(int i=0;i<adj[v].size();i++){
        if(find_set(adj[v][i].f)!=find_set(v)){
            if(!bk[adj[v][i].s]){
                union_sets(adj[v][i].f,v);
                dfs(adj[v][i].f);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        cin>>pop[i];
    }
    for(int j=0;j<m;j++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        aj.pb(mp(a,b));
        adj[a].pb(mp(b,j));
        adj[b].pb(mp(a,j));
    }
    for(int j=0;j<q;j++){
        char a;
        int b;
        cin>>a>>b;
        b--;
        if(a=='P'){
            int c;
            cin>>c;
            od.pb(mp(0,mp(b,pop[b])));
            pop[b]=c;
        }else{
            bk[b]=true;
            od.pb(mp(-1,aj[b]));
        }
    }
    for(int i=0;i<n;i++){
        make_set(i);
        tp[i]=pop[i];
    }
    for(int i=0;i<n;i++){
        dfs(i);
    }
    vector<ll> as;
    as.pb(*mx.begin());
    for(int i=q-1;i>-1;i--){
        if(od[i].f==-1){
            union_sets(od[i].s.f,od[i].s.s);
        }else{
            mx.erase(mx.find(tp[find_set(od[i].s.f)]));
            tp[find_set(od[i].s.f)]-=pop[od[i].s.f];
            pop[od[i].s.f]=od[i].s.s;
            tp[find_set(od[i].s.f)]+=pop[od[i].s.f];
            mx.is(tp[find_set(od[i].s.f)]);
        }
        if(i!=0){
            as.pb(*mx.begin());
        }
    }
    reverse(as.begin(),as.end());
    for(int i=0;i<q;i++){
        cout<<as[i]<<"\n";
    }
    return 0;
}

