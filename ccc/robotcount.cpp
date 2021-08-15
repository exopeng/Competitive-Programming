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
const int MAXN = 252;
//store test cases here
/*


*/
int n,q;
int dp[MAXN][MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("robotcount.in","r",stdin);
    freopen("robotcount.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	dp[a][b][c]++;
    }
    for(int i=1;i<MAXN;i++){
    	for(int j=1;j<MAXN;j++){
    		for(int k=1;k<MAXN;k++){
    			dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k]+dp[i][j][k-1]
    			-dp[i-1][j-1][k]-dp[i][j-1][k-1]-dp[i-1][j][k-1]+dp[i-1][j-1][k-1];
    		}
    	}
    }
    for(int i=0;i<q;i++){
    	int a,b,c,d,e,f;
    	cin>>a>>b>>c>>d>>e>>f;
    	cout<<dp[d][e][f]-dp[d][b-1][f]-dp[a-1][e][f]-dp[d][e][c-1]
    	+dp[a-1][b-1][f]+dp[a-1][e][c-1]+dp[d][b-1][c-1]-dp[a-1][b-1][c-1]<<"\n";
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

