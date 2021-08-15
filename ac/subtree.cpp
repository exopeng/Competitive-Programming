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
#define pdd pair<double,double>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
long long n,m;
vector<int> adj[MAXN];
vector<long long> ps[MAXN];
vector<long long> ss[MAXN];
int ans[MAXN];
long long dp[MAXN];
int pa[MAXN];
map<int,int> ms;
int dfs(int v, int p){
	dp[v]=1;
	vector<int> st;
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			st.pb(1+dfs(adj[v][i],v));
			ms[adj[v][i]]=st.size()-1;
			pa[adj[v][i]]=v;
		}
	}
	for(int i=0;i<st.size();i++){
		dp[v]=(dp[v]*(st[i]))%m;
		ps[v].pb(dp[v]);
		ss[v].pb(0);
	}

	for(int i=st.size()-1;i>-1;i--){
		if(i==st.size()-1){
			ss[v][i]=st[i];
		}else{
			ss[v][i]=(st[i]*ss[v][i+1]) % m;
		}
	}
	return dp[v];
}

void dfs1(int v, int p){
	int t1=dp[p];
	int t2=dp[v];
	dp[p]=1;
	int ix=ms[v];
	//calc p/s sum, current is n^2
	//prefix sum not updated...
	//store multiple with parent
	if(ix!=0){
		dp[p]=ps[p][ix-1];
	}
	if(ix!=ss[p].size()-1){
		dp[p]=(dp[p]*ss[p][ix+1]) % m;
	}
	if(p!=0){
		dp[p]=(dp[p]*(dp[pa[p]]+1))%m;
	}
	dp[v]=(dp[v]*(1+dp[p]))%m;
	ans[v]=dp[v];
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			dfs1(adj[v][i],v);
		}
	}
	dp[p]=t1;
	dp[v]=t2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    ans[0]=dfs(0,-1);
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<"\n";
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


