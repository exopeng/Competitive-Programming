#include <bits/stdc++.h>

using namespace std;
int arr[31][31];
int temparr[31][31];
int ct[62][2];

long long ans = 0;
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	ans = 0;
    	cin >> n >> m;
    	for (int i = 0; i < n + m - 1; i++) {
    		ct[i][0] = 0;
    		ct[i][1] = 0;
    	}
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cin >> arr[i][j];
    			ct[i+j][arr[i][j]]++;
    		}
    	}
    	for (int i = 0; i < (n + m - 1) / 2; i++) {
    		ans += min(ct[i][0] + ct[n + m - 2 - i][0], ct[i][1] + ct[n + m - 2 - i][1]);
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

