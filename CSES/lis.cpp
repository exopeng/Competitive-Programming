#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long INF = 10000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a;
    vector<long long> d;
    for (int i = 0; i < n; i++) {
    	int b;
    	cin >> b;
    	a.push_back(b);
    	d.push_back(INF);
    }

    d.push_back(INF);

    d[0] = -1*INF;

    for (int i = 0; i < n; i++) {
    	long long ind = lower_bound(d.begin(),d.end(),a[i]+1) - d.begin();
    	/*
    	for (int j = 0; j <=n; j++) {
    		cout << p[j] << " ";
    	}
    	*/
    	//acout << "\n";
    	if (d[ind-1] < a[i] && a[i] < d[ind]) {
    		//cout << a[i] << " ";
            d[ind] = a[i];
    	}
    		
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
    	if (d[i] < INF) {
    		ans = i;
    	}
    }
    cout << ans << "\n";
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
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
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

