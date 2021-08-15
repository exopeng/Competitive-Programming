#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int k[6];
    int kn[6];
    cin >> n;
    for (int i = 0; i < 6; i++) {
    	cin >> k[i];
    	kn[i] = k[i];
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 6; j++) {
    		if (k[(j+1) % 6] < k[j]) {
    			kn[(j+1) % 6] += kn[j] / 2;
    			kn[j] -= kn[j] / 2;
    		}
    	}
    	for (int j = 0; j < 6; j++) {
    		k[j] = kn[j];
    	}
    }
    for (int i = 0; i < 6; i++) {
    	cout << k[i] << "\n";
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

