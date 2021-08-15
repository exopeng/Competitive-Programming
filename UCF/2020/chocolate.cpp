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
int arr[MAXN];
int incr[MAXN];
int decr[MAXN];
//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	long long ans = 0;
    	int n,m;
    	cin>>n>>m;
    	for(int i=0;i<n;i++){
    		arr[i]=0;
    		incr[i]=0;
    		decr[i]=0;
    	}
    	for(int i=0;i<m;i++){
    		int a,b;
    		cin>>a>>b;
    		incr[a-1]++;
    		decr[b-1]++;
    	}
    	int run=0;
    	for(int i=0;i<n;i++){
    		run+=incr[i];
    		arr[i]+=run;
    		run-=decr[i];
    	}
    	stack<int> ps;
    	for(int i=0;i<n;i++){
    		if(i>0&&arr[i]<arr[i-1]){
    			while(ps.empty()==false){
    				int curr = ps.top();
    				if(curr > arr[i]) {
    					ps.pop();
    				} else{
    					ans+=arr[i]-curr;
    					break;
    				}
    			}
    			if(ps.empty()){
    				ans+=arr[i];
    			}
    		} else if(i > 0 && arr[i]>arr[i-1]){
    			ans+=arr[i]-arr[i-1];
    		}
    		if(i==0){
    			ans+=arr[i];
    		}
    		ps.push(arr[i]);
    	}
    	cout<<ans<<"\n";
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

