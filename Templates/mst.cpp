#include <bits/stdc++.h>
using namespace std;

int n, edge;
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
int adj[MAXN][MAXN]; // adjacency matrix of graph
vector<pair<int,pii>> prim(){
    vector<bool> sel(n,false);
    vector<pii> min_e(n);
    vector<pair<int,pii>> mst;
    min_e[0].f=0;
    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++){
            if(!sel[j]&&(v==-1||min_e[j].f<min_e[v].f))
                v=j;
        }
        if(min_e[v].f==INF){
            return mst;
        }
        sel[v]=true;
        mst.pb(mp(v,min_e[v]));
        for(int to=0;to<n;to++){
            if(adj[v][to]<min_e[to].f)
                min_e[to]={adj[v][to],v};
        }
    }
    return mst;
}
vector<pair<pii,int>> krs(){
    for(int i=0;i<n;i++){
        make_set(i);
    }
    vector<pair<int,pii>> mst;
    sort(eg.begin(),eg.end());
    int ix=0;
    while(ix<eg.size()&&mst.size()<n-1){
        pair<int,pii> temp=eg[ix];
        int a=temp.s.f;
        int b=temp.s.s;
        if(find_set(b)!=find_set(a)){
            union_set(a,b);
            mst.pb(temp);
        }
        ix++;
    }
    return mst;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>edges;
    for(int i=0;i<edges;i++){
    	int a,b,w;
    	cin>>a>>b>>w;
    	adj[a].pb(mp(b,w));
     	adj[b].pb(mp(a,w));
        edges.pb(mp(w,mp(a,b)));
    }
    vector<pair<pii,int>> mst=krs();
}
