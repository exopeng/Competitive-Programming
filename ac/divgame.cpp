#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pii pair<int,int>
#define is insert
const long long INF = 1000000000;
const long long MOD = 1000000007;
//store test cases here
/*


*/
long long n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    long long temp = n;
    long long div = 2;
    int ans = 0;

    //can div by itself if prime
    while (n != 1 && div <= pow(temp,0.5)) {
    	long long t = div;
    	while (n % t == 0) {
    		ans++;
    		n/=t;
    		t*=div;
    	}
    	//primality check, if yes, then stop
    	while (n % div == 0) {
    		n/=div;
    	}
    	//might have to take floor first
    	//ans += (int)((-1+pow(1+8*ct,0.5)) / 2);
    	div++;
    	//cout << ct << " ";
    }
    if (temp != 1) {
    	if (n != 1) {
    		cout << ans + 1 << "\n";
    	} else {
    		cout << ans << "\n";
    	}
    } else {
    	cout << 0 << "\n";
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
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

