#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
int ans = 0;
 
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("shadow.in","r",stdin);
    freopen("shadow.out","w",stdout);
    int n;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    sum += arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
    ans = max(ans, sum);
    for (int i = 5; i < n; i++) {
        sum -= arr[i-5];
        sum += arr[i];
        ans = max(ans,sum);
    }

    cout << ans << "\n";
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
