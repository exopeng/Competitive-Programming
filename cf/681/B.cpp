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
int dp[MAXN][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
	for(int i=0;i<t;i++){
		int a,b;
		string s;
		cin>>a>>b;
		cin>>s;
		if(s[0]=='1'){
			dp[0][0]=dp[0][1]=a;
		}else{
			dp[0][0]=0;
			dp[0][1]=a;
		}
		for(int j=1;j<s.size();j++){
			if(s[j]=='1'){
				dp[j][0]=dp[j][1]=min(dp[j-1][1],dp[j-1][0]+a);
			}else{
				dp[j][0]=min(dp[j-1][0],dp[j-1][1]);
				dp[j][1]=min(dp[j-1][1]+b,dp[j-1][0]+a+b);
			}
		}
		if(s[s.size()-1]=='1'){
			cout<<dp[s.size()-1][1];
		}else{
			cout<<dp[s.size()-1][0];
		}
		cout<<"\n";
	}

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

