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
const int MAXN = 3e5+10;
//store test cases here
/*


*/
long long n,k;
vector<int> adj[MAXN];
int a[MAXN];
pii dp[MAXN];
int ans[MAXN];
bool vis[MAXN];
pair<pii,pii> mx[MAXN];
pii dfs(int v, int p){
	mx[v].f={-1*INF,INF};
	mx[v].s=mx[v].f;
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			pii cur=dfs(adj[v][i],v);
			if(cur.f>mx[v].f.f||(cur.f==mx[v].f.f&&cur.s<mx[v].f.s)){
				mx[v].s=mx[v].f;
				mx[v].f=cur;
			}else if(cur.f>mx[v].s.f||(cur.f==mx[v].s.f&&cur.s<mx[v].s.s)){
				mx[v].s=cur;
			}
		}
	}
	dp[v]=mx[v].f;
	if(a[v]>dp[v].f||(a[v]==dp[v].f&&v<dp[v].s)){
		return mp(a[v]-1,v);
	}
	return mp(dp[v].f-1,dp[v].s);
}
void dfs1(int v, int p){
	pii cur=dp[v];
	pii t1=mx[v].f;
	pii t2=mx[v].s;
	pii ms=mx[p].f;
	if(ms.s==v){
		ms=mx[p].s;
	}
	ms.f--;
	if(ms.f>mx[v].f.f||(ms.f==mx[v].f.f&&ms.s<mx[v].f.s)){
		mx[v].s=mx[v].f;
		mx[v].f=ms;
	}else if(ms.f>mx[v].s.f||(ms.f==mx[v].s.f&&ms.s<mx[v].s.s)){
		mx[v].s=ms;
	}
	ms=mp(a[p]-1,p);
	if(ms.f>mx[v].f.f||(ms.f==mx[v].f.f&&ms.s<mx[v].f.s)){
		mx[v].s=mx[v].f;
		mx[v].f=ms;
	}else if(ms.f>mx[v].s.f||(ms.f==mx[v].s.f&&ms.s<mx[v].s.s)){
		mx[v].s=ms;
	}
	dp[v]=mx[v].f;
	ans[v]=dp[v].s;
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			dfs1(adj[v][i],v);
		}
	}
	dp[v]=cur;
	mx[v].f=t1;
	mx[v].s=t2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
    	int b,c;
    	cin>>b>>c;
    	b--,c--;
    	adj[b].pb(c);
    	adj[c].pb(b);
    }
    dfs(0,-1);
    ans[0]=dp[0].s;
    
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    /*
    for(int i=0;i<n;i++){
    	cout<<dp[i].f<<" "<<dp[i].s+1<<"\n";
    }
    */
    
    for(int i=0;i<n;i++){
    	cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
    
    
    vector<int> path;
    int cur=0;
    while(!vis[cur]){
    	vis[cur]=true;
    	path.pb(cur);
    	cur=ans[cur];
    }
    int en=-1;
    int cyc=0;
    for(int i=0;i<path.size();i++){
    	if(path[i]==cur){
    		en=i;
    		cyc=path.size()-i;
    		break;
    	}
    }
    if(en==0){
	    cout<<path[k%cyc]+1<<"\n";
    }else{
    	if(k<path.size()){
	    	cout<<path[k]+1<<"\n";
	    }else{
	    	k-=en;
	    	k%=cyc;
	    	cout<<path[en+k]+1<<"\n";
	    }
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

