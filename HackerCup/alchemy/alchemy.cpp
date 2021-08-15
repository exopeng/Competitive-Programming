#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
string ans;
 
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("alchemy.in","r",stdin);
    freopen("alchemy.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int a = 0;
        int b = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            char stone;
            cin >> stone;
            if (stone == 'A') {
                a++;
            } else {
                b++;
            }
        }
        if (abs(a-b) == 1) {
            ans = "Y";
        } else {
            ans = "N";
        }   
        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
    return 0;
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
