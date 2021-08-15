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
int n;
vector<int> adj[MAXN];
int dp[MAXN];
int ans;
multiset<int,greater<int> > ms[MAXN];
int dfs(int v,int p){
	//has to end in different isection
	//cout<<v<<"\n";
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			int c = dfs(adj[v][i],v);
			ms[v].is(c);
		}
	}
	if(p==-1){
		dp[v]=*ms[v].begin()+adj[v].size()-1;
	}else{
		if(ms[v].size()>0){
			dp[v]=max(adj[v].size()-1,*ms[v].begin()+adj[v].size()-2);
		}else{
			dp[v]=adj[v].size()-1;
		}
	}
	return dp[v];
}

void dfs1(int v, int p){
	int t1=dp[v];
	int t2=dp[p];
	ms[p].erase(ms[p].find(dp[v]));
	//log fac
	if(ms[p].size()>0){
		dp[p]=max(*ms[p].begin()+adj[p].size()-2,adj[p].size()-1);
	}else{
		dp[p]=adj[p].size()-1;
	}
	ms[v].is(dp[p]);
	dp[v]=*ms[v].begin()+adj[v].size()-1;
	ans=max(ans,dp[v]);
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			dfs1(adj[v][i],v);
		}
	}
	ms[p].is(t1);
	ms[v].erase(ms[v].find(dp[p]));
	dp[v]=t1;
	dp[p]=t2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ans=0;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    //cout<<1;
    ans=max(ans, dfs(0,-1));
    
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    
    cout<<ans<<"\n";
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

