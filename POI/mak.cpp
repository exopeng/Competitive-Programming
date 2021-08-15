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
const int MAXN = 1e4+3;
//store test cases here
/*


*/
double dp[MAXN][100];
int mult[MAXN][100];
pii from[MAXN][100];
vector<int> p = { 1,2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
	               31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
	               73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
	               127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
	               179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
	               233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
	               283, 293, 307, 311, 313, 317, 331, 337, 347, 349
	            };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    cin>>d;
	for(int i=1;i<MAXN;i++){
		mult[i][0]=1;
		from[i][0]=mp(0,0);
	}
    for(int i=0;i<d;i++){
    	int n;
    	cin>>n;
    	for(int j=1;j<=n;j++){
    		for(int e=1;e<p.size();e++){
    			dp[j][e]=dp[j][e-1];
    			mult[j][e]=-1;
    			from[j][e]=mp(j,e-1);
    			double curr=p[e];
    			while(curr<=j){
    				if(dp[j-(int)curr][e-1]+log2(curr) > dp[j][e]){
    					dp[j][e]=dp[j-(int)curr][e-1]+log2(curr);
    					mult[j][e]=curr;
    					from[j][e]=mp(j-(int)curr,e-1);
    				}
    				curr*=p[e];
    			}
    		}
    	}
    	vector<int> ps;
    	int c1=n;
    	int c2=p.size()-1;
    	while(mult[c1][c2]!=0){
    		if(mult[c1][c2]!=-1){
    			ps.pb(mult[c1][c2]);
    		}
    		pii ts=from[c1][c2];
    		c1=ts.f;
    		c2=ts.s;
    	}
    	vector<int> ans;
    	sort(ps.begin(),ps.end());
    	int curr=0;
    	for(int j=0;j<ps.size();j++){
    		for(int e=0;e<ps[j];e++){
    			ans.pb(((e+1) % ps[j])+1+curr);
    		}
    		curr+=ps[j];
    	}
    	for(int j=0;j<n;j++){
    		cout<<ans[j]<<" ";
    	}
    	cout<<"\n";
    	/*
    	for(int j=1;j<=n;j++){
    		for(int e=1;e<p.size();e++){
    			dp[j][e]=0;
    			mult[j][e]=0;
    			from[j][e]=mp(0,0);
    		}
    	}
    	*/
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