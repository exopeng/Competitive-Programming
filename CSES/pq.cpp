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
//lazy segtree
int n,q;
int sz[MAXN];
vector<int> adj[MAXN];
long long t[4*MAXN];
long long arr[MAXN];
vector<long long> isd;
long long val[MAXN];
int id[MAXN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, long long add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

long long get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
int dfs(int v, int p){
	if(p!=-1){
		arr[v]=arr[p]+val[v];
	}else{
		arr[v]=val[v];
	}
	isd.pb(arr[v]);
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
    	cin>>val[i];
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
    		update(1,0,n-1,id[b],id[b]+sz[b],c-val[b]);
    		val[b]=c;
    	}else{
    		int b;
    		cin>>b;
    		b--;
    		cout<<get(1,0,n-1,id[b])<<"\n";
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

