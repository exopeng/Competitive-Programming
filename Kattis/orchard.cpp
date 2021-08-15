#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
int r,g,b,y,s;
double dp[5][5][5][5][8];
double ans = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> g >> b >> y >> s;

    dp[0][0][0][0][0] = 1;
    bool first = true;
    //go through all states
    for (int i = 0; i <= r; i++) {
    	for (int j = 0; j <= g; j++) {
    		for (int k = 0; k <= b; k++) {
    			for (int e = 0; e <= y; e++) {
    				for (int f = 0; f < s; f++) {
    					if (first) {
    						first = false;
    						continue;
    					}
    					double val = 6;
    					//if maxed out, then not a possible choice
    					//check impossible states
    					//might have to cast double when dividing
    					if (f > 0 && !(i == r && j == g && k == b && e == y)) {
    						if (i == r) {
    							val--;
	    					}
	    					if (j == g) {
	    						val--;
	    					}
	    					if (k == b) {
	    						val--;
	    					}
	    					if (e == y){
	    						val--;	
	    					}
    					    dp[i][j][k][e][f] += dp[i][j][k][e][f-1] / val;
    						//cout << "-i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";
    					}
    					//convert numsame to double?
    					//if not the highest number left, then only 1/6 chance, minus the other nonvalid ones
    					val = 6; 
    					if (e > 0) {
    						bool hi = false;
    						int numsame = 1;

    						if (y-(e-1) == b-k) {
    							numsame++;
    						}
    						if (y-(e-1) == g-j) {
								numsame++;
    						}
    						if (y-(e-1) == r-i) {
								numsame++;
    						}

    						if (y-(e-1) >= b-k && y-(e-1) >= g-j && y-(e-1) >= r-i) {
    						 	hi = true;
    						}
    						if (i == r) {
    							val--;
	    					}
	    					if (j == g) {
	    						val--;
	    					}
	    					if (k == b) {
	    						val--;
	    					}
	    					//any may be chosen, so 
    					    dp[i][j][k][e][f] += dp[i][j][k][e-1][f] / val;
    					    if (hi) {
    					        dp[i][j][k][e][f] += dp[i][j][k][e-1][f] / (val*(numsame));
    					    }
    					    //cout << "-i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";
    					}

    					val = 6;
    					if (k > 0) {
    						bool hi = false;
    						int numsame = 1;

    						if (b-(k-1) == r-i) {
    							numsame++;
    						}
    						if (b-(k-1) == g-j) {
								numsame++;
    						}
    						if (b-(k-1) == y-e) {
								numsame++;
    						}

    						if (b-(k-1) >= r-i && b-(k-1) >= g-j && b-(k-1) >= y-e) {
    						 	hi = true;
    						}

    						if (i == r) {
    							val--;
	    					}
	    					if (j == g) {
	    						val--;
	    					}
	    					if (e == y) {
	    						val--;
	    					}
    					    dp[i][j][k][e][f] += dp[i][j][k-1][e][f] / val;

    					    if (hi) {
    					    	dp[i][j][k][e][f] += dp[i][j][k-1][e][f] / (val*numsame);
    					    }
    					    //cout << "-i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";
    					}

    					val = 6;
    					if (j > 0) {
    						bool hi = false;
    						int numsame = 1;
    						if (g-(j-1) == r-i) {
    							numsame++;
    						}
    						if (g-(j-1) == b-k) {
								numsame++;
    						}
    						if (g-(j-1) == y-e) {
								numsame++;
    						}

    						if (g-(j-1) >= r-i && g-(j-1) >= b-k && g-(j-1) >= y-e) {
    						 	hi = true;
    						}

    						if (i == r) {
    							val--;
	    					}
	    					if (y == e) {
	    						val--;
	    					}
	    					if (k == b) {
	    						val--;
	    					}
    					    dp[i][j][k][e][f] += dp[i][j-1][k][e][f]/ val;
    					    if (hi) {
    					    	dp[i][j][k][e][f] += dp[i][j-1][k][e][f]/ (val*numsame);
    					    }
    					    //cout << "-i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";

    					}

    					val = 6;
    					if (i > 0) {
    						bool hi = false;
    						int numsame = 1;

    						if (r-(i-1) == g-j) {
    							numsame++;
    						}
    						if (r-(i-1) == b-k) {
								numsame++;
    						}
    						if (r-(i-1) == y-e) {
								numsame++;
    						}
    						if (r-(i-1) >= b-k && r-(i-1) >= g-j && r-(i-1) >= y-e) {
    						 	hi = true;
    						}
    						if (y == e) {
    							val--;
	    					}
	    					if (j == g) {
	    						val--;
	    					}
	    					if (k == b) {
	    						val--;
	    					}

    					    dp[i][j][k][e][f] += dp[i-1][j][k][e][f] / val;
    					    if (hi) {
    					    	dp[i][j][k][e][f] += dp[i-1][j][k][e][f] / (val*numsame);
    					    }
    					    //cout << "-i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";

    					}

    					//cout << "i: "<< i << " j: " << j << " k: " << k << " e:" << e << " f: " << f << " val:" << dp[i][j][k][e][f] << "\n";
    				}
    			}
    		}
    	}
    }

    for (int i = 0; i < s; i++) {
    	ans += dp[r][g][b][y][i];
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

