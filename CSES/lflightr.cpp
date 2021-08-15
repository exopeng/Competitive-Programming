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
const int MAXN = 1e5+5;
//store test cases here
/*


*/
int n,m;
vector<int> adj[MAXN];
vector<int> adj1[MAXN];

int d[MAXN];
int p[MAXN];
bool v[MAXN];
vector<int> ord;
void dfs(int curr){
	if(!v[curr]){
		v[curr]=true;
		for(int i=0;i<adj[curr].size();i++){
			dfs(adj[curr][i]);
		}
		ord.pb(curr);
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj1[b].pb(a);
    }
    for(int i=0;i<n;i++){
    	dfs(i);
    }
    reverse(ord.begin(),ord.end());
    d[0]=1;
    for(int i=0;i<ord.size();i++){
    	for(int j=0;j<adj1[ord[i]].size();j++){
    		if(d[adj1[ord[i]][j]]==0){
    			continue;
    		}
    		if(d[adj1[ord[i]][j]]+1>d[ord[i]]){
    			d[ord[i]]=d[adj1[ord[i]][j]]+1;
    			p[ord[i]]=adj1[ord[i]][j];
    		}
    	}
    }
    if(d[n-1]==0){
    	cout<<"IMPOSSIBLE"<<"\n";
    } else{
    	cout<<d[n-1]<<"\n";
    	vector<int> path;
    	int last=n-1;
    	for(int i=0;i<d[n-1];i++){
    		path.pb(last);
    		last=p[last];
    	}
    	reverse(path.begin(),path.end());
    	for(int i=0;i<path.size();i++){
    		cout<<path[i]+1<<" ";
    	}
    	cout<<"\n";
    }

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

