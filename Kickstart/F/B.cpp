#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ti;
    cin >> ti;
    int l = ti;

    while (ti--) {
    	int ans = 0;
    	int n,k;
        pair<int,int> t[100001];
    	cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> t[i].first >> t[i].second;
        }
        //bounds checking +1,-1
        sort(t,t+n);
        int curr = t[0].first;
        int times = ceil((double)(t[0].second - t[0].first) / k); 
        int end = curr + times*k - 1;
        ans += times;
        for (int i = 1; i < n; i++) {
            if (t[i].first > end) {
                times = ceil((double)(t[i].second - t[i].first) / k);
                curr = t[i].first;
                end = curr + times * k - 1; 
                ans += times;
                //if it doesn't cover the whole thing
            } else if (t[i].second > end + 1) {
                times = ceil((double)(t[i].second - end - 1) / k);
                curr = end + 1;
                end = curr + k*times - 1;
                ans+=times;
            }
        }

    	cout << "Case #" << (l-ti) << ": " << ans << "\n";
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

