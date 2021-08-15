#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	long long ans = 0;
    	int p;
    	cin >> p;
    	list<int> arr;
    	for (int i = 0; i < p; i++) {
    		int e;
    		cin >> e;
    		arr.push_back(e);
    	}
    	for (auto i = arr.begin(); i != arr.end(); i++) {
    		if (i == arr.begin()) {
    			continue;
    		}
    		if (next(i,1) != arr.end()) {
    			if ((*prev(i,1) > *i && *i > *next(i,1)) || (*prev(i,1) < *i && *i < *next(i,1))) {
	    			auto temp = i;
	    			i--;
	    			arr.erase(temp);
	    			p--;
	    		}
    		}
    	}
    	cout << p << "\n";
    	for (auto i = arr.begin(); i != arr.end(); i++) {
    		cout << *i << " ";
    	}
    	cout << "\n";

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

