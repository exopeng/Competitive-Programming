#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int a,b;
int dp[501][501];
const int INF = 1000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i <= a; i++) {
    	for (int j = 0; j <= b;j++) {
    		dp[i][j] = INF;
    	}
    }

    for (int i = 1; i <= a; i++) {
    	for (int j = 1; j <= b; j++) {
    		if (i == j) {
    			dp[i][j] = 0;
    		} else {
    			for (int e = 1; e < j; e++) {
    				dp[i][j] = min(dp[i][j], dp[i][j-e] + dp[i][e] + 1);
    			}
    			for (int e = 1; e < i; e++) {
    				dp[i][j] = min(dp[i][j], dp[i-e][j] + dp[e][j] + 1);
    			}
    		}
    		//cout << "i: " << i << " j:" << j << " val: " << dp[i][j];
    	}
    }

    cout << dp[a][b] << "\n";
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

