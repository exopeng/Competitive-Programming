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
const long long INF = 1000000000;
const long long MOD = 30013;
//store test cases here
/*


*/
int n;
pii d[100002];
pii ds[100002];
set< pair< pii ,long long> > ct[100002]; 
pair< pii , pii > a[100001];

bool cmp(const pii& a, cont pii& b) {
	return a.f < b.f && a.s < b.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
    	//a_i,b_i,c_i, d_i
    	cin >> a[i].f.f >> a[i].s.f >> a[i].f.s >> a[i].s.s >> ;
    	d[i].f = INF;
    	d[i].s = INF:
    	/*
    	ds[i].f = INF;
    	ds[i].s = INF:
    	*/
    }
    d[n].f = INF;
    d[n].s =INF;
    /*
    ds[n].f = INF;
    ds[n].s =INF;
	*/
    d[0].f = -1*INF;
    d[0].s = -1*INF;
    /*
    ds[0].f = -1*INF;
    ds[0].s = -1*INF;
	*/
    ct[0].is(mp(mp(-1*INF,-1*INF), 1));
    //define sorting crit?

    for (int i = 0; i < n; i++) {
    	//minimize dist between trapezoids
    	int ind = ub(d.begin(),d.end(), a[i].f, cmp) - d.begin();
    	if (d[ind-1].f < a[i].f.f && d[ind-1].s < a[i].f.s 
    		&& a[i].s.f < d[ind].f && a[i].s.s < d[ind].s) {
            d[ind].f = a[i].s.f;
        	d[ind].s = a[i].s.s;
        	//find all the ones before that are lower than it and add to it
        	int num = 0;
        	for (auto it = ct[ind-1].begin(); it != ct[ind-1].end(); it++) {
        		if (it.f.f < a[i].f.f && it.f.s < a[i].f.s) {
        			num += it.s;
        		}
        	}
        	ct[ind].is(mp(a[i].s, num));
    	}
    		
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
    	if (d[i].f < INF) {
    		ans = i;
    	}
    }
    int tot = lb(ct[ans].begin(),ct[ans].end(), mp(mp(d[ans].f,d[ans].s, 0) ))->s;

    cout << ans << tot << "\n";
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

