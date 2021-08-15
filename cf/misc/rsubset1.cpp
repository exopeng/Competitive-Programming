#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int ans = 0;
int n,k;
pair<int,int> arr[200];
//pair<int,int> dp[201][201];
pair<int,int> dp[201][201][3];

//first is power of 2, second is power of 5, roundness is the min of them
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        long long temp = num;
        arr[i] = make_pair(0,0);
        while (temp % 2 == 0) {
            arr[i].first++;
            temp /= 2;
        }
        while (num % 5 == 0) {
            arr[i].second++;
            num /= 5;
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            int t = arr[j-1].first;
            int f = arr[j-1].second;
            //dp[i][j][k] = max roundness by after taking i elements with the current element
            //about to be taken be the j'th one, k being the preference
            dp[i][j][0] = make_pair(t, f);
            dp[i][j][1] = make_pair(t, f);
            dp[i][j][2] = make_pair(t, f);

            for (int e = j-1; e > -1; e--) {
                //if equal, choose larger power for each
                if (dp[i][j][0].first < dp[i-1][e][0].first + t) {
                    dp[i][j][0] = make_pair(t + dp[i-1][e][0].first, f + dp[i-1][e][0].second);
                } else if (dp[i][j][0].first == dp[i-1][e][0].first + t) {
                    if (dp[i][j][0].second < dp[i-1][e][0].second + f) {
                        dp[i][j][0] = make_pair(t + dp[i-1][e][0].first, f + dp[i-1][e][0].second);
                    }
                }
                if (dp[i][j][1].second < dp[i-1][e][1].second + f) {
                    dp[i][j][1] = make_pair(t + dp[i-1][e][1].first, f + dp[i-1][e][1].second);
                } else if (dp[i][j][1].second == dp[i-1][e][1].second + f) {
                    if (dp[i][j][1].first < dp[i-1][e][1].first + t) {
                        dp[i][j][1] = make_pair(t + dp[i-1][e][1].first, f + dp[i-1][e][1].second);
                    }
                }
                if (min(dp[i][j][2].first, dp[i][j][2].second) < min(t + dp[i-1][e][2].first, f + dp[i-1][e][2].second)) {
                    dp[i][j][2] = make_pair(t + dp[i-1][e][2].first, f + dp[i-1][e][2].second);
                }
                ans = max(ans, min(dp[i][j][0].first, dp[i][j][0].second));
                ans = max(ans, min(dp[i][j][1].first, dp[i][j][1].second));
                ans = max(ans, min(dp[i][j][2].first, dp[i][j][2].second));

            }
            //cout << dp[i][j].first << "&" << dp[i][j].second << " ";
        }
        //cout << "\n";
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

