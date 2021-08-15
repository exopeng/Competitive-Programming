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
int n,m,q;
ll h[MAXN];
vector<pair<int,pii>> et;
multiset<ll,greater<ll>> mx;
vector<ll> as;
int parent[MAXN];
int size[MAXN];
ll sz[MAXN];
set<pii> ts;
void make_set(int v){
    parent[v]=v;
    size[v]=1;
    sz[v]=h[v];
    mx.is(h[v]);
}
int find_set(int v){
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        mx.erase(mx.find(sz[a])),mx.erase(mx.find(sz[b]));
        sz[a]+=sz[b];
        mx.is(sz[a]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        cin>>h[i+1];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ts.is(mp(a,b));
    }
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            ts.erase(mp(b,c)),ts.erase(mp(c,b));
            et.pb(mp(1,mp(b,c)));
        }else{
            et.pb(mp(2,mp(b,h[b])));
            h[b]=c;
        }
    }
    reverse(et.begin(),et.end());
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    for(auto it=ts.begin();it!=ts.end();it++){
        union_sets(it->f,it->s);
    }
    as.pb(*mx.begin());
    for(int i=0;i<et.size()-1;i++){
        if(et[i].f==1){
            union_sets(et[i].s.f,et[i].s.s);
        }else{
            mx.erase(mx.find(sz[find_set(et[i].s.f)]));
            sz[find_set(et[i].s.f)]-=h[et[i].s.f]-et[i].s.s;
            h[et[i].s.f]=et[i].s.s;
            mx.is(sz[find_set(et[i].s.f)]);
        }
        as.pb(*mx.begin());
    }
    for(int i=as.size()-1;i>-1;i--){
        cout<<as[i]<<"\n";
    }
    return 0;
}

