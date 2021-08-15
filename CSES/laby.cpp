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
const int MAXN = 1e3+1;
//store test cases here
/*


*/
int n,m;
char path[MAXN][MAXN];
char grid[MAXN][MAXN];
void bfs(pii start){
	queue<pii> q;
	q.push(start);
	while(!q.empty()){
		pii curr=q.front();
		q.pop();
		if(curr.s+1<m && path[curr.f][curr.s+1]=='F'&&(grid[curr.f][curr.s+1]=='B'
			||grid[curr.f][curr.s+1]=='.')) {
			path[curr.f][curr.s+1]='R';
			q.push(mp(curr.f,curr.s+1));
		}
		if(curr.s-1>-1 && path[curr.f][curr.s-1]=='F'
			&&(grid[curr.f][curr.s-1]=='B'
			||grid[curr.f][curr.s-1]=='.')) {
			path[curr.f][curr.s-1]='L';
			q.push(mp(curr.f,curr.s-1));
		}
		if(curr.f+1<n && path[curr.f+1][curr.s]=='F'
			&&(grid[curr.f+1][curr.s]=='B'
			||grid[curr.f+1][curr.s]=='.')) {
			path[curr.f+1][curr.s]='D';
			q.push(mp(curr.f+1,curr.s));
		}
		if(curr.f-1>-1 && path[curr.f-1][curr.s]=='F'
			&&(grid[curr.f-1][curr.s]=='B'
			||grid[curr.f-1][curr.s]=='.')) {
			path[curr.f-1][curr.s]='U';
			q.push(mp(curr.f-1,curr.s));
		}
	}

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    pii start;
    pii end;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>grid[i][j];
    		if(grid[i][j]=='A'){
    			start.f=i;
    			start.s=j;
    		}else if(grid[i][j]=='B'){
				end.f=i;
    			end.s=j;
    		}
    		path[i][j]='F';
    	}
    }
    path[start.f][start.s]='Y';
    bfs(start);
    if(path[end.f][end.s]!='F'){
    	vector<char> p;
    	cout<<"YES"<<"\n";
    	while(path[end.f][end.s]!='Y'){
    		p.pb(path[end.f][end.s]);
    		if(path[end.f][end.s]=='R') {
    			end.s--;
    		} else if(path[end.f][end.s]=='L') {
    			end.s++;
    		}else if(path[end.f][end.s]=='D'){
    			end.f--;
    		}else {
    			end.f++;
    		}
    	}
    	cout<<p.size()<<"\n";
    	for(int i=p.size()-1;i>-1;i--){
    		cout<<p[i];
    	}
    	cout<<"\n";
    } else {
    	cout<<"NO"<<"\n";
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

