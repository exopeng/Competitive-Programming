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
const int MAXN = 2e5;
//store test cases here
/*


*/
int n;
int orig[MAXN];
long long ans=0;
vector<int> adj[MAXN];
void dfs(int v,int last){
	if(orig[v]==v){
		//after handling all children, if still untouched, exchange with parent
		for(int i=0;i<adj[v].size();i++){
			if(adj[v][i]!=last){
				dfs(adj[v][i],v);
			}
		}
		if(orig[v]==v){
			if(v==last){
				for(int i=0;i<adj[v].size();i++){
					if(adj[v][i]!=last){
						swap(orig[v],orig[adj[v][i]]);
						ans+=2;
						break;
					} 
				}
			} else{
				swap(orig[last],orig[v]);
				ans+=2;
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //check edge case of n=2

    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    } 
    /*
    if(n==2){
    	cout<<2<<"\n";
    	cout<<"2 1"<<"\n";
    }
    */
    for(int i=0;i<n;i++){
    	orig[i]=i;
    }
    dfs(0,0);
    /*
    for(int i=0;i<n;i++){
    	dfs(i,i);
    }
    */
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
    	if(i==n-1){
    		cout<<orig[i]+1<<"\n";
    	} else{
    		cout<<orig[i]+1<<" ";
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

