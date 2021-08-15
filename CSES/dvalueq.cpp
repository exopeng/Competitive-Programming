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
const int MAXN = 2e5+1;
//store test cases here
/*


*/
int n,q;
int arr[MAXN];
int el[MAXN];
pair<pii,int> qu[MAXN];
int t[4*MAXN];
int ans[MAXN];
void build(int curr, int l, int r) {
	if (l == r ) {
		t[curr] = arr[l];
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
    cin>>n>>q;
    map<int,queue<int> > p;
    for (int i=0;i<n;i++) {
    	int bi;
    	cin >>bi;
    	el[i]=bi;
    	if(p.find(bi) != p.end()) {
    		p[bi].push(i);
    	} else {
    		queue<int> temp;
    		temp.push(i);
    		p.is(mp(bi,temp));
    		arr[i]++;
    	}
    }

    build(1,0,n-1);
    for (int i=0;i<q;i++) {
    	int a,b;
    	cin>>a>>b;
    	a--,b--;
    	qu[i]=mp(mp(a,b),i);
    }
    sort(qu,qu+q);
    int last = 0;
    int pt=qu[last].f.f;
    for (int i=0;i<n;i++) {
    	//cout << qu[i].f.f << " " << qu[i].f.s<<" "<<"\n";
    	if (pt > i) {
    	} else {
    		int a=qu[last].f.f;
    		int b=qu[last].f.s;
    		ans[qu[last].s]=sum(1,0,n-1,a,b);
    		last++;
    		if (last >= q) {
    			break;
    		}
    		if (qu[last].f.f==pt) {
    			i--;
    			continue;
    		}
    		pt = qu[last].f.f;
    	}
    	int ind = p[el[i]].front();
		p[el[i]].pop();
		//cout << ind<< " "<<"\n";
		update(1,0,n-1,ind,-1);
    	if (!p[el[i]].empty()) {
			ind = p[el[i]].front();
			update(1,0,n-1,ind,1);
    	}
    }
    for (int i=0;i<q;i++) {
    	cout << ans[i] << "\n";
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

