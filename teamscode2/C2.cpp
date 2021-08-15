#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int arr[50][50];
int dp[50][50];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for (int i = 0; i<n;i++) {
    	for (int j = 0;j<n;j++) {
    		cin >> arr[i][j];
    	}
    }
    dp[0][0] = c;
    for (int i = 0; i < n; i++) {
    	dp[0][i] += arr[0][i];
    	if (i != 0) {
    		dp[0][i] += dp[0][i-1];
    	}
    }
	for (int i = 0; i < n; i++) {
    	dp[i][0] += arr[i][0];
    	if (i != 0) {
    		dp[i][0] += dp[i-1][0];
    	}
    }
    for (int i = 1; i < n; i++) {
    	for (int j = 1;j < n;j++) {
    		dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    		dp[i][j] += arr[i][j];
    	}
    }
    cout << dp[n-1][n-1] << "\n";
}
/* REMINDERS
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
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

