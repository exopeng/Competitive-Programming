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
//first is x coord, ff is horiz(0) or vert(1), fs is y coord
//sort by x,dir,y
vector< pair<int,pii> > arr;
long long ans=0;
//first is y coord, second is x-coord
Tree< pii > ost;
map< pii, pii > taken;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0;i<n;i++) {
    	int a,b,c,d;
    	cin >> a >> b >> c >> d;
    	if (a ==c) {
    		if (b < d) {
    			taken.is(mp( mp(c,d),mp(a,b)));
    			arr.pb(mp(a,mp(1,b)));
    			arr.pb(mp(c,mp(2,d)));
    		} else {
    			taken.is(mp( mp(a,b),mp(c,d)));
    			arr.pb(mp(a,mp(2,b)));
    			arr.pb(mp(c,mp(1,d)));
    		}
    		
    	} else {
    		if (a < c) {
    			taken.is(mp( mp(c,d),mp(a,b)));
    			arr.pb(mp(a,mp(0,b)));
    			arr.pb(mp(c,mp(3,d)));
    		} else {
    			taken.is(mp( mp(a,b),mp(c,d)));
    			arr.pb(mp(a,mp(3,b)));
    			arr.pb(mp(c,mp(0,d)));
    		}
    		
    	}
    }

    //handle horiz last
    sort(arr.begin(),arr.end());
    /*
    for (int i=0;i<2*n;i++) {
    	cout << arr[i].f << " " << arr[i].s.f << " " << arr[i].s.s << "\n";
    }
    */
    for (int i=0;i<2*n;i++) {
    	int a = arr[i].f;
    	int b = arr[i].s.s;
    	if (taken.find(mp(a,b)) != taken.end()) {
  			pii temp = taken[mp(a,b)];
  			if (temp.f==a) {
    			//num less than high y minus num less than low y
    			ans += ost.order_of_key(mp(b,INF))-ost.order_of_key(mp(temp.s,-1*INF));
    		}  
    		ost.erase(mp(temp.s,temp.f));
    	} else {   	
    		if (arr[i].s.f==0) {
    			ost.is(mp(b,a));
    		}
    	}
    }
    cout<<ans << "\n";
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

