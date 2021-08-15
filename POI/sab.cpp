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
const int MAXN = 5e5;
//store test cases here
/*


*/
int n,k;
vector<int> adj[MAXN];
int ns[MAXN];
vector<int> lf;
bool vis[MAXN];
int p[MAXN];
int inf=0;
int dfs(int v,int p){
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			ns[v]+=dfs(adj[v][i],v);
		}
	}
	return ns[v]+1;
}
void dfs1(int v,double x){
	if(!vis[v]){
		vis[v]=true;
		inf=ns[v]+1;
		if((double)(ns[v]+1)/ns[p[v]]>=x){
			dfs1(p[v],x);
		}
	}
}
bool work(double mid){
	int ans=0;
	for(int i=0;i<n;i++){
		vis[i]=false;
	}
	for(int i=0;i<lf.size();i++){
		dfs1(lf[i],mid);
		ans=max(ans,inf);
		inf=0;
	}
	if(ans>k){
		return false;
	}
	return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
    	int a;
    	cin>>a;
    	a--;
    	adj[a].pb(i+1);
    	p[i+1]=a;
    }
    for(int i=0;i<n;i++){
    	if(adj[i].size()==0){
    		lf.pb(i);
    	}
    }
    dfs(0,-1);
    double lo=0;
    double hi=1;
    while(hi-lo>=((double)1/100000000)){
    	double mid=(lo+hi)/2;
    	if(work(mid)){
    		hi=mid;
    	}else{
    		lo=mid;
    	}
    	//cout<<mid<<"\n";
    }
    cout<<setprecision(9) << lo<<"\n";
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

