#include <bits/stdc++.h>

using namespace std;
long long ans = 1;
int n;
vector<int> arr;


int rec(int curr) {
	if (curr == n-1) {
		return 1;
	}
	int pos = 0;
	double maxslope = -100000000;
	for (int i = curr + 1; i < n; i++) {
		if (((double)arr[i] - arr[curr]) / (double)(i - curr) >= maxslope) {
			pos = i;
			maxslope = ((double)arr[i] - arr[curr]) / (double)(i - curr);
		}
	}

	return 1 + rec(pos);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	int e;
    	cin >> e;
    	arr.push_back(e);
    }

    cout << rec(0) << "\n";


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

