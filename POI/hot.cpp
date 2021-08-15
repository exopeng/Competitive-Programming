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
const int MAXN = 5e3+1;
//store test cases here
/*


*/
int n;
vector<int> adj[MAXN];
map<int,int> d[MAXN];
long long ans=0;
void dfs(int v, int p){
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			dfs(adj[v][i],v);
			for(auto it=d[adj[v][i]].begin();it!=d[adj[v][i]].end();it++){
				d[v][it->f+1]+=d[adj[v][i]][it->f];
			}
			d[v][1]++;
		}
	}
}
void dfs1(int v, int p){

}
int ts[MAXN];
long long xs[MAXN];
void ct(int v){
	map<int,int> ts;
    map<int,int> xs;
    if(adj[0].size()>=3){
    	for(int i=0;i<adj[0].size();i++){
    		for(auto it=d[adj[0][i]].begin();it!=d[adj[0][i]].end();it++){
    			ts[it->f]++;
    		}
	    }
	    for(int i=0;i<adj[0].size();i++){
    		for(auto it=d[adj[0][i]].begin();it!=d[adj[0][i]].end();it++){
    			if(ts[it->f]>=3){
    				if(xs.find(it->f)==xs.end()){
    					xs[it->f]=it->s;
    				}else{
    					xs[it->f]*=it->s;
    				}
    			}
    		}
	    }
	    for(auto it=xs.begin();it!=xs.end();it++){
	    	ans+=it->s;
	    }
    }
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
    dfs(0,-1);
    
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

