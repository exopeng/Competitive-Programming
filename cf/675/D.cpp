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
const long long INF = 1e18;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,m;
int sx,sy,fx,fy;
map<pii,int> ms;
vector<pii> adj[MAXN];
vector<pii> x;
vector<pii> y;
long long d[MAXN];
long long ans=INF;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>sx>>sy>>fx>>fy;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ms[mp(a,b)]=i;
        x.pb(mp(a,b));
        y.pb(mp(b,a));
        d[i]=INF;
    }
    x.pb(mp(sx,sy));
    y.pb(mp(sy,sx));
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ms[mp(sx,sy)]=m;
    for(int i=0;i<=m;i++){
        if(i!=0){
            adj[ms[x[i]]].pb(x[i-1]);
            adj[ms[mp(y[i].s,y[i].f)]].pb(mp(y[i-1].s,y[i-1].f));
        }
        if(i!=m){
            adj[ms[x[i]]].pb(x[i+1]);
            adj[ms[mp(y[i].s,y[i].f)]].pb(mp(y[i+1].s,y[i+1].f));
        }
    }
    d[m]=0;
    priority_queue<pair<long long,pii>, vector<pair<long long,pii>>, greater<pair<long long,pii>>> pq;
    pq.push(mp(0,mp(sx,sy)));
    while(!pq.empty()){
        pair<long long,pii> fs=pq.top();
        pq.pop();
        if(fs.f!=d[ms[fs.s]]){
            continue;
        }
        ans=min(ans,fs.f+abs(fs.s.f-fx)+abs(fs.s.s-fy));
        int id=ms[fs.s];
        for(int j=0;j<adj[id].size();j++){
            int ls=ms[adj[id][j]];
            if(adj[id][j].f==fs.s.f||adj[id][j].s==fs.s.s){
                if(fs.f<d[ls]){
                    d[ls]=fs.f;
                    pq.push(mp(d[ls],adj[id][j]));
                }
            }else{
                if(min(abs(adj[id][j].f-fs.s.f),abs(adj[id][j].s-fs.s.s))
                    +fs.f<d[ls]){
                    d[ls]=min(abs(adj[id][j].f-fs.s.f),abs(adj[id][j].s-fs.s.s))
                    +fs.f;
                    pq.push(mp(d[ls],adj[id][j]));
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
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

