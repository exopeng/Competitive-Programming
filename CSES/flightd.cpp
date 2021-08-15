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
const long long INF = 1000000000000000;
const long long MOD = 1000000007;
const int MAXN = 2e5;

//store test cases here
/*


*/ 
long long ans = 0;
int n,m;
vector< pair<int,int> > adj[MAXN];
long long d[MAXN][2];
int p[MAXN];
void dijkstrapq(int s) {
    for(int i=0;i<n;i++){
        d[i][0]=INF;
        d[i][1]=INF;
        p[i]=-1;
    }
    d[s][0] = 0;
    priority_queue<pair<long long,pii>, vector<pair<long long,pii> >, greater<pair<long long,pii> >> q;
    q.push({0, mp(s,0)});
    while (!q.empty()) {
        int v = q.top().second.first;
        long long d_v = q.top().first;
        int bo = q.top().second.second;
        q.pop();
        if (d_v != d[v][bo])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.f;
            long long len = edge.s;
            if (d[v][bo] + len < d[to][bo]) {
                d[to][bo] = d[v][bo] + len;
                p[to] = v;
                q.push({d[to][bo], mp(to,bo)});
            }
            if(bo==0){
                if (d[v][bo] + len/2 < d[to][1]) {
                    d[to][1] = d[v][bo] + len/2;
                    p[to] = v;
                    q.push({d[to][1], mp(to,1)});
                }
            }
            

        }
    }
}
vector<int> getPath(int source, int dest) {
    vector<int> path;
    int curr = p[dest];
    if (curr == -1) {
        path.push_back(-1);
        return path;
    }
    path.push_back(dest);
    while (curr != source) {
        path.push_back(curr);
        curr = p[curr];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].pb(mp(b,c));
    }
    dijkstrapq(0);
    cout<<d[n-1][1]<<"\n";
    return 0;
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
