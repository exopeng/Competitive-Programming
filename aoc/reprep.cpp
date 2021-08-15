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
long long ans=0;
vector<pair<pii,pair<char,string> > > nums;
set<int> rem;
int main() {

    ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("test.in","r",stdin);
    for(int i=0;i<1000;i++){
    	pair<pii,pair<char,string> > curr;
    	cin>>curr.f.f;
    	char temp;
    	cin>>temp;
    	cin>>curr.f.s;
    	cin>>curr.s.f;
    	cin>>temp;
    	cin>>curr.s.s;
    	nums.pb(curr);
    	//cout<<curr.f.f<<" "<<curr.f.s<<" "<<curr.s.f<<" "<<curr.s.s<<"\n";
    }
    for(int i=0;i<nums.size();i++){
    	int occ=0;
    	int lo=nums[i].f.f;
    	int hi=nums[i].f.s;
    	char te=nums[i].s.f;
    	string t=nums[i].s.s;
    	if(t[lo-1]==te && t[hi-1]!=te || t[lo-1]!=te && t[hi-1]==te) {
    		ans++;
    	}
    }
    cout << ans;
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

