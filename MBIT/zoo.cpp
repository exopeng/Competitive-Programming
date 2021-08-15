#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
int n,q;
vector<long long> arr;
long long dpc[100001];
long long dpcc[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
    	long long e;
    	cin >> e;
    	arr.push_back(e);
    }

    //calc paths
    for (int i = 0; i < n-1; i++) {
    	dpc[n-1] += arr[i]; 
    }

    dpcc[n-1] = arr[n-1];
    for (int i = n - 2; i > 0; i--) {
    	dpc[i] = dpc[i+1] - arr[i];
    	dpcc[i] = dpcc[i+1] + arr[i];
    }

    for (int i = 0; i < q; i++) {
    	int a,b;
    	cin >> a >> b;
    	a--,b--;
    	if (a < b) {
    		swap(a,b);
    	}
    	cout << min(abs(dpc[a] - dpc[b]), abs(dpcc[a] + dpc[b])) << "\n";
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

