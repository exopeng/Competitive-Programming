#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int ans = 0;
    	int n,x;
    	vector<int> arr;
    	vector<int> p;
    	cin >> n >> x;
    	int sum = 0;
    	bool found = false;
    	for (int i = 0; i < n; i++) {
    		int e;
    		cin >> e;
    		sum += e;
    		sum %= x;
    		if (e % x != 0) {
    			found = true;
    		}
    		arr.push_back(sum);
    		p.push_back(e);
    	}
    	if (!found) {
    		ans = -1;
    	} else {
	    	if (arr[n-1] != 0) {
	    		ans = n;
	    	} else {
	    		//find the first non zero sum
	    		for (int i = n-2; i > -1; i--) {
	    			if (arr[i] != 0) {
	    				ans = i + 1;
	    				break;
	    			}
	    		}
	    		
	    		//subtract the first nonmultiple of x
	    		for (int i = 0; i < n; i++) {
	    			if (p[i] % x != 0) {
	    				ans = max(ans, n - i - 1);
	    				break;
	    			}
		    	}
		    	
	    	}	
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

