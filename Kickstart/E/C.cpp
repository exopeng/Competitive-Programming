#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int l = t;

    while (t--) {
    	long long ans = 0;
    	int n;
    	cin >> n;
    	vector< pair<long long, long long> > toys;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int e,r;
            cin >> e >> r;
            toys.push_back(make_pair(e,r));
            sum += toys[i].first;
        }
        ans = sum;
        long long tsum = sum;
        multiset< pair<long long, long long> > del;
        long long add = 0;
        long long csum = 0;
        int ct = 0;
        int numr = 0;
        for (int i = 0; i < n; i++) {
            if (sum - toys[i].first - toys[i].second < 0) {
                //if stoppage of early ones, then remove and continue, not necessarily stop
                //removing the toy 
                sum -= toys[i].first;
                ct++;
                add += toys[i].first;
                //others might have to be removed due to this
                //if del was empty
                //remove by which thing's first is largest
                //forgetting to store the previous added
                while (!del.empty() && del.begin()->first - add < 0) {
                    csum -= del.begin()->second;
                    sum -= del.begin()->second;
                    add += del.begin()->second;
                    del.erase(del.begin());
                    ct++;
                    //it might affect more
                }
            } else {
                del.insert(make_pair(tsum - toys[i].first - toys[i].second, toys[i].first));
                csum += toys[i].first;
                //might change?
                if (sum + csum > ans) {
                    ans = sum + csum;
                    numr = ct;
                }
            }
            //make sure nothing that is necessary is dependent on a loop
            
        }  
        if (!del.empty()) {
            cout << "Case #" << l - t << ": " << n - del.size() << " " << "INDEFINITELY" << "\n";         
        } else {
            cout << "Case #" << l - t << ": " << numr << " " << ans << "\n";
        }
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

