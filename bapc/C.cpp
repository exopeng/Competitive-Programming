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
vector<pii> adj[MAXN];
ll d[MAXN];
int ans=INF;
bool vis[MAXN];
int ct[7];
int n,m;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int cr=1;
void wk(int curr){
    if(!vis[curr]){
        vis[curr]=true;
        for(int i=0;i<adj[curr].size();i++){
            //get prime factors
            if(gcd(adj[curr][i].s,
                (int)(cr))
                ==adj[curr][i].s){
                wk(adj[curr][i].f);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].pb(mp(v,w));
    	adj[v].pb(mp(u,w));
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int f=0;f<2;f++){
                for(int e=0;e<2;e++){
                    for(int c=0;c<2;c++){
                        for(int r=0;r<2;r++){
                            cr=(int)(pow(2,i)*pow(3,j)*pow(5,f)*pow(7,e)*pow(11,c)*pow(13,r));
                            wk(1);
                            if(vis[n]){
                                ans=min(ans,cr);
                            }
                            for(int i=1;i<=n;i++){
                                vis[i]=false;
                            }
                        }
                    }
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
 */

