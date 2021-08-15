#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
    	long long ans = 0;
    	long long a,b;
    	cin >> a >> b;
    	if (a > b) {
    		swap(b,a);
    	}
    	if (b % a != 0) {
    		cout << "-1" << "\n";
    	} else {
	    	long long power = b/a;
	    	if(power>0)
		    {
		        while(power%2 == 0)
		        {
		            power/=2;
		        }
		        if(power == 1)
		        {
		            int pow1 = (int)log2(b/a);
		    		int temp = pow1;
					temp /= 3;
					ans += temp;
					pow1 %= 3;
					temp = pow1;
					temp /= 2;
					ans += temp;
					pow1 %= 2;
					temp = pow1;
					temp /= 1;
					ans += temp;
					cout << ans << "\n";
		        }
		    }
		    if(power == 0 || power != 1)
		    {
		        cout << "-1" << "\n";
		    }	
    	}
    	
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

