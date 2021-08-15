#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pii pair<int,int>
#define is insert
const long long INF = 1000000001;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/
int t[4*MAXN];
int arr[MAXN];
int n,q;
void build(int curr, int l, int r) {
	if (l == r ) {
		t[curr] = arr[l];
	} else {
		int mid = (r + l) / 2;
		//an edge's two children are the indices 2i && 2i+1
		//in this sum segtree, an edge's value is the values from it's left to right indices
		build(curr * 2, l, mid);
		build(curr*2 + 1, mid + 1, r);
		t[curr] = min(t[curr*2],t[curr*2+1]);
	}
}
//tl-tr is the current segment, and l-r is the desired segment
int sum(int curr, int tl, int tr, int l, int r) {
	if (l > r) {
		return INF;
	}
	if (l == tl && r == tr) {
		return t[curr];
	}
	int mid = (tl + tr) / 2;
	//taking min of r and mid, because mid might be greater than r, same for max
	return min(sum(curr*2, tl, mid, l, min(r,mid)),sum(curr*2+1, mid +1, tr, max(l,mid+1), r));
}

void update(int curr, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[curr] = val;
	} else {
		int mid = (tl+tr) / 2;
		//see which segment the index falls in, and change it
		if (pos <= mid) {
			update(curr*2, tl, mid, pos, val);
		} else {
			update(curr*2+1, mid+1, tr, pos, val);
		}
		//update the curr segmment to the new val once everything below it has been updated properly
		t[curr] = min(t[curr*2],t[curr*2+1]);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    build(1,0,n-1);
    for (int i = 0; i < q; i++) {
    	int a,b,c;
    	cin >> a >> b >> c;
    	if (a == 1) {
    		b--;
    		update(1,0,n-1,b,c);
    	} else {
    		b--,c--;
    		cout << sum(1,0,n-1,b,c) << "\n";
    	}
    }

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

