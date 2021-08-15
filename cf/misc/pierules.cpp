#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> p;
int dpa[51];
int dpb[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int e;
    	cin >> e;
    	p.push_back(e);
    }
    if (n == 1) {
    	cout << 0 << " " << p[0] << "\n";
    	return 0;
    }
    dpa[n-1] = p[n-1];
    dpb[n-1] = p[n-1];
    int sum = p[n-1];;
    for (int i = n-2; i > 0; i--) {
    	dpa[i] = max(p[i] + sum - dpb[i+1], dpa[i+1]);
    	dpb[i] = max(p[i] + sum - dpa[i+1], dpb[i+1]);
    	sum += p[i];
    }
    dpb[0] = max(p[0] + sum - dpa[1], dpb[1]);
    sum += p[0];
    dpa[0] = sum - dpb[0];
    cout << dpa[0] << " " << dpb[0] << "\n"; 

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

