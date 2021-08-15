#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int w[100];
int v[100];
long long dp[101][100001];
long long ans = 0;
//least weight by taking the ith item with value j/ or not
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,W;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[i][j] = 100000000000000;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - v[i-1] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j - v[i-1]] + w[i-1]);
            }
            if (dp[i][j] <= W) {
                ans = max(ans, (long long)j);
            }
        }
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
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

