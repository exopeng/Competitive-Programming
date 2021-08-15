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
vector<pair<int,pii>> eg;
int parent[10000];
int size[10000];
//prim's for dense graphs, E=V^2
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
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
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
pll krs(){
    for(int i=0;i<n;i++){
        make_set(i);
    }
    ll mc=0;
    ll tc=0;
    vector<pair<int,pii>> mst;
    sort(eg.begin(),eg.end());
    int ix=0;
    while(ix<eg.size()&&mst.size()<n-1){
        pair<int,pii> temp=eg[ix];
        int a=temp.s.f;
        int b=temp.s.s;
        if(find_set(b)!=find_set(a)){
            tc+=abs(temp.f);
            if(temp.f<0){
                mc+=temp.f;
            }
            union_set(a,b);
            mst.pb(temp);
        }
        ix++;
    }
    return mp(-1*mc,tc);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n>>m1>>m2;
        eg.clear();
        for(int i=0;i<m1;i++){
            int a,b,c;
            cin>>a>>b>>c;
            eg.pb(mp(c,mp(a,b)));
        }
        for(int i=0;i<m2;i++){
            int a,b,c;
            cin>>a>>b>>c;
            eg.pb(mp(-1*c,mp(a,b)));
        }
        pll mm=krs();
        bool g=true;
        for(int i=0;i<n-1;i++){
            if(find_set(i)!=find_set(i+1)){
                g=false;
            }
        }
        if(g){
            cout<<mm.f<<" "<<mm.s<<"\n";
        }else{
            cout<<"Impossible"<<"\n";
        }
    }
    return 0;
}

