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
#define is insert
const long long INF = 1000000000;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/
int k,n,m;
vector<pair<int,pii> > adj[2001];
int a,b;
int d[2001][201];
int ans=INF;
void dijkstrapq(int s) {
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            d[i][j]=INF;
        }
    }
    d[s][k] = 0;
    priority_queue< pair<int,pii>, vector<pair<int,pii> >, greater<pair<int,pii> >> q;
    q.push({0, mp(s,k)});
    while (!q.empty()) {
        int v = q.top().s.f;
        int h = q.top().s.s;
        int d_v = q.top().f;
        q.pop();
        if (d_v != d[v][h])
            continue;
        for (auto edge : adj[v]) {
            int to = edge.f;
            int len = edge.s.f;
            int hi = edge.s.s;
            if (h-hi>0&&d[v][h] + len < d[to][h-hi]) {
                d[to][h-hi] = d[v][h] + len;
                q.push({d[to][h-hi], mp(to,h-hi)});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>n>>m;
    for(int i=0;i<m;i++){
        int b,c,t,h;
        cin>>b>>c>>t>>h;
        b--,c--;
        adj[b].pb(mp(c,mp(t,h)));
        adj[c].pb(mp(b,mp(t,h)));
    }   
    cin>>a>>b;
    a--,b--;
    dijkstrapq(a);
    for(int i=1;i<k+1;i++){
        ans=min(ans,d[b][i]);
    }
    if(ans==INF){
        ans=-1;
    }
    cout<<ans<<"\n";

}
/* REMINDERS
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

