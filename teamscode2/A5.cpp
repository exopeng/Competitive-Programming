#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, v;
    int k[500];
    cin >> v >> n;
    for (int i = 0; i < n; i++) {
    	cin >> k[i];
    }
    for (int i = n; i > 0; i--) {
    	int sum = 0;
    	bool h = false;
        int counter = 1;
    	for (int j = 0; j < n; j++) {
    		sum += k[j];
    		if (counter == i || j == n-1) {
                if (v - sum*(counter) < 0) {
                    h = true;
                    //cout << counter << "\n";
                    break;
                } 
    			sum = 0;
                counter = 0;
    		} 
            counter++;
    	}
    	if (!h) {
    		cout << i << "\n";
    		return 0;
    	}
    }
    cout << 0 << "\n";
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

