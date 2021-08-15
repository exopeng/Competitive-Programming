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
ll gcd(ll a,ll b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
vector<int> qs[MAXN];
int t[4*MAXN];
ll sum(int curr,int tl,int tr,int l,int r){
    if(l>r){
        return 0;
    }
    if(l==tl&&r==tr){
        return t[curr];
    }
    int mid=(tl+tr)/2;
    return gcd(sum(curr*2,tl,mid,l,min(r,mid)),sum(curr*2+1,mid+1,tr,max(l,mid+1),r));
}
void update(int curr,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[curr]=val;
    }else{
        int mid=(tl+tr)/2;
        if(pos<=mid){
            update(curr*2,tl,mid,pos,val);
        }else{
            update(curr*2+1,mid+1,tr,pos,val);
        }
        t[curr]=gcd(t[curr*2],t[curr*2+1]);
    }
}
int n,q;
vector<pair<ll,pll>> adj[MAXN];
vector<pii> qt;
map<pii,ll> as;
map<int,int> ls;
set<int,greater<int>> act;
void dfs(int v,int pa){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i].f!=pa){
            act.is(adj[v][i].s.f);
            update(1,0,n-2,ls[adj[v][i].s.f],adj[v][i].s.s);
            for(int j=0;j<qs[adj[v][i].f].size();j++){
                auto it=prev(act.ub(qs[adj[v][i].f][j]));
                if(act.ub(qs[adj[v][i].f][j])!=act.begin()){
                    as[mp(adj[v][i].f,qs[adj[v][i].f][j])]=sum(1,0,n-2,ls[*it],n-2);
                }else{
                    as[mp(adj[v][i].f,qs[adj[v][i].f][j])]=0;
                }
            }
            dfs(adj[v][i].f,v);
            act.erase(adj[v][i].s.f);
            update(1,0,n-2,ls[adj[v][i].s.f],0);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	cin>>n>>q;
        vector<int> lt;
        for(int j=0;j<n-1;j++){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            adj[a].pb(mp(b,mp(c,d)));
            adj[b].pb(mp(a,mp(c,d)));
            lt.pb(c);
        }
        sort(lt.begin(),lt.end());
        for(int j=0;j<lt.size();j++){
            ls[lt[j]]=j;
        }
        cout<<"Case #"<<(i+1)<<":";
        for(int j=0;j<q;j++){
            int c,w;
            cin>>c>>w;
            qs[c].pb(w);qt.pb(mp(c,w));
        }
        dfs(1,-1);
        for(int j=0;j<q;j++){
            cout<<" "<<as[qt[j]];
        }
        cout<<"\n";
        for(int j=0;j<=n;j++){
            adj[j].clear();
        }
        for(int j=0;j<q;j++){
            qs[qt[j].f].clear();
        }
        qt.clear();
        as.clear();
        ls.clear();
        act.clear();
        cout<<"\n";
    }
    return 0;
}

