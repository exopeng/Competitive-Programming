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
int n,m,k;
vector<int> a;
vector<pii> adj[MAXN];
bool sp[MAXN];
ll as=2*INF;
ll d[MAXN];
ll ot[MAXN];
void dpq(){
    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> q;

    for(int i=0;i<a.size();i++){
        d[a[i]]=0;
        ot[a[i]]=a[i];
        q.push(mp(mp(0,a[i]),a[i]));
    }
    while(!q.empty()){
        int v=q.top().f.s;
        int d_v=q.top().f.f;
        int og=q.top().s;
        q.pop();
        if(d_v!=d[v])
            continue;
        for(auto edge:adj[v]){
            int to=edge.f;
            int len=edge.s;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                ot[to]=og;
                q.push(mp(mp(d[to],to),og));
                //
            }else if(og!=ot[to]){
                as=min(as,d[v]+len+d[to]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int b;
        cin>>b;
        a.pb(b);
        sp[b]=true;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    dpq();
    cout<<as<<"\n";
    return 0;
}

