#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int n;
int arr[200000];
int dp[200000];
map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    int mx = 0;
    int ind = -1;
    for (int i = n-1; i > -1; i--) {
    	if (mp.find(arr[i] + 1) != mp.end()) {
    		dp[i] = mp[arr[i]+1] + 1; 
    		mp[arr[i]] = dp[i];
    	} else {
    		dp[i] = 1;
    		mp[arr[i]] = 1;
    	}
    	if (dp[i] > mx) {
    		mx = dp[i];
    		ind = arr[i];
    	}
    }
    int ct = ind;
    cout << mx << "\n";
    for (int i = 0; i < n; i++) {
    	if (arr[i] == ct) {
    		cout << i + 1 << " ";
    		ct++;
    	}
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

