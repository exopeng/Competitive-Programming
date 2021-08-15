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
const long long INF = 1e16;
const long long MOD = 1e9+7;
const int MAXN = 5e2+10;
//store test cases here
/*


*/
int n,m,q;
long long d[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(i==j){
    			d[i][j]=0;
    		}else{
    			d[i][j]=INF;
    		}
    	}
    }
    for(int i=0;i<m;i++){
    	long long a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	d[a][b]=min(d[a][b],c);
    	d[b][a]=min(d[b][a],c);
    }
    for(int k=0;k<n;k++){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if(d[i][j]>d[i][k]+d[k][j]){
    				d[i][j]=d[i][k]+d[k][j];
    			}
    		}
    	}
    }
    for(int i=0;i<q;i++){
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	if(d[a][b]==INF || d[b][a]==INF){
    		cout<<-1<<"\n";
    	}else{
    		cout<<d[a][b]<<"\n";
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

