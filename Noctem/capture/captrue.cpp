#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("capture.in","r",stdin);
    freopen("capture.out","w",stdout);
    int n, r,c,a,b;
    cin >> n >> r >> c >> a >> b;
    vector<pair<int,int> > nets;
    for (int i = 0; i < n; i++) {
        int r,c;
        cin >> r >> c;
        nets.push_back(make_pair(r,c));
    }
    //loop on top left corner
    for (int i = 0; i + b < c;i++) {
        for (int j = 0; j + a < r; j++) {
            pair<int,int> topleft = make_pair(j,i);
            pair<int,int> bottomright = make_pair(j+a,i+b);

            for (int e = 0; e < n; e++) {
                if (nets[e].first >= topleft.second && nets[e].first <= topright.second) {
                    
                }
            }
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
