#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*
*/ 
const long long MAXVAL = 9000000000000000;
int n, m;
long long dp[1000000];
long long c[1000000];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("C1.in","r",stdin);
    freopen("C1.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long ans = MAXVAL;
        //dp[i] represents min cost to get to end
        //if you refill at pos i
        cin >> n >> m; 
        
        for (int j = 0; j < n; j++) {
            dp[j] = MAXVAL;
        }    
     
        for (int j = 0; j < n; j++) {
            cin >> c[j];
        }
        
        //dp[i] = min(dp[i+1]...[dp[farthest you can travel]] + c[i])
        dp[n-1] = 0;
        multiset<long long> mins;
        mins.insert(0);
        for (int j = n-2; j > -1; j--) {
            //make sure not 0
            if (c[j] != 0) {
                /*
               for (int f = j+1; f - (j+1) < m && f < n; f++) {
                    if (dp[f] < minc) {
                        minc = dp[f];
                    }
                }
                */
                dp[j] = *mins.begin() + c[j];
            } 
            mins.insert(dp[j]);
            if ((n-1) - j >= m) {
                mins.erase(mins.find(dp[j+m]));
            } 
        }
        //only a few places where you can refill
        for (int j = 0; j <= m && j < n; j++) {
            if (dp[j] < ans) {
                ans = dp[j];
            }
        }
        if (ans == MAXVAL) {
            ans = -1;
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
