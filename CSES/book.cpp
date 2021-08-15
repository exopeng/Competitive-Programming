#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int n,x;
int p[1001];
int pg[1001];

int dp[100001][1002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> pg[i];
    }

    for (int i = 0; i <= x; i++) {
    	for (int j = 0; j <= n; j++) {
    		if (j != 0) {
    			dp[i][j] = max(dp[i][j], dp[i][j-1]);
    		}
    		if (j != n && i + p[j] <= x) {
    			dp[i+p[j]][j+1] = max(dp[i+p[j]][j+1], dp[i][j] + pg[j]);
    		}
    	}
    }

    cout << dp[x][n] << "\n";
    
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

