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
int n;
long long t[4*MAXN];
int arr[MAXN];
long long inv[MAXN];

void build(int curr, int l, int r) {
	if (l == r ) {
		t[curr] = 0;
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
void update(int curr, int tl, int tr, int pos, int val) {
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tree<pii> bit;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	inv[i] = (bit.order_of_key(mp(-1*arr[i],0)));
    	//make sure don't insert multiple elements
    	bit.is(mp(-1*arr[i],i));
    	//cout << inv[i] << " ";
    }

    build(1,0,1e5+1);
   	for (int i = 0; i < n;i++) {
   		ans += sum(1,0,1e5,arr[i]+1,1e5);
   		//
   		update(1,0,1e5,arr[i],sum(1,0,1e5,arr[i],arr[i])+inv[i]);
   	}

   	cout << ans << "\n";
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

