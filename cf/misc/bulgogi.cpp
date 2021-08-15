#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	string ans = "NO";
    	int n,m;
    	int time[100];
    	int temp[100][2];
    	int dp[100][2];
    	bool bad = false;
    	cin >> n >> m;
    	for (int i = 0; i < n; i++) {
    		cin >> time[i] >> temp[i][0] >> temp[i][1];
    	}
    	dp[n-1][0] = temp[n-1][0];
    	dp[n-1][1] = temp[n-1][1];
    	for (int i = n-2; i > -1; i--) {
    		dp[i][0] = dp[i+1][0] - (time[i+1] - time[i]);
    		dp[i][1] = dp[i+1][1] + (time[i+1] - time[i]);
    		if (temp[i][1] < dp[i][0] || temp[i][0] > dp[i][1]) {
    			cout << "NO" << "\n";
    			bad = true;
    			break;
    		}
    		dp[i][0] = max(temp[i][0], dp[i][0]);
    		dp[i][1] = min(temp[i][1], dp[i][1]);
    	}
    	if (bad) {
    		bad = false;
    		continue;
    	}
    	if (m >= dp[0][0] && m <= dp[0][1]) {
    		ans = "YES";
    	} else if (m > dp[0][1]){
    		if (m - dp[0][1] <= time[0]) {
    			ans = "YES";
    		} 
    	} else {
    		if (dp[0][0] - m <= time[0]) {
    			ans = "YES";
    		}
    	}
    	cout << ans << "\n";
    }
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

