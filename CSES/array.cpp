#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long MOD = 1000000007;
long long n,m;
long long arr[100001];
//first represents the # of ways to reach the sum
//second represents the lowest possible last number to reach it
long long dp[100001][101];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
        /*
        if (arr[i] != 0) {
            dp[i][arr[i]] = 1;
        }
        */
    }
    //put 1 in front of every beginning of zero region
    //maybe multiply each region
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                //make sure state before is valid
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i-1][j-1]) % MOD;
                if (j != m) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                }
            }
        } else {
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]] + dp[i-1][arr[i]-1]) % MOD;
            if (arr[i] != m) {
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1]) % MOD;
            }
        }
    }
    //can the values be 0?
    if (arr[n-1] == 0) {
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + dp[n-1][i]) % MOD;
        }
        cout << ans << "\n";
    } else {
        cout << (dp[n-1][arr[n-1]] % MOD)<< "\n";
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

