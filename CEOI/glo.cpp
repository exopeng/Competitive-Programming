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
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
//store test cases here
/*


*/
int n,x;
vector<int> a;
vector<int> d;
vector<int> r;

int f[MAXN];
int b[MAXN];

int l[MAXN];

vector<pii> sor;

int t[4*MAXN];

void build(int curr, int left, int right) {
	if (left == right ) {
		t[curr] = 0;
	} else {
		int mid = (right + left) / 2;
		//an edge's two children are the indices 2i && 2i+1
		//in this sum segtree, an edge's value is the values from it's left to right indices
		build(curr * 2, left, mid);
		build(curr*2 + 1, mid + 1, right);
		t[curr] = max(t[curr*2],t[curr*2+1]);
	}
	//cout << "tl: " << left << " tr: " << right << " val: " << t[curr] << "\n";

}

//tl-tr is the current segment, and l-r is the desired segment
int sum(int curr, int tl, int tr, int left, int right) {
	if (left > right) {
		return 0;
	}
	if (left == tl && right == tr) {
		return t[curr];
	}

	int mid = (tl + tr) / 2;
	//taking min of r and mid, because mid might be greater than r, same for max
	return max(sum(curr*2, tl, mid, left, min(right,mid)), sum(curr*2+1, mid +1, tr, max(left,mid+1), right));
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
		t[curr] = max(t[curr*2],t[curr*2+1]);
	}
	//cout << "tl: " << tl << " tr: " << tr << " val: " << t[curr] << "\n";
}

int bsearch(int a) {
	int lo = 0;
	int hi = n-1;
	while (lo != hi) {
		int mid = (lo+hi)/2;
		if (r[mid] < a) {
			hi = mid;
		} else {
			lo = mid+1;
		}
		//cout << lo << "\n";
	} 
	return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
    	int m;
    	cin >> m;
    	a.pb(m);
    	sor.pb(mp(m,i));
    	d.pb(INF);
     	r.pb(-1*INF);
    }
    d.pb(INF);
    d[0] = -1*INF;
    r.pb(-1*INF);
    r[0] = INF;
    for (int i = 0; i < n; i++) {
    	int ind = lower_bound(d.begin(),d.end(),a[i]+1) - d.begin();
    	if (d[ind-1] < a[i] && a[i] < d[ind]) {
            d[ind] = a[i];
            f[i] = ind;
    	} else {
    		f[i] = 1;
    	}
    	//cout << "i: " << i << " val: " << f[i] << "\n";
    }
    
    for (int i = n-1; i > -1; i--) {
    	int ind = bsearch(a[i]-1);
    	if (r[ind] < a[i] && a[i] <= r[ind-1]) {
            r[ind] = a[i]-1;
            b[i] = ind;
    	} else {
    		b[i] = 1;
    	}
    	//cout << "i: " << i << " val: " << b[i] << "\n";
    }
	
    int ans = 0;
    for (int i = 0; i <= n; i++) {
    	if (d[i] < INF) {
    		ans = i;
    	}
    }    
   	//empty segtree with size n, point update each time, query minimum in a range
   	//find first index that is geq and last index that is leq
   	//put elements in set afterwards, and map each element to an index in sorted segtree
   	map< pii, int> p;
   	sort(sor.begin(), sor.end());
   	for (int i = 0; i < n; i++) {
   		p.insert(mp(sor[i],i));
   		//cout << "(" << sor[i].first << "," << sor[i].second << ") i: " << i << "\n";
   	}
   	
   	build(1,0,n-1);
		
   	set<pii> taken;
   	//insert beg
   	taken.insert(mp(INF, n));
   	taken.insert(mp(-1*INF, -1*INF));
   	taken.insert(mp(a[0], p[mp(a[0],0)]));
   	update(1,0,n-1,p[mp(a[0],0)],f[0]);
   	//cout << sum(1,0,n-1,5,6) << "\n";
   	
    for (int i = 1; i < n; i++) {
    	int lo = taken.lower_bound(mp(a[i],0))->second;
    	int hi = taken.lower_bound(mp(a[i]+x,0))->second;
    	//cout << "i:" << i << " a[i]:" << a[i] << " lo:" << lo << " hi:" << hi << " sum: " << sum(1,0,n-1,lo,hi-1) << "\n";
    	ans = max(ans,sum(1,0,n-1,lo,hi-1) + b[i]);
    	taken.insert(mp(a[i], p[mp(a[i],i)]));
    	update(1,0,n-1,p[mp(a[i],i)],f[i]);
    	//cout << "ind: " << p[mp(a[i],i)] << " f[i] " << f[i] << "\n";
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

