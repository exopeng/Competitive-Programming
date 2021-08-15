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
int n,q;
vector<int> adj[MAXN];
int timer = 0, tin[MAXN], euler_tour[2*MAXN];
int segtree[8*MAXN]; 

void dfs(int node = 0, int parent = -1) {
   tin[node] = timer; // The time when we first visit a node
   euler_tour[timer++] = node;
   for (int i : adj[node]) {
      if (i != parent) {
          dfs(i, node);
          euler_tour[timer++] = node;
     }
  }
}

int mn_tin(int x, int y) {
  if (x == -1) return y;
  if (y == -1) return x;
  return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running `dfs()`
void build(int node = 1, int l = 0, int r = timer - 1) {
  if (l == r) segtree[node] = euler_tour[l];
  else {
      int mid = (l + r) / 2;
      build(node * 2, l, mid);
      build(node * 2 + 1, mid + 1, r);
      segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
  }
}
  
int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
  if (l > b || r < a) return -1;
  if (l >= a && r <= b) return segtree[node];
  int mid = (l + r) / 2;
  return mn_tin(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run `dfs()` and `build()` before you run this
int lca(int a, int b) {
  if (tin[a] > tin[b]) swap(a, b);
  return query(tin[a], tin[b]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
    	int a;
    	cin>>a;
    	a--;
    	adj[a].pb(i+1);
    	adj[i+1].pb(a);
    }
    dfs();
    build();
    for(int i=0;i<q;i++){
    	int a,b;
    	cin>>a>>b;
    	cout<<lca(a-1,b-1)+1<<"\n";
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

