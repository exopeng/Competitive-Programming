#include <bits/stdc++.h>
using namespace std;
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
//store test cases here
/*


*/
int n,m;
int dp[200001][5001];
int arr[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j <= 5000; j++) {
    		dp[i][j] = INF;
    	}
    }
    for (int i = 0; i <= m; i++) {
    	if (i != arr[0]) {
    		dp[0][i] = 1;
    	} else {
    		dp[0][i] = 0;
    	}
    }

    for (int i = 1; i < n; i++) {
    	for (int j = 0; j <= 5000; j++) { //a[i]
    		for (int e = max(j-m,0);e <= 5000; e++) {
    			if ((j==arr[i] && arr[i] - j <= m) || (j >= arr[i])) {
    				dp[i][j] = min(dp[i][j],dp[i-1][e]);
	    		} else {
    				dp[i][j] = min(dp[i][j],dp[i-1][e] + 1);
	    		}
    		}
    	}
    }

    int ans = INF;
    for (int i = 0; i <= 5000; i++) {
    	ans = min(ans, dp[n-1][i]);
    }

    cout << ans << "\n";


    
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

