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
const long long INF = 100000000000000000;
const long long MOD = 1000000007;
const int MAXN = 2e5+1;
int n,m;
//store test cases here
/*


*/

long long d[MAXN];
pair<pair<long long, long long>,long long> minmaxnum[MAXN];
vector< pair<int,int> > adj[MAXN];

void dijkstrapq(int s) {
    for (int i = 0; i < n; i++) {
    	d[i] = INF;
    	minmaxnum[i].f.f = INF;
    	minmaxnum[i].f.s = 0;
    	minmaxnum[i].s = 0;
    }

    d[s] = 0;
    minmaxnum[s].f.f = 0;
    minmaxnum[s].f.s = 0;
    minmaxnum[s].s = 1;
    priority_queue< pair<long long,int> , vector< pair<long long, int> >, greater< pair<long long,int> > > q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        long long d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            //check neg?
            if (d[v] + len == d[to]) {
                minmaxnum[to].s = (minmaxnum[to].s + minmaxnum[v].s) % MOD;
                minmaxnum[to].f.f = min(minmaxnum[to].f.f,minmaxnum[v].f.f + 1);
                minmaxnum[to].f.s = max(minmaxnum[to].f.s, minmaxnum[v].f.s + 1);
            } else if (d[v] + len < d[to]) {
                //mod?
            	d[to] = d[v] + len;
            	minmaxnum[to].s = minmaxnum[v].s;
            	minmaxnum[to].f.f = minmaxnum[v].f.f+1;
            	minmaxnum[to].f.s = minmaxnum[v].f.s+1;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++) {
    	int a,b,c;
    	cin >> a >> b >>c;
    	a--,b--;
    	adj[a].pb(mp(b,c));
    }

    dijkstrapq(0);
    cout << d[n-1] << " " << minmaxnum[n-1].s << " " << minmaxnum[n-1].f.f << 
    " " << minmaxnum[n-1].f.s << "\n";
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

