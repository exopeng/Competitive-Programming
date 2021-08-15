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
int ans=0;
vector<int> adj[MAXN];
long long ds[MAXN];
long long as[MAXN];
long long ss[MAXN];
long long dfs(int v,int p){
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			ds[v]+=dfs(adj[v][i],v)+ss[adj[v][i]];
		}
	}
	return ds[v];
}
long long dfs2(int v,int p) {
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            ss[v]+=dfs2(adj[v][i],v);
        }
    }
    ss[v]++;
    return ss[v];
}
void dfs1(int v,int p){
    long long t1=ds[p];
    long long t2=ds[v];
    long long t3=ss[p];
    long long t4=ss[v];
    ds[p]-=t2+ss[v];
    //add number of subnodes
    ds[v]+=ds[p]+ss[p]-(ss[v]);
    as[v]=ds[v];
    ss[p]-=ss[v];
    ss[v]+=ss[p];
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]!=p){
            dfs1(adj[v][i],v);
        }
    }
    ds[p]=t1;
    ds[v]=t2;
    ss[v]=t4;
    ss[p]=t3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    dfs2(0,-1);

    dfs(0,-1);
    as[0]=ds[0];
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    for(int i=0;i<n;i++){
        cout<<as[i]<<" ";
    }
    cout<<"\n";
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

