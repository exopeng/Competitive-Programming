#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long INF = -1000000000000000000;
int n;
long long arr[5001];
long long dp[5001][5001][2];
long long sum[5001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		dp[i][j][0] = INF;
    		dp[i][j][1] = INF;
    	}
    }

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	if (i != 0) {
    		sum[i] = sum[i-1];
    	}
    	sum[i] += arr[i];
    	if (n % 2 == 0) {
	    	dp[i][i][1] = arr[i];
	    } else {
	    	dp[i][i][0] = arr[i];
	    }
    }

    for (int i = n-2; i > -1; i--) {
    	for (int j = i+1; j < n; j++) {
			if ((n - (j - i + 1)) % 2 == 0) {
				if (i != 0) {
					dp[i][j][0] = sum[j-1] - sum[i-1] - dp[i][j-1][1] + arr[j];
				} else {
					dp[i][j][0] = sum[j-1] - dp[i][j-1][1] + arr[j];
				}
				dp[i][j][0] = max(dp[i][j][0], sum[j] - sum[i] - dp[i+1][j][1] + arr[i]);
				//cout << "i: " << i << " j: " << j << " k: " << 0 << " val: " << dp[i][j][0] << "\n";
			} else {
				if (i != 0) {
					dp[i][j][1] = sum[j-1] - sum[i-1] - dp[i][j-1][0] + arr[j];
				} else {
					dp[i][j][1] = sum[j-1] - dp[i][j-1][0] + arr[j];
				}
				dp[i][j][1] = max(dp[i][j][1],sum[j] - sum[i] - dp[i+1][j][0] + arr[i]);
				//cout << "i: " << i << " j: " << j << " k: " << 1 << " val: " << dp[i][j][1] << "\n";
			}
    	}
    }


    cout << dp[0][n-1][0] << "\n";


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

