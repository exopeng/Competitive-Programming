#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
/*
bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int l = t;

    while (t--) {
    	int ans = 0;
    	int n,x;
        cin >> n >> x;
        pair<int,int> a[100000];
        for (int i = 0; i < n;i++) {
            cin >> a[i].first;
            a[i].second = i;
            if ((double)a[i].first / x == a[i].first / x && a[i].first / x != 0) {
                a[i].first = a[i].first / x - 1;
            } else {
                a[i].first /= x;
            }
        }

        sort(a,a+n);
        cout << "Case #" << (l-t) << ": ";
        for (int i = 0; i < n; i++) {
            cout << (a[i].second + 1) << " "; 
        }
        cout << "\n";


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

