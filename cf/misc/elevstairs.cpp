#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int n,c;
int a[200000];
int b[200000];
int as[200000];
int bs[200000];
//think about what is important at each state!!!
int dp[200000][2];
bool elev = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n-1; i++) {
    	cin >> a[i];
    	as[i] += a[i];
    }
    for (int i = 0; i < n-1; i++) {
    	cin >> b[i];
    	bs[i] += b[i];
    }

    dp[0][0] = 0;
    dp[0][1] = c;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + a[i-1]);
        dp[i][1] = min(dp[i-1][0] + b[i-1] + c, dp[i-1][1] + b[i-1]);
    }

    for (int i = 0; i < n; i++) {
    	cout << min(dp[i][0],dp[i][1]) << " ";
    }
    cout << "\n";

    
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

