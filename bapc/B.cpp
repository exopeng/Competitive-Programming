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
#define ll long long
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
int n,m;
int tr,tc;
int g[501][501];
int gc[501][501];
int ct[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int> ps;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>tr>>tc;
    tr--,tc--;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>g[i][j];
    		gc[i][j]=1;
    	}
    }
    vector<int> p;
    int v1=g[tr][tc];
    for (long long d = 2; d * d <= v1; d++) {
    	bool g=true;
        while (v1 % d == 0) {
        	if(g){
            	p.pb(d);
        	}
        	g=false;
            v1 /= d;
        }
    }
    if(v1!=1){
    	p.pb(v1);
    }
	gc[tr][tc]=g[tr][tc];
	ct[tr][tc]=p.size();
	for(int i=0;i<p.size();i++){
		priority_queue<pair<int,pii>> q;
	    q.push(mp(g[tr][tc],mp(tr,tc)));
	    while(!q.empty()){
	    	pair<int,pii> cu=q.top();
	    	q.pop();
	    	for(int j=0;j<4;j++){
	    		int nx=cu.s.f+dx[j];
	    		int ny=cu.s.s+dy[j];
	    		if(nx>-1&&nx<n&&ny>-1&&ny<m&&g[cu.s.f][cu.s.s]>g[nx][ny]&&
	    			g[nx][ny]%p[i]==0&&(gc[nx][ny]%p[i])!=0){
	    			ct[nx][ny]++;
	    			gc[nx][ny]*=p[i];
	    			q.push(mp(g[nx][ny],mp(nx,ny)));
	    		}
	    	}
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ct[i][j]<<" ";
		}
		cout<<"\n";
	}
    
    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS, WRITE BRUTE FORCE SOL ALWAYS(OI)
 * STORE INFO IN VECTORS, NOT STRINGS!!!!!!!!!
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * IF ALL ELSE FAILS, DO CASEWORK
 */

