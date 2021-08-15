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
int n,q;
int t[4*MAXN];
int a1[MAXN];
int a2[MAXN];
int arr[MAXN];
pii lt[MAXN];
vector< pair< pair<int,pii>,pii > > val; 
pair< pii,pii > qu[MAXN];


//first.first is the l2, first.second is the index, second.first is the l1, second.second is the r1, int is the index of query 



void build(int curr, int l, int r) {
	if (l == r ) {
		t[curr] = 1;
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
    cin >>n;
    for (int i=0;i<n;i++) {
    	cin>>a1[i];
    }
    map<int,int> p;

    for (int i=0;i<n;i++) {
    	cin>>a2[i];
    	p.is(mp(a2[i],0));
    }
    for (int i=0;i<n;i++){
    	p[a1[i]]=i;
    }
    /*
    for (auto it=p.begin();it!=p.end();it++) {
    	cout << it->first << ":" << it->second<<"\n";
    }
	*/
    cin>>q;
    for(int i=0;i<q;i++){
    	cin>> qu[i].f.f>>qu[i].f.s>>qu[i].s.f>>qu[i].s.s;
    	qu[i].f.f--,qu[i].f.s--,qu[i].s.f--,qu[i].s.s--;
    	val.pb(mp(mp(qu[i].s.f,mp(0,i)),mp(qu[i].f.f,qu[i].f.s)));
    	val.pb(mp(mp(qu[i].s.s+1,mp(1,i)),mp(qu[i].f.f,qu[i].f.s)));
    }

    sort(val.begin(),val.end());
    int last = 0;
    build(1,0,n-1);
    for (int i=0;i<val.size();i++) {
    	//cout<<val[i].f.f<<" q:"<<val[i].s.f<<"-"<<val[i].s.s<<"\n";
    	while (last < val[i].f.f) {
    		//cout<<p[a2[last]]<<"\n";
    		update(1,0,n-1,p[a2[last]],0);
    		last++;
    	}
    	if (val[i].f.s.f==0) {
    		lt[val[i].f.s.s].f=sum(1,0,n-1,val[i].s.f,val[i].s.s);
    		//cout << "val: " << lt[val[i].f.s.s].f << "\n";
    	} else {
    		lt[val[i].f.s.s].s=sum(1,0,n-1,val[i].s.f,val[i].s.s);
    		//cout << "val: " << lt[val[i].f.s.s].s << "\n";
    	}
    }
    for (int i=0;i<q;i++) {
    	cout << qu[i].f.s - qu[i].f.f + 1 - (lt[i].f-lt[i].s) <<"\n";
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

