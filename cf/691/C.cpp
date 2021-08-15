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
#define pdd pair<double,double>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e3+10;
//store test cases here
/*


*/
bool vis[MAXN][MAXN][2];
bool act[MAXN][MAXN];
int n;
int ans=0;
void bfs(){
	queue<pair<pair<int,bool>,pii> > q;
	q.push(mp(mp(0,true),mp(1000,1000)));
	q.push(mp(mp(0,false),mp(1000,1000)));
	while(!q.empty()){
		pair<pair<int,bool>,pii> cur=q.front();
		q.pop();
		if(cur.f.f==n){
			if(!act[cur.s.f][cur.s.s]){
				ans++;
				act[cur.s.f][cur.s.s]=true;
			}
			continue;
		}
		if(cur.f.s){
			if(vis[cur.s.f][cur.s.s+1][!cur.f.s]==false){
				vis[cur.s.f][cur.s.s+1][!cur.f.s]==true;
				q.push(mp(mp(cur.f.f+1,!cur.f.s),mp(cur.s.f,cur.s.s+1)));
			}
			if(vis[cur.s.f][cur.s.s-1][!cur.f.s]==false){
				vis[cur.s.f][cur.s.s-1][!cur.f.s]==true;
				q.push(mp(mp(cur.f.f+1,!cur.f.s),mp(cur.s.f,cur.s.s-1)));
			}
		}else{
			if(vis[cur.s.f+1][cur.s.s][!cur.f.s]==false){
				vis[cur.s.f+1][cur.s.s][!cur.f.s]==true;
				q.push(mp(mp(cur.f.f+1,!cur.f.s),mp(cur.s.f+1,cur.s.s)));
			}
			if(vis[cur.s.f-1][cur.s.s][!cur.f.s]==false){
				vis[cur.s.f-1][cur.s.s][!cur.f.s]==true;
				q.push(mp(mp(cur.f.f+1,!cur.f.s),mp(cur.s.f-1,cur.s.s)));
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    bfs();
    cout<<ans<<"\n";
    return 0;
}
/* REMINDERS
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
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

