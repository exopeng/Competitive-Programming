#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	long long ans = -1;
    	unordered_set<int> taken;
    	vector<int> num;
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		int e;
    		cin >> e;
    		taken.insert(e);
    		num.push_back(e);
    	}
    	bool found = false;
    	for (int i = 1; i < 1024; i++) {
    		unordered_set<int> temp = taken;
    		int k = i;
    		for (int j = 0; j < n; j++) {
    			int x = num[j] ^ i;
    			if (temp.find(x) == temp.end()) {
    				break;
    			}
    			temp.erase(x);
    			if (j == n-1) {
    				ans = i;
    				found = true;
    			}
    		}
    		if (found) {
    			break;
    		}
    	}
    	cout << ans << "\n";
    }
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
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
 */

