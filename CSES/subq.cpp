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
long long t[4*MAXN];
long long arr[MAXN];
int n,q;
int va[MAXN];
vector<int> adj[MAXN];
int sz[MAXN];
int id[MAXN];
vector<int> isd;
void build(int curr, int l, int r) {
	if (l == r ) {
		t[curr] = arr[l];
	} else {
		int mid = (r + l) / 2;
		build(curr * 2, l, mid);
		build(curr*2 + 1, mid + 1, r);
		t[curr] = t[curr*2] + t[curr*2+1];
	}
}
long long sum(int curr, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (l == tl && r == tr) {
		return t[curr];
	}
	int mid = (tl + tr) / 2;
	return sum(curr*2, tl, mid, l, min(r,mid)) + sum(curr*2+1, mid +1, tr, max(l,mid+1), r);
}
void update(int curr, int tl, int tr, int pos, long long val) {
	if (tl == tr) {
		t[curr] = val;
	} else {
		int mid = (tl+tr) / 2;
		if (pos <= mid) {
			update(curr*2, tl, mid, pos, val);
		} else {
			update(curr*2+1, mid+1, tr, pos, val);
		}
		t[curr] = t[curr*2] + t[curr*2+1];
	}
}
int dfs(int v, int p){
	isd.pb(va[v]);
	id[v]=isd.size()-1;
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p){
			sz[v]+=dfs(adj[v][i],v);
		}
	}
	return sz[v]+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	cin>>va[i];
    }
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    dfs(0,-1);
    for(int i=0;i<isd.size();i++){
    	arr[i]=isd[i];
    }
    build(1,0,n-1);
    for(int i=0;i<q;i++){
    	int a;
    	cin>>a;
    	if(a==1){
    		int b,c;
    		cin>>b>>c;
    		b--;
    		update(1,0,n-1,id[b],c);
    	}else{
    		int b;
    		cin>>b;
    		b--;
    		cout<<sum(1,0,n-1,id[b],id[b]+sz[b])<<"\n";
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

