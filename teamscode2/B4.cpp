#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int arr[1000001];
int put[1000001];
int rem[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    int hi = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int l,u;
    	cin >> l >> u;
    	put[l]++;
    	rem[u]++;
    }
    int s = 0;
    for (int i = 0; i < 1000001; i++) {
    	s += put[i];
    	arr[i]+=s;
    	s -= rem[i];
	}
	for (int i = 0; i < 1000001; i++) {
		if (arr[i] > hi) {
			hi = arr[i];
			ans = i;
		} else if (arr[i] == hi) {
			ans = min(ans,i);
		}
	}
	cout << ans << "\n";
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

