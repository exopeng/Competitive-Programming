#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int l = t;

    while (t--) {
    	int n,a,b,c;
    	cin >> n >> a >> b >> c;
    	
    	if (n - (a+b-c) < 0) {
    		cout << "Case #" << (l - t) << ": IMPOSSIBLE" << "\n";
    		continue;
    	}
    	
    	vector<int> ans;
    	//a < same > invis < b
    	//a < same > b
    	//det # of each
    	//a > b
    	int ah = 1;
		int sh = 2;
		int bh = 1;

    	if (c > 1) {	
	    	for (int i = 0; i < a-c; i++) {
	    		ans.push_back(ah);
	    	}

	    	for (int i = 0; i < c; i++) {
	    		ans.push_back(sh);
	    		if (i == 0) {
	    			for (int j = 0; j < n - (a+b-c); j++) {
	    				ans.push_back(1);
					}
	    		}
	    	}
	    	for (int i = 0; i < b - c; i++) {
	    		ans.push_back(bh);
	    	}
    	} else {
    		if (a == 1 && b == 1) {
    			if (n > 1) {
    				cout << "Case #" << (l - t) << ": IMPOSSIBLE" << "\n";
    				continue;
    			} else {
    				ans.push_back(1);
    			}
    		} else if (n-(a+b-c) == 0) {
    			for (int i = 0; i < a-c; i++) {
		    		ans.push_back(ah);
		    	}
		    	ans.push_back(sh);
		    	for (int i = 0; i < b - c; i++) {
		    		ans.push_back(bh);
		    	}
    		} else {
    			//guaranteed for n >= 3
    			ah = 2;
    			sh = 3;
    			bh = 2;
    			//order matters
    			if (a > 1) {
					for (int i = 0; i < a-1; i++) {
		    			ans.push_back(ah);
		    		}
		    		for (int i = 0; i < n-(a+b-c); i++) {
			    		ans.push_back(1);
			    	}
		    		ans.push_back(sh);
			    	for (int i = 0; i < b - 1; i++) {
			    		ans.push_back(bh);
			    	}
    			} else {
		    		ans.push_back(sh);
			    	for (int i = 0; i < n-(a+b-c); i++) {
			    		ans.push_back(1);
			    	}
			    	for (int i = 0; i < b - 1; i++) {
			    		ans.push_back(bh);
			    	}
    			}
    		}
    	}

    	cout << "Case #" << (l-t) << ": ";

    	for (int i = 0; i < ans.size(); i++) {
    		cout << ans[i] << " ";
    	}
    	cout << "\n";
    	
    }
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

