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
#define ll long long
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e3;
//store test cases here
/*


*/
int g[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
    	for(int j=0;j<n;j++){
    		string s;
    		cin>>s;
    		for(int e=0;e<n;e++){
    			g[j][e]=s[e]-'0';
    		}
    	}
    	vector<pii> ts={mp(n-1,n-2),mp(n-2,n-1),mp(n-2,n-2),mp(n-3,n-1),mp(n-1,n-3)};
    	int m1=0;
    	int m0=0;
    	for(int j=0;j<ts.size();j++){
    		if(j<2){
    			if(g[ts[j].f][ts[j].s]==1){
    				m1++;
    			}else{
    				m0++;
    			}
    		}else{
    			if(g[ts[j].f][ts[j].s]==0){
    				m1++;
    			}else{
    				m0++;
    			}
    		}
    	}
    	int c=0;
    	vector<pii> ms;
    	if(m0<m1){	
    		for(int j=0;j<ts.size();j++){
    			if(j<2){
	    			if(g[ts[j].f][ts[j].s]==0){
	    				c++;
	    				ms.pb(ts[j]);
	    			}
	    		}else{
	    			if(g[ts[j].f][ts[j].s]==1){
	    				c++;
	    				ms.pb(ts[j]);
	    			}
	    		}
    		}
    	}else{
    		for(int j=0;j<ts.size();j++){
    			if(j<2){
	    			if(g[ts[j].f][ts[j].s]==1){
	    				c++;
	    				ms.pb(ts[j]);
	    			}
	    		}else{
	    			if(g[ts[j].f][ts[j].s]==0){
	    				c++;
	    				ms.pb(ts[j]);
	    			}
	    		}
    		}
    	}
    	cout<<c<<"\n";
    	for(int j=0;j<ms.size();j++){
    		cout<<(ms[j].f+1)<<" "<<(ms[j].s+1)<<"\n";
    	}
    }
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
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

