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
const long long INF = 2e9+10;
const long long MOD = 1e9+7;
const int MAXN = 1e6+10;
//store test cases here
/*


*/
int n;
int p[MAXN];
//multiset<int,greater<int> > ms;
int ans=INF;
int s[MAXN];
int d[MAXN];
int an=0;
vector<int> adj[MAXN];
int ct[MAXN];
int dfs(int v,int pa){
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=pa){
			ct[v]+=dfs(adj[v][i],v);
		}
	}
	//ms.is(ct[v]+p[v]);
	return ct[v]+p[v];
}
void dfs1(int v,int pa){
	int temp=ct[pa];
	int temp1=ct[v];
	//ms.erase(ms.find(ct[v]+p[v]));
	int t2=ct[v]+p[v];
	ct[pa]-=ct[v]+p[v];
	ct[v]+=p[pa]+ct[pa];
	//ms.is(ct[pa]+p[pa]);
	int t1=ct[pa]+p[pa];
	int mn=0;
	for(int i=0;i<adj[v].size();i++){
		mn=max(mn,ct[adj[v][i]]+p[adj[v][i]]);
	}
	if(mn<ans){
		ans=mn;
		an=v;
	}
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i]!=pa){
			dfs1(adj[v][i],v);
		}
	}
	
	//ms.erase(ms.find(t1));
	ct[pa]=temp;
	ct[v]=temp1;
	//ms.is(t2);
}
int LocateCentre(int ns, int ps[], int ss[],int ds[]) {
	ans=INF;
	n=ns;
	copy(ps,ps+n,p);
	//handle n=1 
	if(n==1){
		return 0;
	}
	for(int i=0;i<n-1;i++){
    	adj[ss[i]].pb(ds[i]);
    	adj[ds[i]].pb(ss[i]);
    }
    int mn=0;
    for(int i=0;i<adj[0].size();i++){
    	int ms=dfs(adj[0][i],0);
    	ct[0]+=ms;
    	mn=max(mn,ms);
    }
    ans=mn;
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    return an;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>p[i];
    }
    //handle n=1 
	if(n==1){
		cout<<0<<"\n";
		return 0;
	}
    for(int i=0;i<n-1;i++){
    	cin>>s[i]>>d[i];
    	adj[s[i]].pb(d[i]);
    	adj[d[i]].pb(s[i]);
    }
    int mn=0;
    for(int i=0;i<adj[0].size();i++){
    	int ms=dfs(adj[0][i],0);
    	ct[0]+=ms;
    	mn=max(mn,ms);
    }
    ans=mn;
    for(int i=0;i<adj[0].size();i++){
    	dfs1(adj[0][i],0);
    }
    
    cout<<an<<"\n";
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

