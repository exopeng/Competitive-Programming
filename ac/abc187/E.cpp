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
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
long long t[4*MAXN];
void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

long long get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
vector<int> adj[MAXN];
int sz[MAXN];
int id[MAXN];
int n,q;
int ct=0;
int pa[MAXN];
vector<pii> ed;
int dfs(int v, int p){
    pa[v]=p;
    id[v]=ct;
    ct++;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            sz[v]+=dfs(adj[v][i],v);
        }
    }
    return sz[v]+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
        ed.pb(mp(a,b));
    }
    dfs(0,-1);
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        b--;
        if(a==1){
            if(pa[ed[b].f]==ed[b].s){
                update(1,0,n-1,id[ed[b].f],id[ed[b].f]+sz[ed[b].f],c);
            }else{
                update(1,0,n-1,0,n-1,c);
                update(1,0,n-1,id[ed[b].s],id[ed[b].s]+sz[ed[b].s],-1*c);
            }
        }else{
            if(pa[ed[b].s]==ed[b].f){
                update(1,0,n-1,id[ed[b].s],id[ed[b].s]+sz[ed[b].s],c);
            }else{
                update(1,0,n-1,0,n-1,c);
                update(1,0,n-1,id[ed[b].f],id[ed[b].f]+sz[ed[b].f],-1*c);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<get(1,0,n-1,id[i])<<"\n";
    }
    return 0;
}
/* REMINDERS
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

