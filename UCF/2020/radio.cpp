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
const int MAXN = 1e3+5;
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
    	int dist[MAXN][MAXN];
    	map<double,int> m;
		int n,p,s;
		cin>>n>>p>>s;
		for (int i = 0; i < n; i++) {
	    	for (int j = 0; j < n; j++) {
	    		if (j != i) {
	    			dist[i][j] = INF;
	    		} else {
	    			dist[i][j] = 0;
	    		}
	    	}
	    }
		for(int i=0;i<n;i++){
			double a;
			cin>>a;
			m[a]=i;
		}    	
		for(int i=0;i<n;i++) {
			dist[i][(i+1) % n]=1;
			dist[i][(i-1+n) % n]=1;
		}
		for(int i=0;i<p;i++){
			double a;
			cin>>a;
			for(int j=0;j<n;j++){
				if(j!=m[a]){
					dist[j][m[a]]=1;
				}
			}
		}

	    for (int k = 0; k < n; k++) {
	    	for (int i = 0; i < n; i++) {
	    		for (int j = 0; j < n; j++) {
				     if (dist[i][k] < INF && dist[k][j] < INF)
                	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
	    		}
	    	}
	    }
	    
	    cout<<"Day #" << ct<<":" << "\n";
	    for(int i=0;i<s;i++){
	    	double a,b;
	    	cin>>a>>b;
	    	cout<<dist[m[a]][m[b]]<<"\n";
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

