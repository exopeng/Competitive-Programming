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
const long long INF = 1000000000;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    int ct=1;
    while (t--) {
    	cout<<"Graph #" << ct<< ": ";
    	long long ans = 0;
    	long long n,a,b;
    	cin>>n>>a>>b;
    	if(n%2==0){
    		if(a%2==b%2) {
    			if(a%2==0) {
    				cout<<min( (max(a,b)-min(a,b)) / 2, (n-max(a,b)) / 2 + min(a,b)/2 );
    			} else{
    				cout<<min( (max(a,b)-min(a,b)) / 2, (n-1-max(a,b)) / 2 + (min(a,b)-1)/2 +1);
    			}
    		} else{
    			cout<<"Impossible";
    		}
    	} else{
    		if(a%2==b%2){
    			if(a%2==0) {
    				cout<<min((max(a,b)-min(a,b))/2, 
    					min(a,b)/2 + n/2 + (n+1-max(a,b))/2 );
    			} else{
    				cout<<min((max(a,b)-min(a,b))/2, 
    					min(a,b)/2  + (n-max(a,b))/2 + (n-1)/2 );
    			}
    		} else{
    			if(b%2==0) {
    				swap(a,b);
    			}
    			cout<<min(a/2 + (n-b)/2, (n-1-a)/2 + (b-1)/2 + 1);
    		}
    	}
    	ct++;
    	cout<<"\n";
    }
    return 0;
}
/* REMINDERS
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
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

