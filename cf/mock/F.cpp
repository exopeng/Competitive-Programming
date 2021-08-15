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
int n,k;
vector<int> adj[MAXN];
ll dp[MAXN];
ll re[MAXN][6];
ll sum=0;
void build(int v, int p){
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            build(adj[v][i],v);
            for(int j=0;j<k;j++){
                re[v][j]+=re[adj[v][i]][(j-1+k)%k];
            }
            re[v][1%k]++;
            dp[v]+=dp[adj[v][i]];
        }
    }
    dp[v]+=re[v][0];
    //dp represents tot # of full jumps
    //rem[i] reps # of paths with remainder i 
}
void tr(int v, int p){
    ll ms=dp[p];
    ll fs=dp[v];
    vector<pll> rs;
    for(int i=0;i<k;i++){
        rs.pb(mp(re[p][i],re[v][i]));
    }
    for(int i=0;i<k;i++){
        re[p][i]-=re[v][(i-1+k)%k];
    }
    dp[p]-=dp[v];
    re[p][1%k]--;
    dp[p]-=re[v][(-1+k)%k];
    for(int i=0;i<k;i++){
        re[v][i]+=re[p][(i-1+k)%k];
    }
    re[v][1%k]++;
    dp[v]+=dp[p]+re[p][(-1+k)%k];
    for(int i=1;i<k;i++){
        sum+=re[v][i];
    }
    sum+=dp[v];
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            tr(adj[v][i],v);
        }
    }
    dp[p]=ms;
    dp[v]=fs;
    for(int i=0;i<k;i++){
        re[p][i]=rs[i].f;
        re[v][i]=rs[i].s;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    build(0,-1);
    for(int i=1;i<k;i++){
        sum+=re[0][i];
    }
    sum+=dp[0];
    for(int i=0;i<adj[0].size();i++){
        tr(adj[0][i],0);
    }
    cout<<sum/2<<"\n";
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

