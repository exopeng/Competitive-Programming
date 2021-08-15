#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
long long ans = 0;
set<int > s;
int n;
int arr[101];
bool dp[100001][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    dp[0][0] = true;
    for (int i = 0; i < 100001; i++) {
    	for (int j = 0; j < n; j++) {
    		if (j!=0) {
    			if (dp[i][j-1]) {
    				dp[i][j] = true;
    			}
    		}
    		if (i+arr[j]<100001) {
    			dp[i+arr[j]][j+1] = dp[i][j];
    		}
    	}
    }

    for (int i = 1; i < 100001; i++) {
    	for (int j = 1; j <= n; j++) {
    		if (dp[i][j]) {
    			ans++;
    			s.insert(i);
    			break;
    		}
    	}
    }

    cout << ans << "\n";
    for (auto it = s.begin(); it!=s.end();it++) {
    	cout << *it << " ";
    }
    cout << "\n";


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

