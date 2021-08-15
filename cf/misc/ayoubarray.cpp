#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int n;
double l,r;
long long ans = 1;
const int MOD = 1000000007;
long long dp[200000][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;
    int temp = l;
    //dp[0] = r - l + 3;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    while (true) {
    	if ((int)l % 3 == 1) {
    		break;
    	}
    	l++;
    }
    count1 = (r-l) / 3 + 1;

    l = temp;
    while (true) {
    	if ((int)l % 3 == 2) {
    		break;
    	}
    	l++;
    }
    count2 = (r-l) / 3 + 1;

    l = temp;
    while (true) {
    	if ((int)l % 3 == 0) {
    		break;
    	}
    	l++;
    }
    count3 = (r-l) / 3 + 1;

    dp[0][0] = count3;
    dp[0][1] = count1;
    dp[0][2] = count2;
    //cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << "\n";
    
    for (int i = 1; i < n; i++) {
    	//num of ways to make val 0 = ways to get 1 mod 3 + previous ways to get 2 mod 3 ...
    	dp[i][0] = (count3 * dp[i-1][0] + count2 * dp[i-1][1] + count1 * dp[i-1][2]) % MOD;
    	dp[i][1] = (count3 * dp[i-1][1] + count2 * dp[i-1][2] + count1 * dp[i-1][0]) % MOD;
    	dp[i][2] = (count3 * dp[i-1][2] + count2 * dp[i-1][0] + count1 * dp[i-1][1]) % MOD;
    }
    
    cout << dp[n-1][0] << "\n";
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

