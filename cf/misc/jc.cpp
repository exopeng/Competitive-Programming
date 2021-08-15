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
int n,m;
pii t[MAXN];
vector<int> adj[MAXN];
set<int> hs[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].f;
        t[i].s=i;
    }
    sort(t+1,t+n+1);
    bool g=false;
    for(int j=1;j<=n;j++){
        for(int f=1;f<t[j].f;f++){
            if(hs[t[j].s].find(f)==hs[t[j].s].end()){
                g=true;
                break;
            }
        }
        if(hs[t[j].s].find(t[j].f)!=hs[t[j].s].end()){
            g=true;
            break;
        }
        if(g){
            break;
        }
        for(int f=0;f<adj[t[j].s].size();f++){
            hs[adj[t[j].s][f]].is(t[j].f);
        }
    }
    if(g){
        cout<<-1<<'\n';
    }else{
        for(int j=1;j<=n;j++){
            cout<<t[j].s<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

