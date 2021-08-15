#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	long long ans;
    	int num = 0;
    	int n;
    	//multiset<int> g;
    	vector<int> g;
    	//map<int,int> g;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		int e;
    		cin >> e;
    		//find the number of g that go over n, that is the new max, as they will never go in
    		g.push_back(e);
    	}
    	//look backwards to find the ones that exceed n
    	//if they do, decrease n, if they don't, stop
    	sort(g.begin(),g.end());
    	for (int i = n-1; i > -1; i--) {
    		if (g[i] > n) {
    			n--;
    		}
    	}
    	cout << n + 1 << "\n";
    	


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

