#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int lengthOfLIS(vector<int>& nums) {
	int dp[1000];
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		dp[i] = 1;
		ans = max(ans,dp[i]);
	}
	for (int i = nums.size()-2; i > -1; i--) {
		int mx = 0;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] > nums[i]) {
			mx = max(mx, dp[j]);

			}
		}
		dp[i] += mx;
		ans = max(ans, dp[i]);
	}
	return ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
    	int b;
    	cin >> b;
    	a.push_back(b);
    }
    cout << lengthOfLIS(a);
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

