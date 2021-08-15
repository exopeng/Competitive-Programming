#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pii pair<int,int>
#define is insert
const int INF = 1000000003;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,q;
int arr[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    Tree< pii > ts;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
        ts.is(mp(arr[i],i));
    }   

    for (int i = 0; i < q; i++) {
    	char f;
        int a,b;
    	cin >> f;
    	if (f == '?') {
    		cin >> a >> b;
            int lo = ts.order_of_key(mp(a,0));
            int hi = ts.order_of_key(mp(b+1,0));
            cout << hi - lo << "\n";
    	} else {
    		cin >> a >> b;
            a--;
            ts.erase(mp(arr[a],a));
            arr[a] = b;
            ts.is(mp(arr[a],a));
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
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

