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
const int MAXN = 1e5+2;
//store test cases here
/*


*/
int n,m,k;
vector<pii> adj[MAXN];
multiset<long long,greater<long long> > d[MAXN];

void dijkstrapq(int s) {
    d[s].is(0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().s;
        long long d_v = q.top().f;
        q.pop();
        if (d[v].find(d_v)==d[v].end()){
            continue;
        }
        for (auto edge : adj[v]) {
            int to = edge.f;
            int len = edge.s;
            if(d[to].size()==k){
            	if(d_v+len<*d[to].begin()){
            		d[to].erase(d[to].begin());
            		d[to].is(d_v+len);
	            	q.push({d_v+len, to});
            	}
            }else{
            	d[to].is(d_v + len);
	            q.push({d_v + len, to});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	adj[a].pb(mp(b,c));
    }
    dijkstrapq(0);
    vector<long long> temp;
    for(auto it=d[n-1].begin();it!=d[n-1].end();it++){
    	temp.pb(*it);
    }
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
    	cout<<temp[i]<<" ";
    }
    cout<<"\n";
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

