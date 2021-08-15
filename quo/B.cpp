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
const int MAXN = 1e3+2;
//store test cases here
/*


*/
int n;
int dp[MAXN][MAXN];
int dp1[MAXN][MAXN];
int g[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>n;
    dp1[0][0]=1;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<n;j++){
    		g[i][j]=s[j]-'0';
    		if(i&&j){
    			if(dp[i-1][j]==dp[i][j-1]){
    				dp[i][j]=dp[i-1][j];
    				dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%MOD;
    			}else if(dp[i-1][j]>dp[i][j-1]){
    				dp[i][j]=dp[i-1][j];
    				dp1[i][j]=dp1[i-1][j];
    			}else{
    				dp[i][j]=dp[i][j-1];
    				dp1[i][j]=dp1[i][j-1];
    			}
    		}else if(i){
				dp[i][j]=dp[i-1][j];
    			dp1[i][j]=dp1[i-1][j];
    		}else if(j){
				dp[i][j]=dp[i][j-1];
				dp1[i][j]=dp1[i][j-1];
    		}
    		dp[i][j]+=g[i][j];
    		dp1[i][j]%=MOD;
    	}
    }
    cout<<dp[n-1][n-1]<<" "<<dp1[n-1][n-1]<<"\n";
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

