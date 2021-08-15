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
const int MAXN = 1e5+1;
//store test cases here
/*


*/
int path[MAXN];
vector<int> adj[MAXN];
int n,m;
void bfs() {
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int curr=q.front();
		q.pop();
		for(int i=0;i<adj[curr].size();i++){
			if(path[adj[curr][i]]==-1) {
				path[adj[curr][i]]=curr;
				q.push(adj[curr][i]);
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++) {
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    for(int i=0;i<n;i++){
    	path[i]=-1;
    }
    path[0]=0;
    bfs();
   	vector<int> p;
   	if (path[n-1]==-1) {
   		cout<<"IMPOSSIBLE"<<"\n";
   	} else {
   		int curr = n-1;
   		p.pb(n-1);
   		while(path[curr]!=curr) {
   			p.pb(path[curr]);
   			curr = path[curr];
   		}
   		cout<<p.size()<<"\n";
   		for(int i=p.size()-1;i>-1;i--){
   			cout<<p[i]+1<<" ";
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

