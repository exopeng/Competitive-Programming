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
const long long INF = 2e9+5;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,m;
set<int> cell;
vector<int> cit;
int l=-1*(1e9+5);
int r=1e9+5;
int check(){
	int mn = 0;
	for(int i=0;i<n;i++){
		auto it=cell.lb(cit[i]);
		auto it1=prev(cell.lb(cit[i]));
		int dist = INF;
		if(*it != l && *it != r) {
			dist = *it - cit[i];
		} 
		if(*it1 != l && *it1 != r){
			dist = min(dist,cit[i]- *it1);
		}
		mn=max(mn,dist);
	}
	return mn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cell.is(l);
    cell.is(r);
    for(int i=0;i<n;i++){
    	int a;
    	cin>>a;
    	cit.pb(a);
    }
    for(int i=0;i<m;i++){
    	int a;
    	cin>>a;
    	cell.is(a);
    }
    //just iterate through all and for each check min dist
    //ans is max of all

    cout<<check()<<"\n";
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

