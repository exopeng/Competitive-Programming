#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string text1,text2;
    cin >> text2 >> text2;

    int dp[1001][1001];
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            dp[i][j] = 0;
        }
    }
    //dp[i][j], if same character, then = dp[i+1][j+1] + 1;
    //not same character, dp[i][j] = max(dp[i+1][j], dp[i][j+1]
    int ans = 0;
    for (int i = text1.size() - 1; i > -1; i--) {
        for (int j = text2.size() - 1; j > -1; j--) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
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

