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
const int MAXN = 2e5+5;
//store test cases here
/*


*/
int n;
int ans=INF;
int dp[MAXN];

vector<int> adj[6];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	dp[i]=INF;
    }
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
    	string s;
    	cin>>s;
    	if(s=="Blue") {
    		adj[0].pb(i);
    	} 
    	if(s=="Orange"){
    		adj[1].pb(i);
    	}
    	if(s=="Red") {
    		adj[2].pb(i);
    	} 
    	if(s=="Yellow"){
    		adj[3].pb(i);
    	}
    	if(s=="Pink") {
    		adj[4].pb(i);
    	} 
    	if(s=="Green"){
    		adj[5].pb(i);
    	}
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<6;j++){
    		auto it=ub(adj[j].begin(),adj[j].end(),i);
    		if(it!=adj[j].end()&&dp[*it]>dp[i]+1){
    			dp[*it]=dp[i]+1;
    		}
    	}
    }
    cout<<dp[n]<<"\n";
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

