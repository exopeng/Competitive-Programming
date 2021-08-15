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
const int MAXM=2e3+5;
//store test cases here
/*


*/
int n1,n2;
int m1,m2;
vector<int> adj1[MAXN];
vector<int> adj2[MAXN];
vector<int> adj3[MAXN];
vector<int> adj4[MAXN];
int q;
bool dp[MAXM];
bool dp1[MAXN][MAXM];
bool dp2[MAXN][MAXM];
bool v1[MAXN];
bool v2[MAXN];
vector<int> ord1;
vector<int> ord2;
void dfs(int curr,bool one){
	if(one){
		if(!v1[curr]){
			v1[curr]=true;
			for(int i=0;i<adj1[curr].size();i++){
				dfs(adj1[curr][i],one);
			}
			ord1.pb(curr);
		}
	}else{
		if(!v2[curr]){
			v2[curr]=true;
			for(int i=0;i<adj2[curr].size();i++){
				dfs(adj2[curr][i],one);
			}
			ord2.pb(curr);
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n1>>n2>>m1>>m2;
    for(int i=0;i<m1;i++){
    	int u,v;
    	cin>>u>>v;
    	u--,v--;
    	adj1[u].pb(v);
    	adj3[v].pb(u);
    }
    for(int i=0;i<m2;i++){
    	int u,v;
    	cin>>u>>v;
    	u--,v--;
    	adj2[u].pb(v);
    	adj4[v].pb(u);
    }
    for(int i=0;i<n1;i++){
    	dfs(i,true);
    }
    for(int i=0;i<n2;i++){
    	dfs(i,false);
    }
    reverse(ord1.begin(),ord1.end());
    reverse(ord2.begin(),ord2.end());
    dp1[0][0]=true;
    dp2[0][0]=true;
    for(int i=0;i<ord1.size();i++){
    	for(int j=0;j<adj3[ord1[i]].size();j++){
    		for(int e=1;e<MAXM;e++){
    			if(dp1[adj3[ord1[i]][j]][e-1]){
    				dp1[ord1[i]][e]=dp1[adj3[ord1[i]][j]][e-1];
    			}
    		}
    	}
    }
    for(int i=0;i<ord2.size();i++){
    	for(int j=0;j<adj4[ord2[i]].size();j++){
    		for(int e=1;e<MAXM;e++){
    			if(dp2[adj4[ord2[i]][j]][e-1]){
    			dp2[ord2[i]][e]=dp2[adj4[ord2[i]][j]][e-1];
    			}
    		}
    	}
    }
    //cout<<dp1[n1-1][1]<<" "<<dp2[n2-1][1];
    
    for(int i=0;i<MAXM;i++){
    	for(int j=0;j<MAXM;j++){
    		if(dp1[n1-1][i]&&dp2[n2-1][j]){
    			dp[i+j]=true;
    		}
    	}
    }
    cin>>q;
    for(int i=0;i<q;i++){
    	int a;
    	cin>>a;
    	if(dp[a]){
    		cout<<"Yes"<<"\n";
    	} else{
    		cout<<"No"<<"\n";
    	}
    }
    return 0;
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

