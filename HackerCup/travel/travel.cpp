#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
long long ans = 0;
 
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        char in[50];
        char out[50];
        char ans[50][50];
        cin >> n;
        for (int j = 0; j < n; j++) {
            for (int f = 0; f < n; f++) {
                if (j == f) {
                    ans[j][f] = 'Y';
                } else {
                    ans[j][f] = 'N';
                }
            }
        }
        for (int j = 0; j < n; j++) {
            cin >> in[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> out[j];
        }
        for (int j = 0; j < n; j++) {
            //two directions
            for (int f = j+1; f < n; f++) {
                if (in[f] == 'Y' && out[f-1] == 'Y') {
                    ans[j][f] = 'Y';
                } else {
                    //all travel to the right is restricted
                    break;
                }
            }
            for (int f = j-1; f > -1; f--) {
                if (in[f] == 'Y' && out[f+1] == 'Y') {
                    ans[j][f] = 'Y';
                } else {
                    //all travel to the left is restricted
                    break;
                }
            }
        }
        cout << "Case #" << i+1 << ":" << "\n";
        for (int j = 0; j < n; j++) {
            for (int f = 0; f < n; f++) {
                cout << ans[j][f];
            }
            cout << "\n";
        }
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
