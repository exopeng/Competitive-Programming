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
const int INF = 1000000003;
const long long MOD = 1000000007;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,q;
int t[8*MAXN];
int a[MAXN];
pair<int, pii> cq[MAXN];
map<int, int> p;
set<int> poss;
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


int sum(int curr, int tl, int tr, int l, int r) {
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
    cin >> n >> q;
    poss.is(0);
    poss.is(INF);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	poss.is(a[i]);
    }

    for (int i = 0; i < q; i++) {
    	char f;
    	cin >> f;
    	if (f == '?') {
    		cq[i].f = 0;
    		cin >> cq[i].s.f >> cq[i].s.s;
    	} else {
    		cq[i].f = 1;
    		cin >> cq[i].s.f >> cq[i].s.s;
    		cq[i].s.f--;
    		poss.is(cq[i].s.s);
    	}
    }
    int ct = 0;
    for (auto it = poss.begin(); it != poss.end();it++) {
    	//dont count ones not yet found
    	p.is(mp(*it,ct));
    	//cout << "i: " << *it << " ind: " << ct << " ";
    	ct++;
    }

    build(1,0,poss.size() -1);
    //multiple
    for (int i = 0; i < n; i++) {
    	update(1,0,poss.size()-1,p[a[i]],sum(1,0,poss.size()-1,p[a[i]],p[a[i]])+1);
    	//cout << "i: " << p[a[i]] << " ";
    }

    for (int i=0;i<q;i++) {
    	if (cq[i].f == 0) {
    		int lo = p[*poss.lb(cq[i].s.f)];
    		int hi = p[*poss.ub(cq[i].s.s)]-1;
    		//cout << "lo: " << lo << " hi: " << hi << " val: " << sum(1,0,poss.size() - 1,lo,hi) << "\n";
    	    cout << sum(1,0,poss.size() - 1,lo,hi) << "\n";

    	} else {
    		update(1,0,poss.size()-1,p[a[cq[i].s.f]], 
    			sum(1,0,poss.size()-1,p[a[cq[i].s.f]],p[a[cq[i].s.f]])-1);
    		a[cq[i].s.f] = cq[i].s.s;
    		update(1,0,poss.size()-1,p[a[cq[i].s.f]], 
    			sum(1,0,poss.size()-1,p[a[cq[i].s.f]],p[a[cq[i].s.f]])+1);
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

