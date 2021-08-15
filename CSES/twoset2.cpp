#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long MOD = 1000000007;
int n;
long long dp[62626][501];
int arr[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	arr[i] = i+1;
    }
    dp[0][0] = 1;
    //validity check beginning...
    for (int i = 0; i <= (double)n*(n+1)/4; i++) {
    	for (int j = 0; j < n; j++) {
    		if (j != 0) {
    			dp[i][j] += dp[i][j-1];
    		} 
    		if (arr[j] + i <= (double)n*(n+1)/4) {
    			dp[i+arr[j]][j+1] = (dp[i+arr[j]][j+1] + dp[i][j]) % MOD;
    		} 
    		//cout << "i: " << i << " j: " << j << " val: " << dp[i][j] << "\n";
    	}
    }

    if ((double)n*(n+1) / 4 != n*(n+1)/4) {
    	cout << "0" << "\n";
    } else {
    	   cout << (dp[n*(n+1)/4][n]) % MOD << "\n";
    }
    
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

