#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int ans = 0;
int N,K;
pair<int,int> arr[201];
//pair<int,int> dp[201][201];
int dp[3619][200][200];
int pow2 = 0;
int pow5 = 0;
//first is power of 2, second is power of 5, roundness is the min of them
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
    	long long num;
    	cin >> num;
    	long long temp = num;
    	arr[i] = make_pair(0,0);
    	while (temp % 2 == 0) {
    		arr[i].first++;
    		temp /= 2;
    		pow2++;
    	}

    	while (num % 5 == 0) {
    		arr[i].second++;
    		num /= 5;
    		pow5++;
    	}
    }

    //dp[i][j][k] = max # of 2's that can pair with ith power of 5 up to the kth element after taking
    //j elements
    for (int i = 0; i <= pow5; i++) {
        for (int j = 0; j < K; j++) {
            //erase past elements
            for (int e = 0; e < N; e++) {
                //make sure valid state
                if (j == 0 || dp[i][j][e] != 0) {
                    dp[i+arr[e].second][j+1][e+1] = max(dp[i+arr[e].second][j+1][e+1], dp[i][j][e] + arr[e].first);
                }
                dp[i][j][e+1] = max(dp[i][j][e+1], dp[i][j][e]);
                //cout << "i: " << i << " j: " << j << " e: " << e << " val: " << dp[i][j][e] << "\n";
            }

        }

    }

    //ans is min(dp[i][K][N], i) for every i
    for (int i = 0; i <= pow5; i++) {
    	ans = max(ans, min(i, dp[i][K][N]));
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

